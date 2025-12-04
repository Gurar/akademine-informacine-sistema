#include <msclr/marshal_cppstd.h>
#include "EditGroupForm.h"
using namespace AIS;

EditGroupForm::EditGroupForm(IGroupRepository* groupRepository, Group* group)
{
	InitializeComponent();
	//
	//TODO: Add the constructor code here
	//
	this->groupRepository = groupRepository;
	this->selectedGroup = group;
}

System::Void EditGroupForm::EditGroupForm_Load(System::Object^ sender, System::EventArgs^ e)
{
		GroupNameBox->Text = gcnew String(selectedGroup->name.c_str());
}
System::Void EditGroupForm::EditGroupButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	using msclr::interop::marshal_as;

	selectedGroup->name = marshal_as<std::string>(GroupNameBox->Text);

	groupRepository->update(selectedGroup);

	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}
System::Void EditGroupForm::CloseModal_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}
