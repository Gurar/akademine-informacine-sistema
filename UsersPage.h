#pragma once
#include "IUserRepository.h"
#include "IRoleRepository.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace AIS {

	/// <summary>
	/// Summary for UsersPage
	/// </summary>
	public ref class UsersPage : public System::Windows::Forms::UserControl
	{
	private:
		IUserRepository* userRepository;
		IRoleRepository* roleRepository;
	public:
		UsersPage(
			IUserRepository* currentUserRepository, 
			IRoleRepository* roleRepository

		);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UsersPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ UserDeleteButton;
	protected:
	private: System::Windows::Forms::Button^ UserAddButton;
	private: System::Windows::Forms::Button^ UserUpdateButton;
	private: System::Windows::Forms::TextBox^ UserFilterBox;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ UsersGrid;
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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->UserDeleteButton = (gcnew System::Windows::Forms::Button());
			this->UserAddButton = (gcnew System::Windows::Forms::Button());
			this->UserUpdateButton = (gcnew System::Windows::Forms::Button());
			this->UserFilterBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->UsersGrid = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UsersGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// UserDeleteButton
			// 
			this->UserDeleteButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->UserDeleteButton->Location = System::Drawing::Point(472, 469);
			this->UserDeleteButton->Name = L"UserDeleteButton";
			this->UserDeleteButton->Size = System::Drawing::Size(151, 41);
			this->UserDeleteButton->TabIndex = 18;
			this->UserDeleteButton->Text = L"Ištrinti";
			this->UserDeleteButton->UseVisualStyleBackColor = true;
			this->UserDeleteButton->Click += gcnew System::EventHandler(this, &UsersPage::UserDeleteButton_Click);
			// 
			// UserAddButton
			// 
			this->UserAddButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->UserAddButton->Location = System::Drawing::Point(25, 469);
			this->UserAddButton->Name = L"UserAddButton";
			this->UserAddButton->Size = System::Drawing::Size(151, 41);
			this->UserAddButton->TabIndex = 19;
			this->UserAddButton->Text = L"Prideti";
			this->UserAddButton->UseVisualStyleBackColor = true;
			this->UserAddButton->Click += gcnew System::EventHandler(this, &UsersPage::UserAddButton_Click);
			// 
			// UserUpdateButton
			// 
			this->UserUpdateButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->UserUpdateButton->Location = System::Drawing::Point(242, 469);
			this->UserUpdateButton->Name = L"UserUpdateButton";
			this->UserUpdateButton->Size = System::Drawing::Size(151, 41);
			this->UserUpdateButton->TabIndex = 20;
			this->UserUpdateButton->Text = L"Redaguoti";
			this->UserUpdateButton->UseVisualStyleBackColor = true;
			this->UserUpdateButton->Click += gcnew System::EventHandler(this, &UsersPage::UserUpdateButton_Click);
			// 
			// UserFilterBox
			// 
			this->UserFilterBox->Location = System::Drawing::Point(94, 65);
			this->UserFilterBox->Name = L"UserFilterBox";
			this->UserFilterBox->Size = System::Drawing::Size(188, 20);
			this->UserFilterBox->TabIndex = 17;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(21, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 20);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Filter";
			// 
			// UsersGrid
			// 
			this->UsersGrid->AllowUserToAddRows = false;
			this->UsersGrid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->UsersGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->UsersGrid->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->UsersGrid->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->UsersGrid->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->UsersGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->UsersGrid->Location = System::Drawing::Point(25, 117);
			this->UsersGrid->MultiSelect = false;
			this->UsersGrid->Name = L"UsersGrid";
			this->UsersGrid->ReadOnly = true;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(254)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::ButtonFace;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->UsersGrid->RowHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->UsersGrid->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->UsersGrid->Size = System::Drawing::Size(817, 305);
			this->UsersGrid->TabIndex = 15;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(21, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 20);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Naudotojai";
			// 
			// UsersPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->UserDeleteButton);
			this->Controls->Add(this->UserAddButton);
			this->Controls->Add(this->UserUpdateButton);
			this->Controls->Add(this->UserFilterBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->UsersGrid);
			this->Controls->Add(this->label1);
			this->Name = L"UsersPage";
			this->Size = System::Drawing::Size(1384, 581);
			this->Load += gcnew System::EventHandler(this, &UsersPage::UsersPage_Load);
			this->Click += gcnew System::EventHandler(this, &UsersPage::UsersPage_Click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UsersGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: 
			System::Void LoadAllUsers();
			System::Void UsersPage_Load(System::Object^ sender, System::EventArgs^ e);
			System::Void UserAddButton_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void UserUpdateButton_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void UserDeleteButton_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void UsersPage_Click(System::Object^ sender, System::EventArgs^ e);
};
}
