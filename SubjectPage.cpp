#include <msclr/marshal_cppstd.h>
#include "SubjectPage.h"
#include "AddSubjectForm.h"
#include "EditSubjectForm.h"
using namespace AIS;

SubjectPage::SubjectPage(ISubjectRepository* subjectRepository, ICreditRepository* creditRepository)
{
	InitializeComponent();
	//
	//TODO: Add the constructor code here
	//
	this->subjectRepository = subjectRepository;
	this->creditRepository = creditRepository;

    credits = new std::vector<Credit*>();

    SubjectGrid->Columns->Add("Id", "ID");
    SubjectGrid->Columns->Add("Name", "Dalykas");
    SubjectGrid->Columns->Add("Credit", "Kreditu sk.");

}

System::Void SubjectPage::SubjectAddButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    AddSubjectForm^ form = gcnew AddSubjectForm(subjectRepository, creditRepository);
    if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK)
    {
        LoadSubjects();
    }
}
System::Void SubjectPage::SubjectUpdateButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (SubjectGrid->SelectedRows->Count == 0)
    {
        MessageBox::Show("Pasirinkite Dalyka");
        return;
    }

    DataGridViewRow^ row = SubjectGrid->SelectedRows[0];

    int id = Convert::ToInt32(row->Cells["Id"]->Value);

    String^ nameStr = row->Cells["Name"]->Value->ToString();
    std::string name = msclr::interop::marshal_as<std::string>(nameStr);

    int number = Convert::ToInt32(row->Cells["Credit"]->Value);

    *credits = creditRepository->getAll();

    int creditId = -1;

    for (auto credit : *credits)
    {
        if (credit->number == number)
        {
            creditId = credit->id;
            break;
        }
    }

    if (creditId == -1)
    {
        MessageBox::Show("Kredito ID nerastas!");
        return;
    }

    Subject* selectedSubject = new Subject(id, name, creditId, number);

    EditSubjectForm^ form = gcnew EditSubjectForm(subjectRepository, creditRepository, selectedSubject);

    if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK)
    {
        LoadSubjects();
    }


}
System::Void SubjectPage::SubjectDeleteButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (SubjectGrid->SelectedRows->Count == 0)
    {
        MessageBox::Show("Pasirinkite dalyka");
        return;
    }

    DataGridViewRow^ row = SubjectGrid->SelectedRows[0];

    int id = Convert::ToInt32(row->Cells["Id"]->Value);

    if (subjectRepository->isAssignedToAnyGroup(id))
    {
        MessageBox::Show("Sis dalykas negali buti istrintas, nes jis priskirtas grupei!");
        return;
    }

    
    if (subjectRepository->isAssignedToAnyTeacher(id))
    {
        MessageBox::Show("Sis dalykas negali buti istrintas, nes jis priskirtas destytojui!");
        return;
    }

    if (MessageBox::Show("Ar tikrai norite pasalinti?",
        "Patvirtinimas", MessageBoxButtons::YesNo) == DialogResult::No)
    {
        return;
    }


    subjectRepository->remove(id);

    LoadSubjects();

    MessageBox::Show("Subject deleted successfully.");
}

System::Void SubjectPage::SubjectPage_Load(System::Object^ sender, System::EventArgs^ e)
{
    LoadSubjects();
}

System::Void SubjectPage::SubjectPage_Click(System::Object^ sender, System::EventArgs^ e)
{
    SubjectGrid->ClearSelection();
    SubjectGrid->CurrentCell = nullptr;
}

System::Void SubjectPage::LoadSubjects()
{
    auto subjects = subjectRepository->getAll();


    SubjectGrid->Rows->Clear();

    

    for (auto subject : subjects)
    {
        SubjectGrid->Rows->Add(
            subject->id,
            gcnew String(subject->name.c_str()),
            subject->creditNumber
        );
    }

    SubjectGrid->ClearSelection();
    SubjectGrid->CurrentCell = nullptr;
}
