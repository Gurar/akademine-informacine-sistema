#pragma once
#include "IUserRepository.h"
#include "IRoleRepository.h"

namespace AIS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EditUserForm
	/// </summary>
	public ref class EditUserForm : public System::Windows::Forms::Form
	{
	private:
		IUserRepository* userRepository;
		IRoleRepository* roleRepository;
		std::vector<Role*>* roles;
		User* selectedUser;
	private: System::Windows::Forms::ComboBox^ RoleComboBox;
	public:
		EditUserForm(IUserRepository* userRepository, IRoleRepository* roleRepository, User* user);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EditUserForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ EditUserLabel;
	protected:
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::TextBox^ UserSurnameBox;
	private: System::Windows::Forms::TextBox^ UserNameBox;
	private: System::Windows::Forms::Button^ CloseModal;
	private: System::Windows::Forms::Button^ EditUserButton;

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
			this->EditUserLabel = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->UserSurnameBox = (gcnew System::Windows::Forms::TextBox());
			this->UserNameBox = (gcnew System::Windows::Forms::TextBox());
			this->CloseModal = (gcnew System::Windows::Forms::Button());
			this->EditUserButton = (gcnew System::Windows::Forms::Button());
			this->RoleComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// EditUserLabel
			// 
			this->EditUserLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->EditUserLabel->AutoSize = true;
			this->EditUserLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EditUserLabel->Location = System::Drawing::Point(186, 49);
			this->EditUserLabel->Name = L"EditUserLabel";
			this->EditUserLabel->Size = System::Drawing::Size(166, 20);
			this->EditUserLabel->TabIndex = 1;
			this->EditUserLabel->Text = L"Redaguoti  naudotoja ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(89, 266);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(42, 20);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Role";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(89, 215);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(67, 20);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Pavarde";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(89, 170);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 20);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Vardas";
			// 
			// UserSurnameBox
			// 
			this->UserSurnameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UserSurnameBox->Location = System::Drawing::Point(248, 209);
			this->UserSurnameBox->Name = L"UserSurnameBox";
			this->UserSurnameBox->Size = System::Drawing::Size(184, 26);
			this->UserSurnameBox->TabIndex = 9;
			// 
			// UserNameBox
			// 
			this->UserNameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UserNameBox->Location = System::Drawing::Point(248, 164);
			this->UserNameBox->Name = L"UserNameBox";
			this->UserNameBox->Size = System::Drawing::Size(184, 26);
			this->UserNameBox->TabIndex = 10;
			// 
			// CloseModal
			// 
			this->CloseModal->Location = System::Drawing::Point(283, 393);
			this->CloseModal->Name = L"CloseModal";
			this->CloseModal->Size = System::Drawing::Size(149, 38);
			this->CloseModal->TabIndex = 12;
			this->CloseModal->Text = L"Atsaukti";
			this->CloseModal->UseVisualStyleBackColor = true;
			this->CloseModal->Click += gcnew System::EventHandler(this, &EditUserForm::CloseModal_Click);
			// 
			// EditUserButton
			// 
			this->EditUserButton->Location = System::Drawing::Point(93, 393);
			this->EditUserButton->Name = L"EditUserButton";
			this->EditUserButton->Size = System::Drawing::Size(149, 38);
			this->EditUserButton->TabIndex = 13;
			this->EditUserButton->Text = L"Patvirtinti";
			this->EditUserButton->UseVisualStyleBackColor = true;
			this->EditUserButton->Click += gcnew System::EventHandler(this, &EditUserForm::EditUserButton_Click);
			// 
			// RoleComboBox
			// 
			this->RoleComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RoleComboBox->FormattingEnabled = true;
			this->RoleComboBox->Location = System::Drawing::Point(248, 266);
			this->RoleComboBox->Name = L"RoleComboBox";
			this->RoleComboBox->Size = System::Drawing::Size(184, 28);
			this->RoleComboBox->TabIndex = 14;
			// 
			// EditUserForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 561);
			this->Controls->Add(this->RoleComboBox);
			this->Controls->Add(this->CloseModal);
			this->Controls->Add(this->EditUserButton);
			this->Controls->Add(this->UserSurnameBox);
			this->Controls->Add(this->UserNameBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->EditUserLabel);
			this->Name = L"EditUserForm";
			this->Text = L"EditUserForm";
			this->Load += gcnew System::EventHandler(this, &EditUserForm::EditUserForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void EditUserForm_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void EditUserButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void CloseModal_Click(System::Object^ sender, System::EventArgs^ e);
};
}
