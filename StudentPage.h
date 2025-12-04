#pragma once
#include "Student.h"
#include "IGroupRepository.h"
#include "IGradeRepository.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace AIS {

	/// <summary>
	/// Summary for StudentPage
	/// </summary>
	public ref class StudentPage : public System::Windows::Forms::UserControl
	{
		Student* currentUser;
		IGroupRepository* groupRepository;
		IGradeRepository* gradeRepository;
	public:
		StudentPage(Student* user, IGroupRepository* groupRepository, IGradeRepository* gradeRepository);
		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StudentPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ GradeGrid;
	protected:
	private: System::Windows::Forms::Button^ ShowGradeButton;
	private: System::Windows::Forms::DataGridView^ SubjectsGrid;

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
			this->GradeGrid = (gcnew System::Windows::Forms::DataGridView());
			this->ShowGradeButton = (gcnew System::Windows::Forms::Button());
			this->SubjectsGrid = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GradeGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SubjectsGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// GradeGrid
			// 
			this->GradeGrid->AllowUserToAddRows = false;
			this->GradeGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->GradeGrid->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->GradeGrid->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->GradeGrid->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->GradeGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->GradeGrid->Location = System::Drawing::Point(552, 80);
			this->GradeGrid->MultiSelect = false;
			this->GradeGrid->Name = L"GradeGrid";
			this->GradeGrid->ReadOnly = true;
			this->GradeGrid->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->GradeGrid->Size = System::Drawing::Size(565, 114);
			this->GradeGrid->TabIndex = 26;
			// 
			// ShowGradeButton
			// 
			this->ShowGradeButton->Location = System::Drawing::Point(36, 437);
			this->ShowGradeButton->Name = L"ShowGradeButton";
			this->ShowGradeButton->Size = System::Drawing::Size(167, 51);
			this->ShowGradeButton->TabIndex = 25;
			this->ShowGradeButton->Text = L"Roditi vertinimus";
			this->ShowGradeButton->UseVisualStyleBackColor = true;
			this->ShowGradeButton->Click += gcnew System::EventHandler(this, &StudentPage::ShowGradeButton_Click);
			// 
			// SubjectsGrid
			// 
			this->SubjectsGrid->AllowUserToAddRows = false;
			this->SubjectsGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->SubjectsGrid->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->SubjectsGrid->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SubjectsGrid->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->SubjectsGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->SubjectsGrid->Location = System::Drawing::Point(36, 80);
			this->SubjectsGrid->MultiSelect = false;
			this->SubjectsGrid->Name = L"SubjectsGrid";
			this->SubjectsGrid->ReadOnly = true;
			this->SubjectsGrid->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->SubjectsGrid->Size = System::Drawing::Size(452, 240);
			this->SubjectsGrid->TabIndex = 24;
			// 
			// StudentPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->GradeGrid);
			this->Controls->Add(this->ShowGradeButton);
			this->Controls->Add(this->SubjectsGrid);
			this->Name = L"StudentPage";
			this->Size = System::Drawing::Size(1384, 581);
			this->Load += gcnew System::EventHandler(this, &StudentPage::StudentPage_Load);
			this->Click += gcnew System::EventHandler(this, &StudentPage::StudentPage_Click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GradeGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SubjectsGrid))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		System::Void StudentPage_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void StudentPage_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void ShowGradeButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void LoadSubjects();
};
}
