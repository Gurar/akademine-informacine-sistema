#include <msclr/marshal_cppstd.h>
#include "AssignsPage.h"
using namespace AIS;

AssignsPage::AssignsPage(IUserRepository* userRepository, ISubjectRepository* subjectRepository, IGroupRepository* groupRepository)
{
	InitializeComponent();
	//
	//TODO: Add the constructor code here
	//

	this->subjectRepository = subjectRepository;
	this->groupRepository = groupRepository;
	this->userRepository = userRepository;

	UsersGrid->Columns->Add("Id", "ID");
	UsersGrid->Columns->Add("FirstName", "Vardas");
	UsersGrid->Columns->Add("LastName", "Pavarde");
	UsersGrid->Columns->Add("Role", "Role");
	UsersGrid->Columns->Add("Group", "Grupie");

	SubjectsGrid->Columns->Add("Id", "ID");
	SubjectsGrid->Columns->Add("Name", "Dalykas");
	SubjectsGrid->Columns->Add("Credit", "Kreditu sk.");
	SubjectsGrid->Columns->Add("Teacher", "Destitojas");
	SubjectsGrid->Columns->Add("Group", "Grupe");
}

System::Void AssignsPage::AssignsPage_Load(System::Object^ sender, System::EventArgs^ e)
{
	LoadUsers();
	LoadSubjects();
	LoadGroups();
}
System::Void AssignsPage::AssignsPage_Click(System::Object^ sender, System::EventArgs^ e)
{
	UsersGrid->ClearSelection();
	UsersGrid->CurrentCell = nullptr;

	SubjectsGrid->ClearSelection();
	SubjectsGrid->CurrentCell = nullptr;
}
System::Void AssignsPage::StudentAssign_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (GroupsComboBox->SelectedIndex < 0)
	{
		MessageBox::Show("Pasirinkite Grupę");
		return;
	}

	if (UsersGrid->CurrentRow == nullptr)
	{
		MessageBox::Show("Pasirinkite Studenta");
		return;
	}

	String^ role = UsersGrid->CurrentRow->Cells["Role"]->Value->ToString();
	if (role != "student")
	{
		MessageBox::Show("Tik studentą galima priskirti grupei!");
		return;
	}


	int studentId = Convert::ToInt32(UsersGrid->CurrentRow->Cells["Id"]->Value);

	String^ groupName = GroupsComboBox->SelectedItem->ToString();
	std::string group = msclr::interop::marshal_as<std::string>(groupName);

	int groupId = groupRepository->getGroupIdByName(group);

	try
	{
		groupRepository->assignStudentToGroup(studentId, groupId);
		MessageBox::Show("Studentas priskirtas grupei sėkmingai!");
	}
	catch (const std::exception& ex)
	{
		MessageBox::Show(gcnew String(ex.what()), "Klaida");
	}

	LoadUsers();
}
System::Void AssignsPage::SubjectAssign_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (GroupsComboBox->SelectedIndex < 0)
	{
		MessageBox::Show("Pasirinkite Grupę");
		return;
	}


	if (SubjectsGrid->CurrentRow == nullptr)
	{
		MessageBox::Show("Pasirinkite Dalyka");
		return;
	}

	int subjectId = Convert::ToInt32(SubjectsGrid->CurrentRow->Cells["Id"]->Value);

	String^ groupName = GroupsComboBox->SelectedItem->ToString();
	std::string group = msclr::interop::marshal_as<std::string>(groupName);

	int groupId = groupRepository->getGroupIdByName(group);

	try
	{
		groupRepository->assignSubjectToGroup(groupId, subjectId);
		MessageBox::Show("Dalikas sekmingai priskirtas grupei");
	}
	catch (const std::exception& ex)
	{
		MessageBox::Show(gcnew String(ex.what()), "Klaida");
	}

	LoadSubjects();
}
System::Void AssignsPage::TeacherAssign_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (SubjectsGrid->CurrentRow == nullptr)
	{
		MessageBox::Show("Pasirinkite Dalyka");
		return;
	}

	if (UsersGrid->CurrentRow == nullptr)
	{
		MessageBox::Show("Pasirinkite Studenta");
		return;
	}

	String^ role = UsersGrid->CurrentRow->Cells["Role"]->Value->ToString();
	if (role != "teacher")
	{
		MessageBox::Show("Tik destitoja galima priskirti dalykui!");
		return;
	}

	int subjectId = Convert::ToInt32(SubjectsGrid->CurrentRow->Cells["Id"]->Value);
	int teacherId = Convert::ToInt32(UsersGrid->CurrentRow->Cells["Id"]->Value);

	try
	{
		subjectRepository->assignTeacherToSubject(subjectId, teacherId);
		MessageBox::Show("Dalikas sekmingai priskirtas grupei");
	}
	catch (const std::exception& ex)
	{
		MessageBox::Show(gcnew String(ex.what()), "Klaida");
	}

	LoadSubjects();

}
System::Void AssignsPage::StudentAssignDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
	
	if (GroupsComboBox->SelectedIndex < 0)
	{
		MessageBox::Show("Pasirinkite grupę");
		return;
	}

	
	if (UsersGrid->CurrentRow == nullptr)
	{
		MessageBox::Show("Pasirinkite studentą");
		return;
	}

	String^ role = UsersGrid->CurrentRow->Cells["Role"]->Value->ToString();
	if (role != "student")
	{
		MessageBox::Show("Tik studentus galima nuimti nuo grupės!");
		return;
	}

	
	int userId = Convert::ToInt32(UsersGrid->CurrentRow->Cells["Id"]->Value);

	
	String^ groupName = GroupsComboBox->SelectedItem->ToString();
	std::string group = msclr::interop::marshal_as<std::string>(groupName);
	int groupId = groupRepository->getGroupIdByName(group);


	if (MessageBox::Show("Ar tikrai norite pasalinti studenta iš grupes?",
		"Patvirtinimas", MessageBoxButtons::YesNo) == DialogResult::No)
	{
		return;
	}

	try
	{
		groupRepository->removeStudentFromGroup(userId, groupId);
		MessageBox::Show("Studentas pasalintas is grupes!");
	}
	catch (const std::exception& ex)
	{
		MessageBox::Show(gcnew String(ex.what()), "Klaida");
	}

	LoadUsers();  // optional: refresh UI

}
System::Void AssignsPage::SubjectAssignDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (GroupsComboBox->SelectedIndex < 0)
	{
		MessageBox::Show("Pasirinkite grupe.");
		return;
	}

	if (SubjectsGrid->CurrentRow == nullptr)
	{
		MessageBox::Show("Pasirinkite dalyka.");
		return;
	}

	int subjectId = Convert::ToInt32(SubjectsGrid->CurrentRow->Cells["Id"]->Value);

	
	String^ groupName = GroupsComboBox->SelectedItem->ToString();
	std::string group = msclr::interop::marshal_as<std::string>(groupName);

	int groupId = groupRepository->getGroupIdByName(group);

	
	if (MessageBox::Show("Ar tikrai norite pasalinti priskyrima?",
		"Patvirtinimas", MessageBoxButtons::YesNo) == DialogResult::No)
	{
		return;
	}

	try
	{
		groupRepository->removeSubjectFromGroup(groupId, subjectId);
		MessageBox::Show("Dalykas pasalintas is grupss.");
	}
	catch (const std::exception& ex)
	{
		MessageBox::Show(gcnew String(ex.what()), "Klaida");
	}

	LoadSubjects();
}
System::Void AssignsPage::TeacherAssignDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (UsersGrid->CurrentRow == nullptr)
	{
		MessageBox::Show("Pasirinkite destytoja.");
		return;
	}

	if (SubjectsGrid->CurrentRow == nullptr)
	{
		MessageBox::Show("Pasirinkite dalyka.");
		return;
	}

	String^ role = UsersGrid->CurrentRow->Cells["Role"]->Value->ToString();
	if (role != "teacher")
	{
		MessageBox::Show("Pasirinkite destitoja");
		return;
	}

	int teacherId = Convert::ToInt32(UsersGrid->CurrentRow->Cells["Id"]->Value);
	int subjectId = Convert::ToInt32(SubjectsGrid->CurrentRow->Cells["Id"]->Value);

	// Confirm
	if (MessageBox::Show("Ar tikrai norite nuimti destytoją nuo sio dalyko?",
		"Patvirtinimas", MessageBoxButtons::YesNo) == DialogResult::No)
	{
		return;
	}

	try
	{
		subjectRepository->removeTeacherFromSubject(subjectId, teacherId);
		MessageBox::Show("Detytojas pasalintas nuo dalyko.");
	}
	catch (const std::exception& ex)
	{
		MessageBox::Show(gcnew String(ex.what()), "Klaida");
	}

	LoadSubjects();
}

