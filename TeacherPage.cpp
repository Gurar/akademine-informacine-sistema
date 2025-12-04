#include <msclr/marshal_cppstd.h>
#include "TeacherPage.h"
using namespace AIS;

TeacherPage::TeacherPage(Teacher* user, ITeacherRepository* teacherRepository, IGroupRepository* groupRepository, IGradeRepository* gradeRepository)
{
	InitializeComponent();
	//
	//TODO: Add the constructor code here
	//
	this->currentUser = user;
	this->teacherRepository = teacherRepository;
	this->groupRepository = groupRepository;
	this->gradeRepository = gradeRepository;

	SubjectsGrid->Columns->Add("Id", "ID");
	SubjectsGrid->Columns->Add("Name", "Dalykas");
	SubjectsGrid->Columns->Add("Credit", "Kreditai sk.");
	SubjectsGrid->Columns->Add("Group", "Grupe.");

	UsersGrid->Columns->Add("Id", "ID");
	UsersGrid->Columns->Add("FirstName", "Vardas");
	UsersGrid->Columns->Add("LastName", "Pavarde");

	GradeGrid->Columns->Add("Id", "ID");
	GradeGrid->Columns->Add("Number", "Pazimis");
	GradeGrid->Columns->Add("Type", "Tipas");
}

System::Void TeacherPage::TeacherPage_Load(System::Object^ sender, System::EventArgs^ e)
{
	LoadSubjects();
	LoadGradeTypes();
}

System::Void TeacherPage::TeacherPage_Click(System::Object^ sender, System::EventArgs^ e)
{
	SubjectsGrid->ClearSelection();
	SubjectsGrid->CurrentCell = nullptr;

	UsersGrid->ClearSelection();
	UsersGrid->CurrentCell = nullptr;

	GradeGrid->ClearSelection();
	GradeGrid->CurrentCell = nullptr;

}

System::Void TeacherPage::LoadSubjects()
{
	auto subjects = teacherRepository->getTeacherSubjects(currentUser->id);

	SubjectsGrid->Rows->Clear();

	for (auto subject : subjects)
	{
		SubjectsGrid->Rows->Add(
			subject->id,
			gcnew String(subject->name.c_str()),
			subject->creditNumber,
			gcnew String(subject->groupName.c_str())
		);
	}

	SubjectsGrid->ClearSelection();
	SubjectsGrid->CurrentCell = nullptr;
}

System::Void TeacherPage::ShownStudentsButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (SubjectsGrid->CurrentRow == nullptr)
	{
		MessageBox::Show("Pasirinkite dalyka");
		return;
	}

	String^ groupName = SubjectsGrid->CurrentRow->Cells["Group"]->Value->ToString();

	if (String::IsNullOrWhiteSpace(groupName))
	{
		MessageBox::Show("Sis dalykas nepriskirtas jokiai grupei!");
		return;
	}

	std::string groupNameStd = msclr::interop::marshal_as<std::string>(groupName);
	int groupId = groupRepository->getGroupIdByName(groupNameStd);

	auto students = groupRepository->getStudentsInGroup(groupId);

	UsersGrid->Rows->Clear();

	for (auto student : students)
	{
		UsersGrid->Rows->Add(
			student->id,
			gcnew String(student->firstName.c_str()),
			gcnew String(student->lastName.c_str())
		);
	}

	UsersGrid->ClearSelection();
	UsersGrid->CurrentCell = nullptr;
	GradeGrid->Rows->Clear();
	
}

System::Void TeacherPage::ShowGradeButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (SubjectsGrid->CurrentRow == nullptr)
	{
		MessageBox::Show("Pasirinkite dalyka");
		return;
	}


	if (UsersGrid->CurrentRow == nullptr)
	{
		MessageBox::Show("Pasirinkite studenta");
		return;
	}

	int subjectId = Convert::ToInt32(SubjectsGrid->CurrentRow->Cells["Id"]->Value);
	int studentId = Convert::ToInt32(UsersGrid->CurrentRow->Cells["Id"]->Value);

	auto grades = gradeRepository->getGradesForStudent(studentId, subjectId);

	GradeGrid->Rows->Clear();

	for (auto grade : grades)
	{
		GradeGrid->Rows->Add(
			grade->id,
			grade->number,
			gcnew String(grade->type.c_str())
		);
	}

	GradeGrid->ClearSelection();
	GradeGrid->CurrentCell = nullptr;
	LoadGradesForSelectedStudent();
}

System::Void TeacherPage::SaveGrade_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (SubjectsGrid->CurrentRow == nullptr)
	{
		MessageBox::Show("Pasirinkite dalyka!");
		return;
	}

	if (UsersGrid->CurrentRow == nullptr)
	{
		MessageBox::Show("Pasirinkite studenta!");
		return;
	}

	if (GradeTypeSelect->SelectedIndex < 0)
	{
		MessageBox::Show("Pasirinkite pazymio tipa!");
		return;
	}

	String^ text = GradeNumberBox->Text;

	int gradeNumber;
	if (!Int32::TryParse(text, gradeNumber))
	{
		MessageBox::Show("Įveskite tik skaičių!");
		return;
	}

	int number = Convert::ToInt32(GradeNumberBox->Text);
	String^ type = GradeTypeSelect->SelectedItem->ToString();

	int subjectId = Convert::ToInt32(SubjectsGrid->CurrentRow->Cells["Id"]->Value);
	int studentId = Convert::ToInt32(UsersGrid->CurrentRow->Cells["Id"]->Value);

	try
	{
		gradeRepository->addGrade(
			studentId,
			subjectId,
			number,
			msclr::interop::marshal_as<std::string>(type)
		);

		MessageBox::Show("Pazymys issaugotas sekmingai!");
	}
	catch (const std::exception& ex)
	{
		MessageBox::Show(gcnew String(ex.what()), "Klaida");
	}

	LoadGradesForSelectedStudent();
}

System::Void TeacherPage::LoadGradeTypes()
{
	auto types = gradeRepository->getAllGradeTypes();

	GradeTypeSelect->Items->Clear();

	for (auto type : types)
	{
		
		GradeTypeSelect->Items->Add(gcnew String(type->type.c_str()));
	}
}

void TeacherPage::LoadGradesForSelectedStudent()
{
	if (SubjectsGrid->CurrentRow == nullptr || UsersGrid->CurrentRow == nullptr)
		return;

	int subjectId = Convert::ToInt32(SubjectsGrid->CurrentRow->Cells["Id"]->Value);
	int studentId = Convert::ToInt32(UsersGrid->CurrentRow->Cells["Id"]->Value);

	auto grades = gradeRepository->getGradesForStudent(studentId, subjectId);

	GradeGrid->Rows->Clear();

	for (auto g : grades)
	{
		GradeGrid->Rows->Add(
			g->id,
			g->number,
			gcnew String(g->type.c_str())
		);
	}
}
