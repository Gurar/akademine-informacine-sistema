#include "AdminPage.h"
#include "UsersPage.h"
#include "SubjectPage.h"
#include "GroupsPage.h"
#include "AssignsPage.h"
using namespace AIS;

AdminPage::AdminPage(
	Admin* user, 
	IUserRepository* userRepository, 
	IRoleRepository* roleRepository, 
	ISubjectRepository* subjectRepository,
	ICreditRepository* creditRepository,
	IGroupRepository* groupRepository
)

{
	InitializeComponent();
	//
	//TODO: Add the constructor code here
	//

	this->adminUser = user;
	this->userRepository = userRepository;
	this->roleRepository = roleRepository;
	this->subjectRepository = subjectRepository;
	this->creditRepository = creditRepository;
	this->groupRepository = groupRepository;

	LoadPage(gcnew UsersPage(userRepository, roleRepository));
}

System::Void AdminPage::LoadPage(UserControl^ page)
{
	this->AdminRightPanel->Controls->Clear();

	page->Dock = DockStyle::Fill;

	this->AdminRightPanel->Controls->Add(page);
}

System::Void AdminPage::AdminUsersButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	LoadPage(gcnew UsersPage(userRepository, roleRepository));
}

System::Void AdminPage::AdminSubjectsButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	LoadPage(gcnew SubjectPage(subjectRepository, creditRepository));
}

System::Void AdminPage::AdminGroupsButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	LoadPage(gcnew GroupsPage(groupRepository));
}

System::Void AdminPage::AdminAssignButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	LoadPage(gcnew AssignsPage(userRepository,subjectRepository, groupRepository));
}