System::Void AssignsPage::LoadUsers()
{
	auto users = userRepository->getAll();

	UsersGrid->Rows->Clear();

	for (auto user : users) {
		UsersGrid->Rows->Add(
			user->id,
			gcnew String(user->firstName.c_str()),
			gcnew String(user->lastName.c_str()),
			gcnew String(user->role.c_str()),
			gcnew String(user->groupName.c_str())
		);
	}

	UsersGrid->ClearSelection();
	UsersGrid->CurrentCell = nullptr;
}

System::Void AssignsPage::LoadSubjects()
{
	auto subjects = subjectRepository->getAll();


	SubjectsGrid->Rows->Clear();



	for (auto subject : subjects)
	{
		SubjectsGrid->Rows->Add(
			subject->id,
			gcnew String(subject->name.c_str()),
			subject->creditNumber,
			gcnew String(subject->teacherName.c_str()),
			gcnew String(subject->groupName.c_str())
		);
	}

	SubjectsGrid->ClearSelection();
	SubjectsGrid->CurrentCell = nullptr;
}

System::Void AssignsPage::LoadGroups()
{
	auto groups = groupRepository->getAll();

	GroupsComboBox->Items->Clear();

	for (auto group : groups) {
		GroupsComboBox->Items->Add(gcnew String(group->name.c_str()));
	}
}