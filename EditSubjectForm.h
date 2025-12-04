#pragma once
#include "ISubjectRepository.h"
#include "ICreditRepository.h"

namespace AIS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EditSubjectForm
	/// </summary>
	public ref class EditSubjectForm : public System::Windows::Forms::Form
	{
	private:
		ISubjectRepository* subjectRepository;
		ICreditRepository* creditRepository;
		std::vector<Credit*>* credits;
		Subject* selectedSubject;
	public:
		EditSubjectForm(ISubjectRepository* subjectRepository, ICreditRepository* creditRepository, Subject* subject);
		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EditSubjectForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ CreditComboBox;
	protected:

	protected:
	private: System::Windows::Forms::Button^ CloseModal;
	private: System::Windows::Forms::Button^ EditSubjectButton;
	private: System::Windows::Forms::TextBox^ SubjectNameBox;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ EditUserLabel;

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
			this->CreditComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->CloseModal = (gcnew System::Windows::Forms::Button());
			this->EditSubjectButton = (gcnew System::Windows::Forms::Button());
			this->SubjectNameBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->EditUserLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// CreditComboBox
			// 
			this->CreditComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CreditComboBox->FormattingEnabled = true;
			this->CreditComboBox->Location = System::Drawing::Point(246, 256);
			this->CreditComboBox->Name = L"CreditComboBox";
			this->CreditComboBox->Size = System::Drawing::Size(184, 28);
			this->CreditComboBox->TabIndex = 23;
			// 
			// CloseModal
			// 
			this->CloseModal->Location = System::Drawing::Point(309, 398);
			this->CloseModal->Name = L"CloseModal";
			this->CloseModal->Size = System::Drawing::Size(149, 38);
			this->CloseModal->TabIndex = 21;
			this->CloseModal->Text = L"Atsaukti";
			this->CloseModal->UseVisualStyleBackColor = true;
			this->CloseModal->Click += gcnew System::EventHandler(this, &EditSubjectForm::CloseModal_Click);
			// 
			// EditSubjectButton
			// 
			this->EditSubjectButton->Location = System::Drawing::Point(101, 398);
			this->EditSubjectButton->Name = L"EditSubjectButton";
			this->EditSubjectButton->Size = System::Drawing::Size(149, 38);
			this->EditSubjectButton->TabIndex = 22;
			this->EditSubjectButton->Text = L"Patvirtinti";
			this->EditSubjectButton->UseVisualStyleBackColor = true;
			this->EditSubjectButton->Click += gcnew System::EventHandler(this, &EditSubjectForm::EditSubjectButton_Click);
			// 
			// SubjectNameBox
			// 
			this->SubjectNameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SubjectNameBox->Location = System::Drawing::Point(246, 205);
			this->SubjectNameBox->Name = L"SubjectNameBox";
			this->SubjectNameBox->Size = System::Drawing::Size(184, 26);
			this->SubjectNameBox->TabIndex = 20;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(68, 256);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(83, 20);
			this->label4->TabIndex = 18;
			this->label4->Text = L"Kreditu sk.";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(68, 208);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(149, 20);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Dalyko pavadinimas";
			// 
			// EditUserLabel
			// 
			this->EditUserLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->EditUserLabel->AutoSize = true;
			this->EditUserLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EditUserLabel->Location = System::Drawing::Point(192, 51);
			this->EditUserLabel->Name = L"EditUserLabel";
			this->EditUserLabel->Size = System::Drawing::Size(166, 20);
			this->EditUserLabel->TabIndex = 15;
			this->EditUserLabel->Text = L"Redaguoti  naudotoja ";
			// 
			// EditSubjectForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 561);
			this->Controls->Add(this->CreditComboBox);
			this->Controls->Add(this->CloseModal);
			this->Controls->Add(this->EditSubjectButton);
			this->Controls->Add(this->SubjectNameBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->EditUserLabel);
			this->Name = L"EditSubjectForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EditSubjectForm";
			this->Load += gcnew System::EventHandler(this, &EditSubjectForm::EditSubjectForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void EditSubjectForm_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void EditSubjectButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void CloseModal_Click(System::Object^ sender, System::EventArgs^ e);
};
}
