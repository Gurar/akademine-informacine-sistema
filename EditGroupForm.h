#pragma once
#include "IGroupRepository.h"

namespace AIS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EditGroupForm
	/// </summary>
	public ref class EditGroupForm : public System::Windows::Forms::Form
	{
	private:
		IGroupRepository* groupRepository;
		Group* selectedGroup;
	public:
		EditGroupForm(IGroupRepository* groupRepository, Group* group);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EditGroupForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ GroupNameBox;
	protected:

	private: System::Windows::Forms::Button^ CloseModal;
	private: System::Windows::Forms::Button^ EditGroupButton;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->GroupNameBox = (gcnew System::Windows::Forms::TextBox());
			this->CloseModal = (gcnew System::Windows::Forms::Button());
			this->EditGroupButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(85, 226);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(154, 20);
			this->label2->TabIndex = 22;
			this->label2->Text = L"Grupes pavadinimas";
			// 
			// GroupNameBox
			// 
			this->GroupNameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GroupNameBox->Location = System::Drawing::Point(282, 223);
			this->GroupNameBox->Name = L"GroupNameBox";
			this->GroupNameBox->Size = System::Drawing::Size(219, 26);
			this->GroupNameBox->TabIndex = 21;
			// 
			// CloseModal
			// 
			this->CloseModal->Location = System::Drawing::Point(306, 425);
			this->CloseModal->Name = L"CloseModal";
			this->CloseModal->Size = System::Drawing::Size(149, 38);
			this->CloseModal->TabIndex = 19;
			this->CloseModal->Text = L"Atsaukti";
			this->CloseModal->UseVisualStyleBackColor = true;
			this->CloseModal->Click += gcnew System::EventHandler(this, &EditGroupForm::CloseModal_Click);
			// 
			// EditGroupButton
			// 
			this->EditGroupButton->Location = System::Drawing::Point(90, 425);
			this->EditGroupButton->Name = L"EditGroupButton";
			this->EditGroupButton->Size = System::Drawing::Size(149, 38);
			this->EditGroupButton->TabIndex = 20;
			this->EditGroupButton->Text = L"Prideti";
			this->EditGroupButton->UseVisualStyleBackColor = true;
			this->EditGroupButton->Click += gcnew System::EventHandler(this, &EditGroupForm::EditGroupButton_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(202, 59);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(132, 20);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Redaguoti Grupe";
			// 
			// EditGroupForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 561);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->GroupNameBox);
			this->Controls->Add(this->CloseModal);
			this->Controls->Add(this->EditGroupButton);
			this->Controls->Add(this->label1);
			this->Name = L"EditGroupForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EditGroupForm";
			this->Load += gcnew System::EventHandler(this, &EditGroupForm::EditGroupForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void EditGroupForm_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void EditGroupButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void CloseModal_Click(System::Object^ sender, System::EventArgs^ e);
};
}
