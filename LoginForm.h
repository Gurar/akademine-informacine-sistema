#pragma once
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
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	private:
		Authentication* authService;
		IUserRepository* userRepository;
		IRoleRepository* roleRepository;
		ISubjectRepository* subjectRepository;
		ICreditRepository* creditRepository;
		IGroupRepository* groupRepository;
		ITeacherRepository* teacherRepository;
		IGradeRepository* gradeRepository;
	public:
		LoginForm(
			Authentication* auth, 
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
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ LoginSubTitle;
	private: System::Windows::Forms::TextBox^ UsernameTextBox;
	private: System::Windows::Forms::TextBox^ PasswordTextBox;
	private: System::Windows::Forms::Label^ UsernameLabel;
	private: System::Windows::Forms::Label^ PasswordLabel;
	private: System::Windows::Forms::Button^ LoginButton;
	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->LoginSubTitle = (gcnew System::Windows::Forms::Label());
			this->UsernameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->PasswordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->UsernameLabel = (gcnew System::Windows::Forms::Label());
			this->PasswordLabel = (gcnew System::Windows::Forms::Label());
			this->LoginButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(230, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(288, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Akademinės informacijos sistema";
			// 
			// LoginSubTitle
			// 
			this->LoginSubTitle->AutoSize = true;
			this->LoginSubTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LoginSubTitle->Location = System::Drawing::Point(322, 215);
			this->LoginSubTitle->Name = L"LoginSubTitle";
			this->LoginSubTitle->Size = System::Drawing::Size(101, 20);
			this->LoginSubTitle->TabIndex = 1;
			this->LoginSubTitle->Text = L"Prisijungimas";
			// 
			// UsernameTextBox
			// 
			this->UsernameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UsernameTextBox->Location = System::Drawing::Point(337, 295);
			this->UsernameTextBox->Name = L"UsernameTextBox";
			this->UsernameTextBox->Size = System::Drawing::Size(213, 26);
			this->UsernameTextBox->TabIndex = 4;
			// 
			// PasswordTextBox
			// 
			this->PasswordTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PasswordTextBox->Location = System::Drawing::Point(337, 339);
			this->PasswordTextBox->Name = L"PasswordTextBox";
			this->PasswordTextBox->Size = System::Drawing::Size(213, 26);
			this->PasswordTextBox->TabIndex = 5;
			// 
			// UsernameLabel
			// 
			this->UsernameLabel->AutoSize = true;
			this->UsernameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UsernameLabel->Location = System::Drawing::Point(183, 298);
			this->UsernameLabel->Name = L"UsernameLabel";
			this->UsernameLabel->Size = System::Drawing::Size(125, 20);
			this->UsernameLabel->TabIndex = 6;
			this->UsernameLabel->Text = L"Vartotojo vardas";
			// 
			// PasswordLabel
			// 
			this->PasswordLabel->AutoSize = true;
			this->PasswordLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PasswordLabel->Location = System::Drawing::Point(183, 342);
			this->PasswordLabel->Name = L"PasswordLabel";
			this->PasswordLabel->Size = System::Drawing::Size(92, 20);
			this->PasswordLabel->TabIndex = 7;
			this->PasswordLabel->Text = L"Slaptažodis";
			// 
			// LoginButton
			// 
			this->LoginButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->LoginButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LoginButton->Location = System::Drawing::Point(264, 456);
			this->LoginButton->Name = L"LoginButton";
			this->LoginButton->Size = System::Drawing::Size(236, 38);
			this->LoginButton->TabIndex = 8;
			this->LoginButton->Text = L"Prisijungti";
			this->LoginButton->UseVisualStyleBackColor = true;
			this->LoginButton->Click += gcnew System::EventHandler(this, &LoginForm::LoginButton_Click);
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 761);
			this->Controls->Add(this->LoginButton);
			this->Controls->Add(this->PasswordLabel);
			this->Controls->Add(this->UsernameLabel);
			this->Controls->Add(this->PasswordTextBox);
			this->Controls->Add(this->UsernameTextBox);
			this->Controls->Add(this->LoginSubTitle);
			this->Controls->Add(this->label1);
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LoginForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void LoginButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
