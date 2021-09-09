#include "cApp.h"
#include "cMain.h"
#include <iostream>

/*
░█████╗░░█████╗░██████╗░██████╗░░░░░█████╗░██████╗░██████╗░
██╔══██╗██╔══██╗██╔══██╗██╔══██╗░░░██╔══██╗██╔══██╗██╔══██╗
██║░░╚═╝███████║██████╔╝██████╔╝░░░██║░░╚═╝██████╔╝██████╔╝
██║░░██╗██╔══██║██╔═══╝░██╔═══╝░░░░██║░░██╗██╔═══╝░██╔═══╝░
╚█████╔╝██║░░██║██║░░░░░██║░░░░░██╗╚█████╔╝██║░░░░░██║░░░░░
░╚════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝░░░░░╚═╝░╚════╝░╚═╝░░░░░╚═╝░░░░░
*/

wxIMPLEMENT_APP(cApp);

cApp::cApp()
{
}

cApp::~cApp()
{
}

bool cApp::OnInit()
{

	wxInitAllImageHandlers();


	// Show the frame as it's created initially hidden.

	m_frame1 = new cMain();
	m_frame1->SetBackgroundColour(*wxLIGHT_GREY);
	m_frame1->Show();


	return true;
}