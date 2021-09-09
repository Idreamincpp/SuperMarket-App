#pragma once
#include "wx/wx.h"

/*

░█████╗░███╗░░░███╗░█████╗░██╗███╗░░██╗░░░██╗░░██╗
██╔══██╗████╗░████║██╔══██╗██║████╗░██║░░░██║░░██║
██║░░╚═╝██╔████╔██║███████║██║██╔██╗██║░░░███████║
██║░░██╗██║╚██╔╝██║██╔══██║██║██║╚████║░░░██╔══██║
╚█████╔╝██║░╚═╝░██║██║░░██║██║██║░╚███║██╗██║░░██║
░╚════╝░╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═╝╚═╝░░╚══╝╚═╝╚═╝░░╚═╝
*/

class Openfile : public wxFrame
{
public:
	Openfile(const wxString& title);

	void OnOpen(wxCommandEvent& event);


};

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();


public:
	wxButton* m_btn1 = nullptr;
	wxMenuBar* m_menu;
	wxMenu* fileMenu;
	wxPanel* m_panel1 = nullptr;

	void OnButtonClicked(wxCommandEvent& evt);
	void OnSales(wxCommandEvent& evt);
	void OnHistory(wxCommandEvent& evt);
	void OnProducts(wxCommandEvent& evt);
	void OnSuppliers(wxCommandEvent& evt);
	void OnUsers(wxCommandEvent& evt);
	void OnAddUser(wxCommandEvent& evt);
	void OnStatistics(wxCommandEvent& evt);
	void OnHelp(wxCommandEvent& evt);


	wxDECLARE_EVENT_TABLE();

};

