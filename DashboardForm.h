#pragma once
#include "User.h"
#include "Authentication.h"
#include "IUserRepository.h"
#include "IRoleRepository.h"
#include "ISubjectRepository.h"
#include "ICreditRepository.h"
#include "IGroupRepository.h"
#include "ITeacherRepository.h"
#include "IGradeRepository.h"

namespace AIS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DashboardForm
	/// </summary>
	public ref class DashboardForm : public System::Windows::Forms::Form
	{
	private:
		User* currentUser;
		Authentication* authService;
		IUserRepository* userRepository;
		IRoleRepository* roleRepository;
		ISubjectRepository* subjectRepository;
		ICreditRepository* creditRepository;
		IGroupRepository* groupRepository;
		ITeacherRepository* teacherRepository;
		IGradeRepository* gradeRepository;
	private: System::Windows::Forms::Button^ Logout;

	private: System::Windows::Forms::Label^ MainHeaderRole;
	private: System::Windows::Forms::Label^ MainHeaderName;
		   Form^ loginForm;
	public:
		DashboardForm(
			Form^ login,
			User* user, Authentication* auth,
			IUserRepository* userRepository,
			IRoleRepository* roleRepository,
			ISubjectRepository* subjectRepository,
			ICreditRepository* creditRepository,
			IGroupRepository* groupRepository,
			ITeacherRepository* teacherRepository,
			IGradeRepository* gradeRepository
		);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DashboardForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ MainHeaderPanel;
	protected:
	private: System::Windows::Forms::Panel^ MainContentPanel;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->MainHeaderPanel = (gcnew System::Windows::Forms::Panel());
			this->Logout = (gcnew System::Windows::Forms::Button());
			this->MainHeaderRole = (gcnew System::Windows::Forms::Label());
			this->MainHeaderName = (gcnew System::Windows::Forms::Label());
			this->MainContentPanel = (gcnew System::Windows::Forms::Panel());
			this->MainHeaderPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// MainHeaderPanel
			// 
			this->MainHeaderPanel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->MainHeaderPanel->Controls->Add(this->Logout);
			this->MainHeaderPanel->Controls->Add(this->MainHeaderRole);
			this->MainHeaderPanel->Controls->Add(this->MainHeaderName);
			this->MainHeaderPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->MainHeaderPanel->Location = System::Drawing::Point(0, 0);
			this->MainHeaderPanel->Name = L"MainHeaderPanel";
			this->MainHeaderPanel->Size = System::Drawing::Size(1384, 100);
			this->MainHeaderPanel->TabIndex = 2;
			// 
			// Logout
			// 
			this->Logout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Logout->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Logout->Location = System::Drawing::Point(1239, 18);
			this->Logout->Name = L"Logout";
			this->Logout->Size = System::Drawing::Size(133, 29);
			this->Logout->TabIndex = 3;
			this->Logout->Text = L"Atsijungti";
			this->Logout->UseVisualStyleBackColor = true;
			this->Logout->Click += gcnew System::EventHandler(this, &DashboardForm::Logout_Click);
			// 
			// MainHeaderRole
			// 
			this->MainHeaderRole->AutoSize = true;
			this->MainHeaderRole->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MainHeaderRole->Location = System::Drawing::Point(26, 51);
			this->MainHeaderRole->Name = L"MainHeaderRole";
			this->MainHeaderRole->Size = System::Drawing::Size(36, 16);
			this->MainHeaderRole->TabIndex = 1;
			this->MainHeaderRole->Text = L"Role";
			// 
			// MainHeaderName
			// 
			this->MainHeaderName->AutoSize = true;
			this->MainHeaderName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MainHeaderName->Location = System::Drawing::Point(25, 18);
			this->MainHeaderName->Name = L"MainHeaderName";
			this->MainHeaderName->Size = System::Drawing::Size(69, 24);
			this->MainHeaderName->TabIndex = 2;
			this->MainHeaderName->Text = L"Vardas";
			// 
			// MainContentPanel
			// 
			this->MainContentPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->MainContentPanel->Location = System::Drawing::Point(0, 100);
			this->MainContentPanel->Name = L"MainContentPanel";
			this->MainContentPanel->Size = System::Drawing::Size(1384, 581);
			this->MainContentPanel->TabIndex = 3;
			// 
			// DashboardForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1384, 681);
			this->Controls->Add(this->MainContentPanel);
			this->Controls->Add(this->MainHeaderPanel);
			this->Name = L"DashboardForm";
			this->Text = L"DashboardForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->MainHeaderPanel->ResumeLayout(false);
			this->MainHeaderPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		System::Void LoadPage(UserControl^ page);
		System::Void LoadRolePage();
		System::Void Logout_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void LoadUserInfo();

};
}
