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
	/// Summary for AddUserForm
	/// </summary>
	public ref class AddUserForm : public System::Windows::Forms::Form
	{
	private:
		IUserRepository* userRepository;
		IRoleRepository* roleRepository;
	private: System::Windows::Forms::ComboBox^ RoleComboBox;
		   std::vector<Role*>* roles;
	public:
		AddUserForm(IUserRepository* userRepository, IRoleRepository* roleRepository);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddUserForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ UserSurnameBox;
	private: System::Windows::Forms::TextBox^ UserNameBox;
	private: System::Windows::Forms::Button^ CloseModal;
	private: System::Windows::Forms::Button^ AddUserButton;
	private: System::Windows::Forms::Label^ label1;

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
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->UserSurnameBox = (gcnew System::Windows::Forms::TextBox());
			this->UserNameBox = (gcnew System::Windows::Forms::TextBox());
			this->CloseModal = (gcnew System::Windows::Forms::Button());
			this->AddUserButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->RoleComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(138, 246);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(42, 20);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Role";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(138, 213);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(67, 20);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Pavarde";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(138, 175);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 20);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Vardas";
			// 
			// UserSurnameBox
			// 
			this->UserSurnameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UserSurnameBox->Location = System::Drawing::Point(245, 210);
			this->UserSurnameBox->Name = L"UserSurnameBox";
			this->UserSurnameBox->Size = System::Drawing::Size(219, 26);
			this->UserSurnameBox->TabIndex = 10;
			// 
			// UserNameBox
			// 
			this->UserNameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UserNameBox->Location = System::Drawing::Point(245, 172);
			this->UserNameBox->Name = L"UserNameBox";
			this->UserNameBox->Size = System::Drawing::Size(219, 26);
			this->UserNameBox->TabIndex = 11;
			// 
			// CloseModal
			// 
			this->CloseModal->Location = System::Drawing::Point(329, 424);
			this->CloseModal->Name = L"CloseModal";
			this->CloseModal->Size = System::Drawing::Size(149, 38);
			this->CloseModal->TabIndex = 8;
			this->CloseModal->Text = L"Atsaukti";
			this->CloseModal->UseVisualStyleBackColor = true;
			this->CloseModal->Click += gcnew System::EventHandler(this, &AddUserForm::CloseModal_Click);
			// 
			// AddUserButton
			// 
			this->AddUserButton->Location = System::Drawing::Point(126, 424);
			this->AddUserButton->Name = L"AddUserButton";
			this->AddUserButton->Size = System::Drawing::Size(149, 38);
			this->AddUserButton->TabIndex = 9;
			this->AddUserButton->Text = L"Prideti vartotoja";
			this->AddUserButton->UseVisualStyleBackColor = true;
			this->AddUserButton->Click += gcnew System::EventHandler(this, &AddUserForm::AddUserButton_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(172, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(212, 20);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Pridėti naują vartotojo langas";
			// 
			// RoleComboBox
			// 
			this->RoleComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RoleComboBox->FormattingEnabled = true;
			this->RoleComboBox->Location = System::Drawing::Point(245, 246);
			this->RoleComboBox->Name = L"RoleComboBox";
			this->RoleComboBox->Size = System::Drawing::Size(219, 28);
			this->RoleComboBox->TabIndex = 15;
			// 
			// AddUserForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 561);
			this->Controls->Add(this->RoleComboBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->UserSurnameBox);
			this->Controls->Add(this->UserNameBox);
			this->Controls->Add(this->CloseModal);
			this->Controls->Add(this->AddUserButton);
			this->Controls->Add(this->label1);
			this->Name = L"AddUserForm";
			this->Text = L"AddUserForm";
			this->Load += gcnew System::EventHandler(this, &AddUserForm::AddUserForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void AddUserButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void CloseModal_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void AddUserForm_Load(System::Object^ sender, System::EventArgs^ e);
};
}
