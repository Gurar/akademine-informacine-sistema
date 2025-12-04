#pragma once
#include "IUserRepository.h"
#include "ISubjectRepository.h"
#include "IGroupRepository.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace AIS {

	/// <summary>
	/// Summary for AssignsPage
	/// </summary>
	public ref class AssignsPage : public System::Windows::Forms::UserControl
	{
		IGroupRepository* groupRepository;
		ISubjectRepository* subjectRepository;
		IUserRepository* userRepository;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ GroupsComboBox;
	private: System::Windows::Forms::Button^ StudentAssign;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ SubjectsGrid;
	private: System::Windows::Forms::DataGridView^ UsersGrid;
	private: System::Windows::Forms::Button^ SubjectAssign;
	private: System::Windows::Forms::Button^ StudentAssignDelete;
	private: System::Windows::Forms::Button^ SubjectAssignDelete;
	private: System::Windows::Forms::Button^ TeacherAssignDelete;

	private: System::Windows::Forms::Button^ TeacherAssign;
		  
	public:
		AssignsPage(IUserRepository* userRepository, ISubjectRepository* subjectRepository, IGroupRepository* groupRepository);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AssignsPage()
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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->GroupsComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->StudentAssign = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SubjectsGrid = (gcnew System::Windows::Forms::DataGridView());
			this->UsersGrid = (gcnew System::Windows::Forms::DataGridView());
			this->SubjectAssign = (gcnew System::Windows::Forms::Button());
			this->TeacherAssign = (gcnew System::Windows::Forms::Button());
			this->StudentAssignDelete = (gcnew System::Windows::Forms::Button());
			this->SubjectAssignDelete = (gcnew System::Windows::Forms::Button());
			this->TeacherAssignDelete = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SubjectsGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UsersGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(1063, 90);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 20);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Grupie";
			// 
			// GroupsComboBox
			// 
			this->GroupsComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GroupsComboBox->FormattingEnabled = true;
			this->GroupsComboBox->Location = System::Drawing::Point(1143, 87);
			this->GroupsComboBox->Name = L"GroupsComboBox";
			this->GroupsComboBox->Size = System::Drawing::Size(204, 28);
			this->GroupsComboBox->TabIndex = 18;
			// 
			// StudentAssign
			// 
			this->StudentAssign->Location = System::Drawing::Point(53, 523);
			this->StudentAssign->Name = L"StudentAssign";
			this->StudentAssign->Size = System::Drawing::Size(146, 41);
			this->StudentAssign->TabIndex = 17;
			this->StudentAssign->Text = L"Priskirti studenta prie grupes";
			this->StudentAssign->UseVisualStyleBackColor = true;
			this->StudentAssign->Click += gcnew System::EventHandler(this, &AssignsPage::StudentAssign_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(37, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 20);
			this->label1->TabIndex = 16;
			this->label1->Text = L"Priskirti";
			// 
			// SubjectsGrid
			// 
			this->SubjectsGrid->AllowUserToAddRows = false;
			this->SubjectsGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->SubjectsGrid->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->SubjectsGrid->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SubjectsGrid->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->SubjectsGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->SubjectsGrid->Location = System::Drawing::Point(632, 87);
			this->SubjectsGrid->MultiSelect = false;
			this->SubjectsGrid->Name = L"SubjectsGrid";
			this->SubjectsGrid->ReadOnly = true;
			this->SubjectsGrid->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->SubjectsGrid->Size = System::Drawing::Size(352, 305);
			this->SubjectsGrid->TabIndex = 14;
			// 
			// UsersGrid
			// 
			this->UsersGrid->AllowUserToAddRows = false;
			this->UsersGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->UsersGrid->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->UsersGrid->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->UsersGrid->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->UsersGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->UsersGrid->Location = System::Drawing::Point(41, 87);
			this->UsersGrid->MultiSelect = false;
			this->UsersGrid->Name = L"UsersGrid";
			this->UsersGrid->ReadOnly = true;
			this->UsersGrid->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->UsersGrid->Size = System::Drawing::Size(495, 305);
			this->UsersGrid->TabIndex = 15;
			// 
			// SubjectAssign
			// 
			this->SubjectAssign->Location = System::Drawing::Point(248, 523);
			this->SubjectAssign->Name = L"SubjectAssign";
			this->SubjectAssign->Size = System::Drawing::Size(146, 41);
			this->SubjectAssign->TabIndex = 20;
			this->SubjectAssign->Text = L"Priskirti Dalyka prie grupes";
			this->SubjectAssign->UseVisualStyleBackColor = true;
			this->SubjectAssign->Click += gcnew System::EventHandler(this, &AssignsPage::SubjectAssign_Click);
			// 
			// TeacherAssign
			// 
			this->TeacherAssign->Location = System::Drawing::Point(445, 523);
			this->TeacherAssign->Name = L"TeacherAssign";
			this->TeacherAssign->Size = System::Drawing::Size(146, 41);
			this->TeacherAssign->TabIndex = 21;
			this->TeacherAssign->Text = L"Priskirti Destitoja prie dalyko";
			this->TeacherAssign->UseVisualStyleBackColor = true;
			this->TeacherAssign->Click += gcnew System::EventHandler(this, &AssignsPage::TeacherAssign_Click);
			// 
			// StudentAssignDelete
			// 
			this->StudentAssignDelete->Location = System::Drawing::Point(643, 523);
			this->StudentAssignDelete->Name = L"StudentAssignDelete";
			this->StudentAssignDelete->Size = System::Drawing::Size(158, 41);
			this->StudentAssignDelete->TabIndex = 22;
			this->StudentAssignDelete->Text = L"Pasalinti studenta is grupes";
			this->StudentAssignDelete->UseVisualStyleBackColor = true;
			this->StudentAssignDelete->Click += gcnew System::EventHandler(this, &AssignsPage::StudentAssignDelete_Click);
			// 
			// SubjectAssignDelete
			// 
			this->SubjectAssignDelete->Location = System::Drawing::Point(859, 523);
			this->SubjectAssignDelete->Name = L"SubjectAssignDelete";
			this->SubjectAssignDelete->Size = System::Drawing::Size(146, 41);
			this->SubjectAssignDelete->TabIndex = 23;
			this->SubjectAssignDelete->Text = L"Pasalinti dalyka is grupes";
			this->SubjectAssignDelete->UseVisualStyleBackColor = true;
			this->SubjectAssignDelete->Click += gcnew System::EventHandler(this, &AssignsPage::SubjectAssignDelete_Click);
			// 
			// TeacherAssignDelete
			// 
			this->TeacherAssignDelete->Location = System::Drawing::Point(1052, 523);
			this->TeacherAssignDelete->Name = L"TeacherAssignDelete";
			this->TeacherAssignDelete->Size = System::Drawing::Size(146, 41);
			this->TeacherAssignDelete->TabIndex = 24;
			this->TeacherAssignDelete->Text = L"Pasalinti destitoja is dalyko";
			this->TeacherAssignDelete->UseVisualStyleBackColor = true;
			this->TeacherAssignDelete->Click += gcnew System::EventHandler(this, &AssignsPage::TeacherAssignDelete_Click);
			// 
			// AssignsPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->TeacherAssignDelete);
			this->Controls->Add(this->SubjectAssignDelete);
			this->Controls->Add(this->StudentAssignDelete);
			this->Controls->Add(this->TeacherAssign);
			this->Controls->Add(this->SubjectAssign);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->GroupsComboBox);
			this->Controls->Add(this->StudentAssign);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->SubjectsGrid);
			this->Controls->Add(this->UsersGrid);
			this->Name = L"AssignsPage";
			this->Size = System::Drawing::Size(1384, 685);
			this->Load += gcnew System::EventHandler(this, &AssignsPage::AssignsPage_Load);
			this->Click += gcnew System::EventHandler(this, &AssignsPage::AssignsPage_Click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SubjectsGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UsersGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void AssignsPage_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void AssignsPage_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void StudentAssign_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void SubjectAssign_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void TeacherAssign_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void StudentAssignDelete_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void SubjectAssignDelete_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void TeacherAssignDelete_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void AssignsPage::LoadUsers();
		System::Void AssignsPage::LoadSubjects();
		System::Void AssignsPage::LoadGroups();
};
}
