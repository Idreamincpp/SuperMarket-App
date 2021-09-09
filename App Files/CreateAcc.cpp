#include "CreateAcc.h"
#include <wx/wx.h>
#include "wx/textfile.h"
#include <fstream>

using namespace std;

wxTextFile qfile(wxT("D:\\user.txt"));
fstream rfile;

CreateAcc::CreateAcc(const wxString& title)
    : wxFrame((wxFrame*)NULL, wxID_ANY, title, wxPoint(wxID_ANY, wxID_ANY), wxSize(340, 150),
        wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX | wxCAPTION | wxCLIP_CHILDREN)
{
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer* hbox1 = new wxBoxSizer(wxHORIZONTAL);
    m_usernameLabel = new wxStaticText(panel, wxID_ANY, wxT("Username: "), wxDefaultPosition, wxSize(70, -1));
    hbox1->Add(m_usernameLabel, 0);

    m_usernameEntry = new wxTextCtrl(panel, wxID_ANY);
    hbox1->Add(m_usernameEntry, 1);
    vbox->Add(hbox1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    wxBoxSizer* hbox2 = new wxBoxSizer(wxHORIZONTAL);
    m_passwordLabel = new wxStaticText(panel, wxID_ANY, wxT("Password: "), wxDefaultPosition, wxSize(70, -1));
    hbox2->Add(m_passwordLabel, 0);

    m_passwordEntry = new wxTextCtrl(panel, wxID_ANY, wxString(""),
        wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
    hbox2->Add(m_passwordEntry, 1);
    vbox->Add(hbox2, 0, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, 10);

    wxBoxSizer* hbox3 = new wxBoxSizer(wxHORIZONTAL);
    m_buttonSignUp = new wxButton(panel, 30006, wxT("Sign Up"));
    hbox3->Add(m_buttonSignUp);

    m_buttonQuit = new wxButton(panel, wxID_EXIT, ("Quit"));
    hbox3->Add(m_buttonQuit);
    vbox->Add(hbox3, 0, wxALIGN_RIGHT | wxTOP | wxRIGHT | wxBOTTOM, 10);

    panel->SetSizer(vbox);
    Centre();
}

void CreateAcc::OnClose(wxCommandEvent& event)
{
    Close(true);
}

void CreateAcc::OnSignUp(wxCommandEvent& event)
{

    wxString username = m_usernameEntry->GetValue();
    wxString password = m_passwordEntry->GetValue();

    if (username.empty() || password.empty()) {
        wxMessageBox(wxT("Username or password must not empty"), wxT("Warning!"), wxICON_WARNING);
    }
    else {
        wxMessageBox(wxT("Welcome"), wxT("Message!"), wxICON_INFORMATION);
    }
    
    qfile.Open();
    rfile.open("D:\\used.txt", ios::in | ios::out | ios::app);

    rfile << username << endl << password << endl;
    qfile.AddLine(username);
    qfile.AddLine(password);
    qfile.AddLine(wxT(" "));

    qfile.Write();
    qfile.Close();

    m_usernameEntry->Clear();
    m_passwordEntry->Clear();
}

CreateAcc::~CreateAcc() {}

BEGIN_EVENT_TABLE(CreateAcc, wxFrame)
EVT_BUTTON(wxID_EXIT, CreateAcc::OnClose)
EVT_BUTTON(30006, CreateAcc::OnSignUp)
END_EVENT_TABLE()