#pragma once
#include "Teacher.h"
#include "ITeacherRepository.h"
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
	/// Summary for TeacherPage
	/// </summary>
	public ref class TeacherPage : public System::Windows::Forms::UserControl
	{
	private:
		Teacher* currentUser;
		ITeacherRepository* teacherRepository;
		IGroupRepository* groupRepository;
		IGradeRepository* gradeRepository;
	private: System::Windows::Forms::DataGridView^ SubjectsGrid;
	private: System::Windows::Forms::DataGridView^ UsersGrid;

	private: System::Windows::Forms::Button^ ShowGradeButton;
	private: System::Windows::Forms::TextBox^ GradeNumberBox;




	private: System::Windows::Forms::Label^ label1;



	private: System::Windows::Forms::Button^ SaveGrade;
	private: System::Windows::Forms::DataGridView^ GradeGrid;
	private: System::Windows::Forms::ComboBox^ GradeTypeSelect;
	private: System::Windows::Forms::Label^ label2;



	private: System::Windows::Forms::Button^ ShownStudentsButton;
	public:
		TeacherPage(Teacher* user, ITeacherRepository* teacherRepository, IGroupRepository* groupRepository, IGradeRepository* gradeRepository);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TeacherPage()
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
			this->SubjectsGrid = (gcnew System::Windows::Forms::DataGridView());
			this->UsersGrid = (gcnew System::Windows::Forms::DataGridView());
			this->ShownStudentsButton = (gcnew System::Windows::Forms::Button());
			this->ShowGradeButton = (gcnew System::Windows::Forms::Button());
			this->GradeNumberBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SaveGrade = (gcnew System::Windows::Forms::Button());
			this->GradeGrid = (gcnew System::Windows::Forms::DataGridView());
			this->GradeTypeSelect = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SubjectsGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UsersGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GradeGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// SubjectsGrid
			// 
			this->SubjectsGrid->AllowUserToAddRows = false;
			this->SubjectsGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->SubjectsGrid->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->SubjectsGrid->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SubjectsGrid->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->SubjectsGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->SubjectsGrid->Location = System::Drawing::Point(80, 68);
			this->SubjectsGrid->MultiSelect = false;
			this->SubjectsGrid->Name = L"SubjectsGrid";
			this->SubjectsGrid->ReadOnly = true;
			this->SubjectsGrid->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->SubjectsGrid->Size = System::Drawing::Size(452, 240);
			this->SubjectsGrid->TabIndex = 15;
			// 
			// UsersGrid
			// 
			this->UsersGrid->AllowUserToAddRows = false;
			this->UsersGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->UsersGrid->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->UsersGrid->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->UsersGrid->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->UsersGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->UsersGrid->Location = System::Drawing::Point(663, 68);
			this->UsersGrid->MultiSelect = false;
			this->UsersGrid->Name = L"UsersGrid";
			this->UsersGrid->ReadOnly = true;
			this->UsersGrid->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->UsersGrid->Size = System::Drawing::Size(565, 149);
			this->UsersGrid->TabIndex = 16;
			// 
			// ShownStudentsButton
			// 
			this->ShownStudentsButton->Location = System::Drawing::Point(80, 464);
			this->ShownStudentsButton->Name = L"ShownStudentsButton";
			this->ShownStudentsButton->Size = System::Drawing::Size(167, 51);
			this->ShownStudentsButton->TabIndex = 17;
			this->ShownStudentsButton->Text = L"Roditi studentus";
			this->ShownStudentsButton->UseVisualStyleBackColor = true;
			this->ShownStudentsButton->Click += gcnew System::EventHandler(this, &TeacherPage::ShownStudentsButton_Click);
			// 
			// ShowGradeButton
			// 
			this->ShowGradeButton->Location = System::Drawing::Point(298, 464);
			this->ShowGradeButton->Name = L"ShowGradeButton";
			this->ShowGradeButton->Size = System::Drawing::Size(167, 51);
			this->ShowGradeButton->TabIndex = 19;
			this->ShowGradeButton->Text = L"Roditi vertinimus";
			this->ShowGradeButton->UseVisualStyleBackColor = true;
			this->ShowGradeButton->Click += gcnew System::EventHandler(this, &TeacherPage::ShowGradeButton_Click);
			// 
			// GradeNumberBox
			// 
			this->GradeNumberBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GradeNumberBox->Location = System::Drawing::Point(835, 464);
			this->GradeNumberBox->Name = L"GradeNumberBox";
			this->GradeNumberBox->Size = System::Drawing::Size(108, 26);
			this->GradeNumberBox->TabIndex = 20;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(738, 467);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 20);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Pazimis";
			// 
			// SaveGrade
			// 
			this->SaveGrade->Location = System::Drawing::Point(536, 464);
			this->SaveGrade->Name = L"SaveGrade";
			this->SaveGrade->Size = System::Drawing::Size(167, 51);
			this->SaveGrade->TabIndex = 22;
			this->SaveGrade->Text = L"Isaugoti vertinimus";
			this->SaveGrade->UseVisualStyleBackColor = true;
			this->SaveGrade->Click += gcnew System::EventHandler(this, &TeacherPage::SaveGrade_Click);
			// 
			// GradeGrid
			// 
			this->GradeGrid->AllowUserToAddRows = false;
			this->GradeGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->GradeGrid->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->GradeGrid->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->GradeGrid->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->GradeGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->GradeGrid->Location = System::Drawing::Point(663, 252);
			this->GradeGrid->MultiSelect = false;
			this->GradeGrid->Name = L"GradeGrid";
			this->GradeGrid->ReadOnly = true;
			this->GradeGrid->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->GradeGrid->Size = System::Drawing::Size(565, 114);
			this->GradeGrid->TabIndex = 23;
			// 
			// GradeTypeSelect
			// 
			this->GradeTypeSelect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GradeTypeSelect->FormattingEnabled = true;
			this->GradeTypeSelect->Location = System::Drawing::Point(1125, 462);
			this->GradeTypeSelect->Name = L"GradeTypeSelect";
			this->GradeTypeSelect->Size = System::Drawing::Size(103, 28);
			this->GradeTypeSelect->TabIndex = 24;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(1028, 465);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 20);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Tipas";
			// 
			// TeacherPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->GradeTypeSelect);
			this->Controls->Add(this->GradeGrid);
			this->Controls->Add(this->SaveGrade);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->GradeNumberBox);
			this->Controls->Add(this->ShowGradeButton);
			this->Controls->Add(this->ShownStudentsButton);
			this->Controls->Add(this->UsersGrid);
			this->Controls->Add(this->SubjectsGrid);
			this->Name = L"TeacherPage";
			this->Size = System::Drawing::Size(1384, 625);
			this->Load += gcnew System::EventHandler(this, &TeacherPage::TeacherPage_Load);
			this->Click += gcnew System::EventHandler(this, &TeacherPage::TeacherPage_Click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SubjectsGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UsersGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GradeGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void TeacherPage_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void LoadSubjects();
		System::Void ShownStudentsButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void TeacherPage_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void ShowGradeButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void SaveGrade_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void LoadGradeTypes();
		System::Void LoadGradesForSelectedStudent();
};
}
