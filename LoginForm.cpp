#include "LoginForm.h"
#include "DashboardForm.h"
#include "User.h"
#include <msclr/marshal_cppstd.h>
using namespace AIS;

LoginForm::LoginForm(
	Authentication* auth, 
	IUserRepository* userRepository, 
	IRoleRepository* roleRepository, 
	ISubjectRepository* subjectRepository, 
	ICreditRepository* creditRepository,
	IGroupRepository* groupRepository,
	ITeacherRepository* teacherRepository,
	IGradeRepository* gradeRepository
)
{
	InitializeComponent();
	//
	//TODO: Add the constructor code here
	//
	this->authService = auth;
	this->userRepository = userRepository;
	this->roleRepository = roleRepository;
	this->subjectRepository = subjectRepository;
	this->creditRepository = creditRepository;
	this->groupRepository = groupRepository;
	this->teacherRepository = teacherRepository;
	this->gradeRepository = gradeRepository;
}

System::Void LoginForm::LoginButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string username = msclr::interop::marshal_as<std::string>(UsernameTextBox->Text);
	std::string password = msclr::interop::marshal_as<std::string>(PasswordTextBox->Text);

	User* user = authService->Login(username, password);

	if (!user) {
		MessageBox::Show("Netaisingas vartotojo vardas ar slaptazodis");
		return;
	}


	DashboardForm^ form = gcnew DashboardForm(this, user, authService, userRepository,roleRepository, subjectRepository, creditRepository, groupRepository, teacherRepository, gradeRepository);
	form->Show();
	this->Hide();
}
