#include "LoginForm.h"
#include "Database.h"
#include "IUserRepository.h"
#include "IRoleRepository.h"
#include "MySQLUserRepository.h"
#include "MySQLRoleRepository.h"
#include "Authentication.h"
#include "ISubjectRepository.h"
#include "ICreditRepository.h"
#include "MySQLCreditRepository.h"
#include "MySQLSubjectRepository.h"
#include "IGroupRepository.h"
#include "MySQLGroupRepository.h"
#include "ITeacherRepository.h"
#include "MySQLTeacherRepository.h"
#include "IGradeRepository.h"
#include "MySQLGradeRepository.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args)
{
	Database* db = new Database("tcp://127.0.0.1:3306", "root", "", "db_ais");

	IUserRepository* userRepository = new MySQLUserRepository(db);
	IRoleRepository* roleRepository = new MySQLRoleRepository(db);
	ISubjectRepository* subjectRepository = new MySQLSubjectRepository(db);
	ICreditRepository* creditRepository = new MySQLCreditRepository(db);
	IGroupRepository* groupRepository = new MySQLGroupRepository(db);
	ITeacherRepository* teacherRepository = new MySQLTeacherRepository(db);
	IGradeRepository* gradeRepository = new MySQLGradeRepository(db);

	Authentication* auth = new Authentication(userRepository);

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew AIS::LoginForm(
		auth, 
		userRepository, 
		roleRepository, 
		subjectRepository, 
		creditRepository,
		groupRepository,
		teacherRepository,
		gradeRepository
	));
}