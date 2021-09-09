#pragma once

#include "wx/wx.h"

class Product : public wxFrame
{
public:
    Product(const wxString& title);

    // Destructor
    virtual ~Product();

private:
    wxStaticText* m_usernameLabel;
    wxStaticText* m_passwordLabel;
    wxTextCtrl* m_usernameEntry;
    wxTextCtrl* m_passwordEntry;
    wxButton* m_buttonLogin;
    wxButton* m_buttonQuit;
    wxMessageDialog* dlg;

private:
    void OnQuit(wxCommandEvent& event);
    void OnAdd(wxCommandEvent& event);

private:
    DECLARE_EVENT_TABLE()

    enum
    {
        BUTTON_Login = wxID_HIGHEST + 1
    };
};