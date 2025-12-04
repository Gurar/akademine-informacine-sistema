#pragma once
#include "Admin.h"
#include "IUserRepository.h"
#include "IRoleRepository.h"
#include "ISubjectRepository.h"
#include "ICreditRepository.h"
#include "IGroupRepository.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace AIS {

	/// <summary>
	/// Summary for AdminPage
	/// </summary>
	public ref class AdminPage : public System::Windows::Forms::UserControl
	{
	private:
		Admin* adminUser;
		IUserRepository* userRepository;
		ISubjectRepository* subjectRepository;
		ICreditRepository* creditRepository;
		IRoleRepository* roleRepository;
		IGroupRepository* groupRepository;

	private: System::Windows::Forms::Panel^ AdminRightPanel;
	private: System::Windows::Forms::Button^ AdminUsersButton;
	private: System::Windows::Forms::Button^ AdminSubjectsButton;
	private: System::Windows::Forms::Button^ AdminAssignButton;


	private: System::Windows::Forms::Button^ AdminGroupsButton;
	private: System::Windows::Forms::Panel^ MeniuLeftPanel;
		   
	public:
		AdminPage(
			Admin* user, 
			IUserRepository* userRepository, 
			IRoleRepository* roleRepository,
			ISubjectRepository* subjectRepository,
			ICreditRepository* creditRepository,
			IGroupRepository* groupRepository
		);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminPage()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->AdminRightPanel = (gcnew System::Windows::Forms::Panel());
			this->AdminUsersButton = (gcnew System::Windows::Forms::Button());
			this->AdminSubjectsButton = (gcnew System::Windows::Forms::Button());
			this->MeniuLeftPanel = (gcnew System::Windows::Forms::Panel());
			this->AdminAssignButton = (gcnew System::Windows::Forms::Button());
			this->AdminGroupsButton = (gcnew System::Windows::Forms::Button());
			this->MeniuLeftPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// AdminRightPanel
			// 
			this->AdminRightPanel->AutoSize = true;
			this->AdminRightPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->AdminRightPanel->Location = System::Drawing::Point(182, 0);
			this->AdminRightPanel->Name = L"AdminRightPanel";
			this->AdminRightPanel->Size = System::Drawing::Size(1202, 581);
			this->AdminRightPanel->TabIndex = 2;
			// 
			// AdminUsersButton
			// 
			this->AdminUsersButton->Location = System::Drawing::Point(54, 15);
			this->AdminUsersButton->Name = L"AdminUsersButton";
			this->AdminUsersButton->Size = System::Drawing::Size(75, 23);
			this->AdminUsersButton->TabIndex = 3;
			this->AdminUsersButton->Text = L"Naudotojai";
			this->AdminUsersButton->UseVisualStyleBackColor = true;
			this->AdminUsersButton->Click += gcnew System::EventHandler(this, &AdminPage::AdminUsersButton_Click);
			// 
			// AdminSubjectsButton
			// 
			this->AdminSubjectsButton->Location = System::Drawing::Point(54, 59);
			this->AdminSubjectsButton->Name = L"AdminSubjectsButton";
			this->AdminSubjectsButton->Size = System::Drawing::Size(75, 23);
			this->AdminSubjectsButton->TabIndex = 4;
			this->AdminSubjectsButton->Text = L"Dalykai";
			this->AdminSubjectsButton->UseVisualStyleBackColor = true;
			this->AdminSubjectsButton->Click += gcnew System::EventHandler(this, &AdminPage::AdminSubjectsButton_Click);
			// 
			// MeniuLeftPanel
			// 
			this->MeniuLeftPanel->Controls->Add(this->AdminAssignButton);
			this->MeniuLeftPanel->Controls->Add(this->AdminGroupsButton);
			this->MeniuLeftPanel->Controls->Add(this->AdminSubjectsButton);
			this->MeniuLeftPanel->Controls->Add(this->AdminUsersButton);
			this->MeniuLeftPanel->Dock = System::Windows::Forms::DockStyle::Left;
			this->MeniuLeftPanel->Location = System::Drawing::Point(0, 0);
			this->MeniuLeftPanel->Name = L"MeniuLeftPanel";
			this->MeniuLeftPanel->Size = System::Drawing::Size(182, 581);
			this->MeniuLeftPanel->TabIndex = 1;
			// 
			// AdminAssignButton
			// 
			this->AdminAssignButton->Location = System::Drawing::Point(54, 162);
			this->AdminAssignButton->Name = L"AdminAssignButton";
			this->AdminAssignButton->Size = System::Drawing::Size(75, 23);
			this->AdminAssignButton->TabIndex = 6;
			this->AdminAssignButton->Text = L"Priskirimai";
			this->AdminAssignButton->UseVisualStyleBackColor = true;
			this->AdminAssignButton->Click += gcnew System::EventHandler(this, &AdminPage::AdminAssignButton_Click);
			// 
			// AdminGroupsButton
			// 
			this->AdminGroupsButton->Location = System::Drawing::Point(54, 107);
			this->AdminGroupsButton->Name = L"AdminGroupsButton";
			this->AdminGroupsButton->Size = System::Drawing::Size(75, 23);
			this->AdminGroupsButton->TabIndex = 5;
			this->AdminGroupsButton->Text = L"Grupes";
			this->AdminGroupsButton->UseVisualStyleBackColor = true;
			this->AdminGroupsButton->Click += gcnew System::EventHandler(this, &AdminPage::AdminGroupsButton_Click);
			// 
			// AdminPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->AdminRightPanel);
			this->Controls->Add(this->MeniuLeftPanel);
			this->Name = L"AdminPage";
			this->Size = System::Drawing::Size(1384, 581);
			this->MeniuLeftPanel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void AdminPage::LoadPage(UserControl^ page);
		System::Void AdminUsersButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void AdminSubjectsButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void AdminGroupsButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void AdminAssignButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
