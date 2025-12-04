#include <msclr/marshal_cppstd.h>
#include "EditUserForm.h"
using namespace AIS;

EditUserForm::EditUserForm(IUserRepository* userRepository, IRoleRepository* roleRepository, User* user)
{
	InitializeComponent();
	//
	//TODO: Add the constructor code here
	//
	this->userRepository = userRepository;
	this->roleRepository = roleRepository;
	this->selectedUser = user;
	roles = new std::vector<Role*>();

	this->Load += gcnew EventHandler(this, &EditUserForm::EditUserForm_Load);
};

System::Void EditUserForm::EditUserForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	UserNameBox->Text = gcnew String(selectedUser->firstName.c_str());
	UserSurnameBox->Text = gcnew String(selectedUser->lastName.c_str());

	*roles = roleRepository->getAllRoles();

	RoleComboBox->Items->Clear();

	int selectedIndex = -1;

	for (int i = 0; i < roles->size(); i++)
	{
		Role* role = (*roles)[i];

		RoleComboBox->Items->Add(gcnew String(role->name.c_str()));

		if (role->name == selectedUser->role)
		{
			selectedIndex = i;
		}
	}

	RoleComboBox->SelectedIndex = selectedIndex;
}

System::Void EditUserForm::EditUserButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	using msclr::interop::marshal_as;

	selectedUser->firstName = marshal_as<std::string>(UserNameBox->Text);

	selectedUser->lastName = marshal_as<std::string>(UserSurnameBox->Text);

	int index = RoleComboBox->SelectedIndex;

	if (index >= 0)
	{
		Role* selectedRole = (*roles)[index];
		selectedUser->role = selectedRole->name;

		// update DB
		userRepository->assignRole(selectedUser->id, selectedRole->id);
	}

	userRepository->update(selectedUser);

	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();


}
System::Void EditUserForm::CloseModal_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

