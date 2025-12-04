#include <msclr/marshal_cppstd.h>
#include "AddGroupForm.h"
using namespace AIS;

AddGroupForm::AddGroupForm(IGroupRepository* groupRepository)
{
	InitializeComponent();
	//
	//TODO: Add the constructor code here
	//

	this->groupRepository = groupRepository;
}

System::Void AddGroupForm::AddGroupForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	
}

System::Void AddGroupForm::AddGroupButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	using msclr::interop::marshal_as;

	std::string name = marshal_as<std::string>(GroupNameBox->Text);

	if (name.size() <= 0)
	{
		MessageBox::Show("Tuscias laukas");
		return;
	}

	Group* group = new Group(0, name);

	groupRepository->add(group);

	MessageBox::Show("Grupe sukurta!");
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}
System::Void AddGroupForm::CloseModal_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}
