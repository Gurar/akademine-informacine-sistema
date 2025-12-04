#pragma once
#include "ISubjectRepository.h"
#include "ICreditRepository.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace AIS {

	/// <summary>
	/// Summary for SubjectPage
	/// </summary>
	public ref class SubjectPage : public System::Windows::Forms::UserControl
	{
	private:
		ISubjectRepository* subjectRepository;
		ICreditRepository* creditRepository;






	private: System::Windows::Forms::Button^ SubjectUpdateButton;
	private: System::Windows::Forms::Button^ SubjectDeleteButton;
	private: System::Windows::Forms::Button^ SubjectAddButton;

	private: System::Windows::Forms::Label^ label2;




	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::DataGridView^ SubjectGrid;



		   std::vector<Credit*>* credits;
	public:
		SubjectPage(ISubjectRepository* subjectRepository, ICreditRepository* credirRepository);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SubjectPage()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->SubjectUpdateButton = (gcnew System::Windows::Forms::Button());
			this->SubjectDeleteButton = (gcnew System::Windows::Forms::Button());
			this->SubjectAddButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->SubjectGrid = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SubjectGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// SubjectUpdateButton
			// 
			this->SubjectUpdateButton->Location = System::Drawing::Point(244, 474);
			this->SubjectUpdateButton->Name = L"SubjectUpdateButton";
			this->SubjectUpdateButton->Size = System::Drawing::Size(151, 41);
			this->SubjectUpdateButton->TabIndex = 27;
			this->SubjectUpdateButton->Text = L"Redaguoti naudotoja";
			this->SubjectUpdateButton->UseVisualStyleBackColor = true;
			this->SubjectUpdateButton->Click += gcnew System::EventHandler(this, &SubjectPage::SubjectUpdateButton_Click);
			// 
			// SubjectDeleteButton
			// 
			this->SubjectDeleteButton->Location = System::Drawing::Point(463, 474);
			this->SubjectDeleteButton->Name = L"SubjectDeleteButton";
			this->SubjectDeleteButton->Size = System::Drawing::Size(151, 41);
			this->SubjectDeleteButton->TabIndex = 25;
			this->SubjectDeleteButton->Text = L"Ištrinti naudotoja";
			this->SubjectDeleteButton->UseVisualStyleBackColor = true;
			this->SubjectDeleteButton->Click += gcnew System::EventHandler(this, &SubjectPage::SubjectDeleteButton_Click);
			// 
			// SubjectAddButton
			// 
			this->SubjectAddButton->Location = System::Drawing::Point(29, 474);
			this->SubjectAddButton->Name = L"SubjectAddButton";
			this->SubjectAddButton->Size = System::Drawing::Size(151, 41);
			this->SubjectAddButton->TabIndex = 26;
			this->SubjectAddButton->Text = L"Sukurti naudotoja";
			this->SubjectAddButton->UseVisualStyleBackColor = true;
			this->SubjectAddButton->Click += gcnew System::EventHandler(this, &SubjectPage::SubjectAddButton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(25, 73);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 20);
			this->label2->TabIndex = 23;
			this->label2->Text = L"Filter";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(25, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 20);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Dalykai";
			// 
			// comboBox2
			// 
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(99, 70);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(153, 28);
			this->comboBox2->TabIndex = 29;
			// 
			// SubjectGrid
			// 
			this->SubjectGrid->AllowUserToAddRows = false;
			this->SubjectGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->SubjectGrid->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->SubjectGrid->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SubjectGrid->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->SubjectGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->SubjectGrid->Location = System::Drawing::Point(29, 125);
			this->SubjectGrid->MultiSelect = false;
			this->SubjectGrid->Name = L"SubjectGrid";
			this->SubjectGrid->ReadOnly = true;
			this->SubjectGrid->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->SubjectGrid->Size = System::Drawing::Size(495, 305);
			this->SubjectGrid->TabIndex = 30;
			// 
			// SubjectPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->SubjectGrid);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->SubjectDeleteButton);
			this->Controls->Add(this->SubjectAddButton);
			this->Controls->Add(this->SubjectUpdateButton);
			this->Name = L"SubjectPage";
			this->Size = System::Drawing::Size(1384, 581);
			this->Load += gcnew System::EventHandler(this, &SubjectPage::SubjectPage_Load);
			this->Click += gcnew System::EventHandler(this, &SubjectPage::SubjectPage_Click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SubjectGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void SubjectAddButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void SubjectUpdateButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void SubjectDeleteButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void SubjectPage_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void LoadSubjects();
		System::Void SubjectPage_Click(System::Object^ sender, System::EventArgs^ e);
};
}
