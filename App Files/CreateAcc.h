#pragma once
#include "wx/wx.h"
class CreateAcc : public wxFrame
{
public:
    CreateAcc(const wxString& title);

    // Destructor
    virtual ~CreateAcc();

private:
    wxStaticText* m_usernameLabel;
    wxStaticText* m_passwordLabel;
    wxTextCtrl* m_usernameEntry;
    wxTextCtrl* m_passwordEntry;
    wxButton* m_buttonSignUp;
    wxButton* m_buttonQuit;
    wxMessageDialog* dlg;

public:
    void OnClose(wxCommandEvent& event);
    void OnSignUp(wxCommandEvent& event);

public:
    DECLARE_EVENT_TABLE()

    enum
    {
        BUTTON_Login = wxID_HIGHEST + 1
    };
};
