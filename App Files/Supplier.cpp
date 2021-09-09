#include "Supplier.h"
#include <wx/wx.h>
#include "wx/textfile.h"
#include <fstream>

using namespace std;

wxTextFile sfile(wxT("D:\\suppliers.txt"));

Supplier::Supplier(const wxString& title)
    : wxFrame((wxFrame*)NULL, wxID_ANY, title, wxPoint(wxID_ANY, wxID_ANY), wxSize(340, 150),
        wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX | wxCAPTION | wxCLIP_CHILDREN)
{
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer* hbox1 = new wxBoxSizer(wxHORIZONTAL);
    m_usernameLabel = new wxStaticText(panel, wxID_ANY, wxT("Supplier: "), wxDefaultPosition, wxSize(70, -1));
    hbox1->Add(m_usernameLabel, 0);

    m_usernameEntry = new wxTextCtrl(panel, wxID_ANY);
    hbox1->Add(m_usernameEntry, 1);
    vbox->Add(hbox1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    //wxBoxSizer* hbox2 = new wxBoxSizer(wxHORIZONTAL);
    //m_passwordLabel = new wxStaticText(panel, wxID_ANY, wxT("Supplier ID: "), wxDefaultPosition, wxSize(70, -1));
    //hbox2->Add(m_passwordLabel, 0);

    //m_passwordEntry = new wxTextCtrl(panel, wxID_ANY, wxString(""),
        //wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
    //hbox2->Add(m_passwordEntry, 1);
    //vbox->Add(hbox2, 0, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, 10);

    wxBoxSizer* hbox3 = new wxBoxSizer(wxHORIZONTAL);
    m_buttonLogin = new wxButton(panel, 30006, wxT("Add Supplier"));
    hbox3->Add(m_buttonLogin);

    m_buttonQuit = new wxButton(panel, wxID_EXIT, ("Quit"));
    hbox3->Add(m_buttonQuit);
    vbox->Add(hbox3, 0, wxALIGN_RIGHT | wxTOP | wxRIGHT | wxBOTTOM, 10);

    panel->SetSizer(vbox);
    Centre();
}

void Supplier::OnQuit(wxCommandEvent& event)
{
    Close(true);
}

void Supplier::OnAdd(wxCommandEvent& event)
{

    wxString username = m_usernameEntry->GetValue();
    wxString password = m_passwordEntry->GetValue();

    if (username.empty() || password.empty()) {
        wxMessageBox(wxT("Must not empty"), wxT("Warning!"), wxICON_WARNING);
    }
    else {
        wxMessageBox(wxT("Added Succesfully"), wxT("Message!"), wxICON_INFORMATION);
    }

    sfile.Open();

    sfile.AddLine(username);
    sfile.AddLine(password);
    sfile.AddLine(wxT(" "));

    sfile.Write();
    sfile.Close();

    m_usernameEntry->Clear();
    m_passwordEntry->Clear();
}

Supplier::~Supplier() {}

BEGIN_EVENT_TABLE(Supplier, wxFrame)
EVT_BUTTON(wxID_EXIT, Supplier::OnQuit)
EVT_BUTTON(30006, Supplier::OnAdd)
END_EVENT_TABLE()