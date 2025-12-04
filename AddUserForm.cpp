#include "AddUserForm.h"
#include <msclr/marshal_cppstd.h>
using namespace AIS;

AddUserForm::AddUserForm(IUserRepository* userRepository, IRoleRepository* roleRepository)
{
	InitializeComponent();
	//
	//TODO: Add the constructor code here
	//
	this->userRepository = userRepository;
	this->roleRepository = roleRepository;

	roles = new std::vector<Role*>();

	this->Load += gcnew System::EventHandler(this, &AddUserForm::AddUserForm_Load);
}

System::Void AddUserForm::AddUserButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	using msclr::interop::marshal_as;

	std::string first = marshal_as<std::string>(UserNameBox->Text);
	std::string last = marshal_as<std::string>(UserSurnameBox->Text);

	int selectedIndex = RoleComboBox->SelectedIndex;

	if (first.size() <= 0 || last.size() <= 0)
	{
		MessageBox::Show("Tusti laukai");
		return;
	}

	if (selectedIndex < 0)
	{
		MessageBox::Show("Pasirinkite naudotojo role");
		return;
	}

	User* newUser = new User(0, first, last, "");

	int newUserId = userRepository->add(newUser);
	int roleId = (*roles)[selectedIndex]->id;

	if (newUserId <= 0)
	{
		MessageBox::Show("Error inserting user");
		return;
	}

	userRepository->assignRole(newUserId, roleId);

	MessageBox::Show("Naudotojas idetas");
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}

System::Void AddUserForm::CloseModal_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

System::Void AddUserForm::AddUserForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	*roles = roleRepository->getAllRoles();

	RoleComboBox->Items->Clear();

	for (auto role : *roles)
	{
		RoleComboBox->Items->Add(gcnew String(role->name.c_str()));
	}
}

