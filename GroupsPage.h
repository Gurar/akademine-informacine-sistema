#pragma once
#include "IGroupRepository.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace AIS {

	/// <summary>
	/// Summary for GroupsPage
	/// </summary>
	public ref class GroupsPage : public System::Windows::Forms::UserControl
	{
	private:
		IGroupRepository* groupRepository;
	public:
		GroupsPage(IGroupRepository* groupRepository);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GroupsPage()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Button^ GroupDeleteButton;

	protected:

	private: System::Windows::Forms::Button^ GroupUpdateButton;

	private: System::Windows::Forms::Button^ GroupAddButton;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ GroupGrid;


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
			this->GroupDeleteButton = (gcnew System::Windows::Forms::Button());
			this->GroupUpdateButton = (gcnew System::Windows::Forms::Button());
			this->GroupAddButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->GroupGrid = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GroupGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// GroupDeleteButton
			// 
			this->GroupDeleteButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->GroupDeleteButton->Location = System::Drawing::Point(431, 449);
			this->GroupDeleteButton->Name = L"GroupDeleteButton";
			this->GroupDeleteButton->Size = System::Drawing::Size(151, 41);
			this->GroupDeleteButton->TabIndex = 33;
			this->GroupDeleteButton->Text = L"Ištrinti grupe";
			this->GroupDeleteButton->UseVisualStyleBackColor = true;
			this->GroupDeleteButton->Click += gcnew System::EventHandler(this, &GroupsPage::GroupDeleteButton_Click);
			// 
			// GroupUpdateButton
			// 
			this->GroupUpdateButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->GroupUpdateButton->Location = System::Drawing::Point(229, 449);
			this->GroupUpdateButton->Name = L"GroupUpdateButton";
			this->GroupUpdateButton->Size = System::Drawing::Size(151, 41);
			this->GroupUpdateButton->TabIndex = 35;
			this->GroupUpdateButton->Text = L"Redaguoti grupe";
			this->GroupUpdateButton->UseVisualStyleBackColor = true;
			this->GroupUpdateButton->Click += gcnew System::EventHandler(this, &GroupsPage::GroupUpdateButton_Click);
			// 
			// GroupAddButton
			// 
			this->GroupAddButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->GroupAddButton->Location = System::Drawing::Point(27, 449);
			this->GroupAddButton->Name = L"GroupAddButton";
			this->GroupAddButton->Size = System::Drawing::Size(151, 41);
			this->GroupAddButton->TabIndex = 34;
			this->GroupAddButton->Text = L"Sukurti  grupe";
			this->GroupAddButton->UseVisualStyleBackColor = true;
			this->GroupAddButton->Click += gcnew System::EventHandler(this, &GroupsPage::GroupAddButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(23, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 20);
			this->label1->TabIndex = 36;
			this->label1->Text = L"Grupes";
			// 
			// GroupGrid
			// 
			this->GroupGrid->AllowUserToAddRows = false;
			this->GroupGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->GroupGrid->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->GroupGrid->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->GroupGrid->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->GroupGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->GroupGrid->Location = System::Drawing::Point(27, 76);
			this->GroupGrid->MultiSelect = false;
			this->GroupGrid->Name = L"GroupGrid";
			this->GroupGrid->ReadOnly = true;
			this->GroupGrid->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->GroupGrid->Size = System::Drawing::Size(399, 305);
			this->GroupGrid->TabIndex = 37;
			// 
			// GroupsPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->GroupGrid);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->GroupDeleteButton);
			this->Controls->Add(this->GroupUpdateButton);
			this->Controls->Add(this->GroupAddButton);
			this->Name = L"GroupsPage";
			this->Size = System::Drawing::Size(1384, 581);
			this->Load += gcnew System::EventHandler(this, &GroupsPage::GroupsPage_Load);
			this->Click += gcnew System::EventHandler(this, &GroupsPage::GroupsPage_Click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GroupGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void GroupsPage_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void GroupAddButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void GroupUpdateButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void GroupDeleteButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void LoadAllGroups();
		System::Void GroupsPage_Click(System::Object^ sender, System::EventArgs^ e);
};
}
