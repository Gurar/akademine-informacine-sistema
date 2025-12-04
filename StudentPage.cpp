#include "StudentPage.h"
using namespace AIS;


StudentPage::StudentPage(Student* user, IGroupRepository* groupRepository, IGradeRepository* gradeRepository)
{
	InitializeComponent();
	//
	//TODO: Add the constructor code here
	//

	this->currentUser = user;
	this->groupRepository = groupRepository;
	this->gradeRepository = gradeRepository;

	SubjectsGrid->Columns->Add("Id", "ID");
	SubjectsGrid->Columns->Add("Name", "Dalykas");
	SubjectsGrid->Columns->Add("Credit", "Kreditai sk.");

	GradeGrid->Columns->Add("Id", "ID");
	GradeGrid->Columns->Add("Number", "Pazimis");
	GradeGrid->Columns->Add("Type", "Tipas");
}

System::Void StudentPage::StudentPage_Load(System::Object^ sender, System::EventArgs^ e)
{
	LoadSubjects();
}
System::Void StudentPage::StudentPage_Click(System::Object^ sender, System::EventArgs^ e)
{
	SubjectsGrid->ClearSelection();
	SubjectsGrid->CurrentCell = nullptr;

	GradeGrid->ClearSelection();
	GradeGrid->CurrentCell = nullptr;
}
System::Void StudentPage::ShowGradeButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (SubjectsGrid->CurrentRow == nullptr)
	{
		MessageBox::Show("Pasirinkite dalyka");
		return;
	}

	int subjectId = Convert::ToInt32(SubjectsGrid->CurrentRow->Cells["Id"]->Value);

	auto grades = gradeRepository->getGradesForStudent(currentUser->id, subjectId);

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
}

System::Void StudentPage::LoadSubjects()
{
	auto subjects = groupRepository->getSubjectsForStudent(currentUser->id);

	SubjectsGrid->Rows->Clear();

	for (auto s : subjects)
	{
		SubjectsGrid->Rows->Add(
			s->id,
			gcnew String(s->name.c_str()),
			s->creditNumber,
			gcnew String(s->groupName.c_str())
		);
	}

	SubjectsGrid->ClearSelection();
	SubjectsGrid->CurrentCell = nullptr;
}