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
	/// Summary for AddSubjectForm
	/// </summary>
	public ref class AddSubjectForm : public System::Windows::Forms::Form
	{
	private:
		ISubjectRepository* subjectRepository;
		ICreditRepository* creditRepository;
		std::vector<Credit*>* credits;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ SubjectNameBox;


	private: System::Windows::Forms::Button^ CloseButton;
	private: System::Windows::Forms::Button^ AddSubjectButton;
	private: System::Windows::Forms::ComboBox^ CreditComboBox;



	public:
		AddSubjectForm(ISubjectRepository* subjectRepository, ICreditRepository* creditRepository);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddSubjectForm()
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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SubjectNameBox = (gcnew System::Windows::Forms::TextBox());
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			this->AddSubjectButton = (gcnew System::Windows::Forms::Button());
			this->CreditComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(104, 266);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 18);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Kreditu sk.";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(104, 223);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(142, 18);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Dalyko Pavadinimas";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(199, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(151, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Sukurti nauja dalyka";
			// 
			// SubjectNameBox
			// 
			this->SubjectNameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SubjectNameBox->Location = System::Drawing::Point(287, 219);
			this->SubjectNameBox->Name = L"SubjectNameBox";
			this->SubjectNameBox->Size = System::Drawing::Size(202, 26);
			this->SubjectNameBox->TabIndex = 6;
			// 
			// CloseButton
			// 
			this->CloseButton->Location = System::Drawing::Point(332, 366);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(130, 35);
			this->CloseButton->TabIndex = 7;
			this->CloseButton->Text = L"Atsaukti";
			this->CloseButton->UseVisualStyleBackColor = true;
			this->CloseButton->Click += gcnew System::EventHandler(this, &AddSubjectForm::CloseButton_Click);
			// 
			// AddSubjectButton
			// 
			this->AddSubjectButton->Location = System::Drawing::Point(107, 366);
			this->AddSubjectButton->Name = L"AddSubjectButton";
			this->AddSubjectButton->Size = System::Drawing::Size(130, 35);
			this->AddSubjectButton->TabIndex = 8;
			this->AddSubjectButton->Text = L"Patvirtinti";
			this->AddSubjectButton->UseVisualStyleBackColor = true;
			this->AddSubjectButton->Click += gcnew System::EventHandler(this, &AddSubjectForm::AddSubjectButton_Click);
			// 
			// CreditComboBox
			// 
			this->CreditComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CreditComboBox->FormattingEnabled = true;
			this->CreditComboBox->Location = System::Drawing::Point(287, 262);
			this->CreditComboBox->Name = L"CreditComboBox";
			this->CreditComboBox->Size = System::Drawing::Size(202, 28);
			this->CreditComboBox->TabIndex = 10;
			// 
			// AddSubjectForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 561);
			this->Controls->Add(this->CreditComboBox);
			this->Controls->Add(this->CloseButton);
			this->Controls->Add(this->AddSubjectButton);
			this->Controls->Add(this->SubjectNameBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"AddSubjectForm";
			this->Text = L"AddSubjectForm";
			this->Load += gcnew System::EventHandler(this, &AddSubjectForm::AddSubjectForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void AddSubjectForm_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void AddSubjectButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void CloseButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
