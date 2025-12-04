#include <msclr/marshal_cppstd.h>
#include "EditSubjectForm.h"
using namespace AIS;

EditSubjectForm::EditSubjectForm(ISubjectRepository* subjectRepository, ICreditRepository* creditRepository, Subject* subject)
{
	InitializeComponent();
	//
	//TODO: Add the constructor code here
	//

	this->subjectRepository = subjectRepository;
	this->creditRepository = creditRepository;
	this->selectedSubject = subject;

	credits = new std::vector<Credit*>();

	this->Load += gcnew EventHandler(this, &EditSubjectForm::EditSubjectForm_Load);
}

System::Void EditSubjectForm::EditSubjectButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	using msclr::interop::marshal_as;

	selectedSubject->name = marshal_as<std::string>(SubjectNameBox->Text);

	int index = CreditComboBox->SelectedIndex;

	selectedSubject->creditId = (*credits)[index]->id;
	selectedSubject->creditNumber = (*credits)[index]->number;

	subjectRepository->update(selectedSubject);

	MessageBox::Show("Dalykas buvo redaguotas");
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}

System::Void EditSubjectForm::EditSubjectForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	SubjectNameBox->Text = gcnew String(selectedSubject->name.c_str());

	*credits = creditRepository->getAll();

	CreditComboBox->Items->Clear();

	int selectedIndex = -1;

	for (int i = 0; i < credits->size(); i++)
	{
		Credit* credit = (*credits)[i];

		CreditComboBox->Items->Add(credit->number);

		if (credit->number == selectedSubject->creditNumber)
		{
			selectedIndex = i;
		}
	}

	CreditComboBox->SelectedIndex = selectedIndex;
}

System::Void EditSubjectForm::CloseModal_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}


