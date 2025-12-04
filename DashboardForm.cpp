#include "DashboardForm.h"
#include "AdminPage.h"
#include "TeacherPage.h"
#include "StudentPage.h"

using namespace AIS;

DashboardForm::DashboardForm(
    Form^ login, 
    User* user, 
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
    loginForm = login;
	this->currentUser = user;
	this->authService = auth;
	this->userRepository = userRepository;
	this->roleRepository = roleRepository;
    this->subjectRepository = subjectRepository;
    this->creditRepository = creditRepository;
    this->groupRepository = groupRepository;
    this->teacherRepository = teacherRepository;
    this->gradeRepository = gradeRepository;
    
    LoadUserInfo();
    LoadRolePage();
}

System::Void DashboardForm::LoadPage(UserControl^ page)
{
    this->MainContentPanel->Controls->Clear();

    page->Dock = DockStyle::Fill;

    this->MainContentPanel->Controls->Add(page);
}

System::Void DashboardForm::LoadRolePage()
{
    if (Admin* admin = dynamic_cast<Admin*>(currentUser))
    {
        AdminPage^ page = gcnew AdminPage(admin, userRepository, roleRepository, subjectRepository, creditRepository, groupRepository);
        LoadPage(page);
        return;
    }

    if (Teacher* teacher = dynamic_cast<Teacher*>(currentUser))
    {
        TeacherPage^ page = gcnew TeacherPage(teacher, teacherRepository, groupRepository, gradeRepository);
        LoadPage(page);
        return;
    }

    if (Student* student = dynamic_cast<Student*>(currentUser))
    {
       StudentPage^ page = gcnew StudentPage(student, groupRepository, gradeRepository);
        LoadPage(page);
        return;
    }

}

System::Void DashboardForm::LoadUserInfo()
{
    std::string fullName = currentUser->firstName + " " + currentUser->lastName;

    MainHeaderName->Text = gcnew String(fullName.c_str());
    MainHeaderRole->Text = gcnew String(currentUser->role.c_str());
}

System::Void DashboardForm::Logout_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
    loginForm->Show();
}
