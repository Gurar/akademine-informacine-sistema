#include <msclr/marshal_cppstd.h>
#include "AddSubjectForm.h"
using namespace AIS;

AddSubjectForm::AddSubjectForm(ISubjectRepository* subjectRepository, ICreditRepository* creditRepository)
{
	InitializeComponent();
	//
	//TODO: Add the constructor code here
	//
	this->subjectRepository = subjectRepository;
	this->creditRepository = creditRepository;

	credits = new std::vector<Credit*>();
}

System::Void AddSubjectForm::AddSubjectForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	*credits = creditRepository->getAll();

	CreditComboBox->Items->Clear();

	for (auto credit : *credits)
	{
		CreditComboBox->Items->Add(credit->number.ToString());
	}

}
System::Void AddSubjectForm::AddSubjectButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	using msclr::interop::marshal_as;

	std::string name = marshal_as<std::string>(SubjectNameBox->Text);

	if (name.size() <= 0)
	{
		MessageBox::Show("Tuscias laukas");
		return;
	}
		
	int index = CreditComboBox->SelectedIndex;

	if (index < 0)
	{
		MessageBox::Show("Pasirinkite Kreditu skaiciu");
		return;
	}

	int creditId = (*credits)[index]->id;
	int creditNumber = (*credits)[index]->number;

	Subject* subject = new Subject(0, name, creditId, creditNumber);

	subjectRepository->add(subject);

	MessageBox::Show("Subject added!");
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();

}
System::Void AddSubjectForm::CloseButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

