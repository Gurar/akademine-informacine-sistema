#include <msclr/marshal_cppstd.h>
#include "GroupsPage.h"
#include "AddGroupForm.h"
#include "EditGroupForm.h"
using namespace AIS;

GroupsPage::GroupsPage(IGroupRepository* groupRepository)
{
	InitializeComponent();
	//
	//TODO: Add the constructor code here
	//
	this->groupRepository = groupRepository;

	GroupGrid->Columns->Add("Id", "ID");
	GroupGrid->Columns->Add("Name", "Grupe");
}

System::Void GroupsPage::GroupsPage_Load(System::Object^ sender, System::EventArgs^ e)
{
	LoadAllGroups();
}

System::Void GroupsPage::GroupsPage_Click(System::Object^ sender, System::EventArgs^ e)
{
	GroupGrid->ClearSelection();
	GroupGrid->CurrentCell = nullptr;
}

System::Void GroupsPage::GroupAddButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	AddGroupForm^ form = gcnew AddGroupForm(groupRepository);

	if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		LoadAllGroups();
	}

}
System::Void GroupsPage::GroupUpdateButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (GroupGrid->SelectedRows->Count == 0)
	{
		MessageBox::Show("Pasirinkite Grupie");
		return;
	}

	DataGridViewRow^ row = GroupGrid->SelectedRows[0];

	int id = Convert::ToInt32(row->Cells["Id"]->Value);
	String^ name = row->Cells["Name"]->Value->ToString();
	std::string name2 = msclr::interop::marshal_as<std::string>(name);

	Group* selectedGroup = new Group(id, name2);

	EditGroupForm^ form = gcnew EditGroupForm(groupRepository, selectedGroup);

	if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		LoadAllGroups();
	}
}
System::Void GroupsPage::GroupDeleteButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (GroupGrid->SelectedRows->Count == 0)
	{
		MessageBox::Show("Pasirinkite Naudotoja");
		return;
	}


	DataGridViewRow^ row = GroupGrid->SelectedRows[0];
	int id = Convert::ToInt32(row->Cells["Id"]->Value);

	
	if (groupRepository->hasStudents(id))
	{
		MessageBox::Show("Grupe negali buti istrinta, nes joje dar yra studentu!");
		return;
	}

	
	if (groupRepository->hasSubjects(id))
	{
		MessageBox::Show("Grupe negali būti istrinta, nes jai priskirti dalykai!");
		return;
	}


	if (MessageBox::Show("Ar tikrai norite pasalinti?",
		"Patvirtinimas", MessageBoxButtons::YesNo) == DialogResult::No)
	{
		return;
	}

	groupRepository->remove(id);

	LoadAllGroups();

	MessageBox::Show("Grupe buvo sekmingai istrinta.");

}

System::Void GroupsPage::LoadAllGroups()
{
	auto groups = groupRepository->getAll();

	GroupGrid->Rows->Clear();

	for (auto group : groups) {
		GroupGrid->Rows->Add(
			group->id,
			gcnew String(group->name.c_str())
		);
	}

	GroupGrid->ClearSelection();
	GroupGrid->CurrentCell = nullptr;
}
