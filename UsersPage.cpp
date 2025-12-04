#include <msclr/marshal_cppstd.h>
#include "UsersPage.h"
#include "AddUserForm.h"
#include "EditUserForm.h"

using namespace AIS;

UsersPage::UsersPage(IUserRepository* userRepository, IRoleRepository* roleRepository)
{
	InitializeComponent();
	//
	//TODO: Add the constructor code here
	//
	this->userRepository = userRepository;
	this->roleRepository = roleRepository;

	UsersGrid->Columns->Add("Id", "ID");
	UsersGrid->Columns->Add("FirstName", "Vardas");
	UsersGrid->Columns->Add("LastName", "Pavarde");
	UsersGrid->Columns->Add("Role", "Role");
}

System::Void UsersPage::UsersPage_Load(System::Object^ sender, System::EventArgs^ e)
{
	LoadAllUsers();
}

System::Void UsersPage::UsersPage_Click(System::Object^ sender, System::EventArgs^ e)
{
	UsersGrid->ClearSelection();
	UsersGrid->CurrentCell = nullptr;
}

System::Void UsersPage::LoadAllUsers()
{
	auto users = userRepository->getAll();

	UsersGrid->Rows->Clear();

	for (auto user : users) {
		UsersGrid->Rows->Add(
			user->id,
			gcnew String(user->firstName.c_str()),
			gcnew String(user->lastName.c_str()),
			gcnew String(user->role.c_str())
		);
	}

	UsersGrid->ClearSelection();
	UsersGrid->CurrentCell = nullptr;
}

System::Void UsersPage::UserAddButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	AddUserForm^ form = gcnew AddUserForm(userRepository, roleRepository);
	if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		LoadAllUsers();   // refresh table after insert
	}
}

System::Void UsersPage::UserUpdateButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (UsersGrid->SelectedRows->Count == 0)
	{
		MessageBox::Show("Pasirinkite Naudotoja");
		return;
	}

	DataGridViewRow^ row = UsersGrid->SelectedRows[0];

	int id = Convert::ToInt32(row->Cells["Id"]->Value);
	String^ firstName = row->Cells["FirstName"]->Value->ToString();
	String^ lastName = row->Cells["LastName"]->Value->ToString();

	std::string first = msclr::interop::marshal_as<std::string>(firstName);
	std::string last = msclr::interop::marshal_as<std::string>(lastName);

	std::string userRole = userRepository->getRole(id);

	User* selectedUser = new User(id, first, last, "");

	selectedUser->role = userRole;

	selectedUser->role = userRepository->getRole(id);

	EditUserForm^ form = gcnew EditUserForm(userRepository, roleRepository, selectedUser);
	if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		LoadAllUsers();
	}
}

System::Void UsersPage::UserDeleteButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (UsersGrid->SelectedRows->Count == 0)
	{
		MessageBox::Show("Pasirinkite Naudotoja");
		return;
	}

	DataGridViewRow^ row = UsersGrid->SelectedRows[0];
	int id = Convert::ToInt32(row->Cells["Id"]->Value);
	String^ role = row->Cells["Role"]->Value->ToString();

	if (role == "student" && userRepository->isStudentInAnyGroup(id))
	{
		MessageBox::Show("Studentas negali būti ištrintas, nes jis priskirtas grupei!");
		return;
	}

	if (role == "teacher" && userRepository->isTeacherAssignedToAnySubject(id))
	{
		MessageBox::Show("Dėstytojas negali būti ištrintas, nes jis priskirtas dalykui!");
		return;
	}

	if (MessageBox::Show("Ar tikrai norite pasalinti?",
		"Patvirtinimas", MessageBoxButtons::YesNo) == DialogResult::No)
	{
		return;
	}

	userRepository->remove(id);

	LoadAllUsers();

	MessageBox::Show("Naudotojas sekmingai istrinta.");

}
