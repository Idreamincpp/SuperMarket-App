#include "FormLogin.h"
#include <iostream>
#include <fstream>
#include <wx/wx.h>
#include <string>
#include <wx/textfile.h>

using namespace std;

FormLogin::FormLogin(const wxString& title)
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
    m_buttonLogin = new wxButton(panel, BUTTON_Login, wxT("Login"));
    hbox3->Add(m_buttonLogin);

    m_buttonQuit = new wxButton(panel, wxID_EXIT, ("Quit"));
    hbox3->Add(m_buttonQuit);
    vbox->Add(hbox3, 0, wxALIGN_RIGHT | wxTOP | wxRIGHT | wxBOTTOM, 10);

    panel->SetSizer(vbox);
    Centre();
}

void FormLogin::OnQuit(wxCommandEvent& event)
{
    Close(true);
}

void FormLogin::OnLogin(wxCommandEvent& event)
{

    wxString username = m_usernameEntry->GetValue();
    wxString password = m_passwordEntry->GetValue();

    if (username.empty() || password.empty()) {
        wxMessageBox(wxT("Username or password must not be empty"), wxT("Warning!"), wxICON_WARNING);
    }
    else {
        fstream cfile;
        cfile.open("D:\\used.txt", ios::in);

        size_t pos;
        string line;
        string code;

        string search;

        username = search;
        password = code;

        if (cfile.is_open())
        {
            while (getline(cfile, line))
            {
                pos = line.find(search);
                if (pos != string::npos) // string::npos is returned if string is not found
                {

                    break;
                }
                else {
                    wxMessageBox("Username not found");
                }
            }
            while (getline(cfile, code))
            {
                if (pos != string::npos)
                {
                    break;
                }
                else {
                    wxMessageBox("Password not found");
                }
            }


            m_usernameEntry->Clear();
            m_passwordEntry->Clear();
        }
    }
}

FormLogin::~FormLogin() {}

BEGIN_EVENT_TABLE(FormLogin, wxFrame)
EVT_BUTTON(wxID_EXIT, FormLogin::OnQuit)
EVT_BUTTON(BUTTON_Login, FormLogin::OnLogin)
END_EVENT_TABLE()