#include "Product.h"
#include <wx/wx.h>
#include "wx/textfile.h"
#include <fstream>

using namespace std;

wxTextFile pfile(wxT("D:\\products.txt"));

Product::Product(const wxString& title)
    : wxFrame((wxFrame*)NULL, wxID_ANY, title, wxPoint(wxID_ANY, wxID_ANY), wxSize(340, 150),
        wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX | wxCAPTION | wxCLIP_CHILDREN)
{
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer* hbox1 = new wxBoxSizer(wxHORIZONTAL);
    m_usernameLabel = new wxStaticText(panel, wxID_ANY, wxT("Product: "), wxDefaultPosition, wxSize(70, -1));
    hbox1->Add(m_usernameLabel, 0);

    m_usernameEntry = new wxTextCtrl(panel, wxID_ANY);
    hbox1->Add(m_usernameEntry, 1);
    vbox->Add(hbox1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    wxBoxSizer* hbox2 = new wxBoxSizer(wxHORIZONTAL);
    m_passwordLabel = new wxStaticText(panel, wxID_ANY, wxT("Product ID: "), wxDefaultPosition, wxSize(70, -1));
    hbox2->Add(m_passwordLabel, 0);

    m_passwordEntry = new wxTextCtrl(panel, wxID_ANY, wxString(""),
        wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
    hbox2->Add(m_passwordEntry, 1);
    vbox->Add(hbox2, 0, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, 10);

    wxBoxSizer* hbox3 = new wxBoxSizer(wxHORIZONTAL);
    m_buttonLogin = new wxButton(panel, 30006, wxT("Add Product"));
    hbox3->Add(m_buttonLogin);

    m_buttonQuit = new wxButton(panel, wxID_EXIT, ("Quit"));
    hbox3->Add(m_buttonQuit);
    vbox->Add(hbox3, 0, wxALIGN_RIGHT | wxTOP | wxRIGHT | wxBOTTOM, 10);

    panel->SetSizer(vbox);
    Centre();
}

void Product::OnQuit(wxCommandEvent& event)
{
    Close(true);
}

void Product::OnAdd(wxCommandEvent& event)
{

    wxString username = m_usernameEntry->GetValue();
    wxString password = m_passwordEntry->GetValue();

    if (username.empty() || password.empty()) {
        wxMessageBox(wxT("Must not empty"), wxT("Warning!"), wxICON_WARNING);
    }
    else {
        wxMessageBox(wxT("Added Succesfully"), wxT("Message!"), wxICON_INFORMATION);
    }

    pfile.Open();

    pfile.AddLine(username);
    pfile.AddLine(password);
    pfile.AddLine(wxT(" "));

    pfile.Write();
    pfile.Close();

    m_usernameEntry->Clear();
    m_passwordEntry->Clear();
}

Product::~Product() {}

BEGIN_EVENT_TABLE(Product, wxFrame)
EVT_BUTTON(wxID_EXIT, Product::OnQuit)
EVT_BUTTON(30006, Product::OnAdd)
END_EVENT_TABLE()