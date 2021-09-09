#include "cMain.h"
#include <iostream>
#include <fstream>
#include "wx/image.h"
#include "wx/bitmap.h"
#include  "wx/toolbar.h"
#include "wx/grid.h"
#include "wx/textfile.h"
#include <string>
#include "FormLogin.h"
#include "CreateAcc.h"
#include "BaseFrame.h"
#include "Supplier.h"
#include "Product.h"


/*
░█████╗░███╗░░░███╗░█████╗░██╗███╗░░██╗░░░░█████╗░██████╗░██████╗░
██╔══██╗████╗░████║██╔══██╗██║████╗░██║░░░██╔══██╗██╔══██╗██╔══██╗
██║░░╚═╝██╔████╔██║███████║██║██╔██╗██║░░░██║░░╚═╝██████╔╝██████╔╝
██║░░██╗██║╚██╔╝██║██╔══██║██║██║╚████║░░░██║░░██╗██╔═══╝░██╔═══╝░
╚█████╔╝██║░╚═╝░██║██║░░██║██║██║░╚███║██╗╚█████╔╝██║░░░░░██║░░░░░
░╚════╝░╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═╝╚═╝░░╚══╝╚═╝░╚════╝░╚═╝░░░░░╚═╝░░░░░
*/


wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_BUTTON(10001, OnButtonClicked)
EVT_TOOL(10002, cMain::OnSales)
EVT_TOOL(10003, cMain::OnHistory)
EVT_TOOL(10004, cMain::OnProducts)
EVT_TOOL(10005, cMain::OnSuppliers)
EVT_TOOL(10006, cMain::OnUsers)
EVT_TOOL(10007, cMain::OnAddUser)
EVT_TOOL(10008, cMain::OnStatistics)
EVT_TOOL(wxID_HELP, cMain::OnHelp)
wxEND_EVENT_TABLE()

using namespace std;

wxTextFile file(wxT("D:\kile.txt"));

bool checkEmptyString(const string& s)
{
	return s.size() == 0;
}

wxGrid* grid = nullptr;

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Supermarket Application", wxPoint(0, 0), wxSize(1460, 600))
{
	//*************************************************************************	

	grid = new wxGrid(this,
		-1,
		wxPoint(0, 126),
		wxSize(1000, 1000));

	//createGrid to set the dimensions of the grid
	grid->CreateGrid(13, 11);

	//sizing all rows to 30
	grid->SetRowSize(0, 30);
	grid->SetRowSize(1, 30);
	grid->SetRowSize(2, 30);
	grid->SetRowSize(3, 30);
	grid->SetRowSize(4, 30);
	grid->SetRowSize(5, 30);
	grid->SetRowSize(6, 30);
	grid->SetRowSize(7, 30);
	grid->SetRowSize(8, 30);
	grid->SetRowSize(9, 30);
	grid->SetRowSize(10, 30);
	grid->SetRowSize(11, 30);
	grid->SetRowSize(12, 30);


	//individually sizing columns 
	grid->SetColSize(3, 250);
	grid->SetColSize(1, 150);
	grid->SetColSize(7, 120);
	grid->SetColSize(8, 150);
	grid->SetColSize(9, 300);
	grid->SetColSize(10, 100);
	grid->SetColSize(0, 0);

	//Creating custom labels
	grid->SetColLabelValue(1, wxT("Item ID"));
	grid->SetColLabelValue(2, wxT("Time"));
	grid->SetColLabelValue(3, wxT("Order"));
	grid->SetColLabelValue(4, wxT("Quantity"));
	grid->SetColLabelValue(5, wxT("Units"));
	grid->SetColLabelValue(6, wxT("Profit"));
	grid->SetColLabelValue(7, wxT("Customer Name"));
	grid->SetColLabelValue(8, wxT("Customer Number"));
	grid->SetColLabelValue(9, wxT("Total"));
	grid->SetColLabelValue(10, wxT("Date"));

	//changing total values to Numbers
	grid->SetColFormatNumber(9);

	//*************************************************************************

		//creating toolbar
	wxToolBar* m_toolbarTemplate = CreateToolBar();

	//making bitmap tools
	wxBitmap m_bitmap;
	bool result = m_bitmap.LoadFile("shopping-cart-48.png", wxBITMAP_TYPE_PNG);

	wxBitmap m_bitmap2;
	bool result2 = m_bitmap2.LoadFile("paper-48.png", wxBITMAP_TYPE_PNG);

	wxBitmap m_bitmap3;
	bool result3 = m_bitmap3.LoadFile("package-2-48.png", wxBITMAP_TYPE_PNG);

	wxBitmap m_bitmap4;
	bool results4 = m_bitmap4.LoadFile("truck-48.png", wxBITMAP_TYPE_PNG);

	wxBitmap m_bitmap5;
	bool results5 = m_bitmap5.LoadFile("user-48.png", wxBITMAP_TYPE_PNG);

	wxBitmap m_bitmap6;
	bool results6 = m_bitmap6.LoadFile("add-user-48.png", wxBITMAP_TYPE_PNG);

	wxBitmap m_bitmap8;
	bool results8 = m_bitmap8.LoadFile("calculator-6-48.png", wxBITMAP_TYPE_PNG);

	wxBitmap m_bitmap7;
	bool results7 = m_bitmap7.LoadFile("help-48.png", wxBITMAP_TYPE_PNG);

	wxStaticText* txt;

	//*************************************************************************

	m_toolbarTemplate->SetToolBitmapSize(wxSize(90, 48));

	txt = new wxStaticText(m_toolbarTemplate, wxID_ANY, " Zeus Apps™ ", wxPoint(1100, 20), wxSize(700, 700));

	//toolbar buttons
	m_toolbarTemplate->AddTool(10002, _("Sales"), m_bitmap);
	m_toolbarTemplate->AddTool(10003, _("History"), m_bitmap2);
	m_toolbarTemplate->AddTool(10004, _("Products"), m_bitmap3);
	m_toolbarTemplate->AddTool(10005, _("Suppliers"), m_bitmap4);
	m_toolbarTemplate->AddTool(10006, _("Users"), m_bitmap5);
	m_toolbarTemplate->AddTool(10007, _("Add User"), m_bitmap6);
	m_toolbarTemplate->AddTool(10008, _("Statistics"), m_bitmap8);
	m_toolbarTemplate->AddTool(wxID_HELP, _("Help"), m_bitmap7);
	m_toolbarTemplate->AddSeparator();

	//help text
	m_toolbarTemplate->SetToolShortHelp(10002, _("Sales"));
	m_toolbarTemplate->SetToolShortHelp(10003, _("History"));
	m_toolbarTemplate->SetToolShortHelp(10004, _("Products"));
	m_toolbarTemplate->SetToolShortHelp(10005, _("Suppliers"));
	m_toolbarTemplate->SetToolShortHelp(10006, _("Users"));
	m_toolbarTemplate->SetToolShortHelp(10007, _("Add User"));
	m_toolbarTemplate->SetToolShortHelp(10008, _("Calculator"));
	m_toolbarTemplate->SetToolShortHelp(wxID_HELP, _("Help"));

	//realizing our toolbar
	m_toolbarTemplate->Realize();


	m_menu = new wxMenuBar();
	fileMenu = new wxMenu();

	//*************************************************************************

		//wxWidgets buttons
	fileMenu->Append(wxID_NEW);
	fileMenu->Append(wxID_OPEN);
	fileMenu->Append(wxID_SAVE);
	fileMenu->Append(wxID_CLOSE);

	m_menu->Append(fileMenu, _("&File"));
	SetMenuBar(m_menu);

	Connect(wxID_OPEN, wxEVT_COMMAND_MENU_SELECTED,
		wxCommandEventHandler(Openfile::OnOpen));

	Center();


	//*************************************************************************

		//Checkout button
	m_btn1 = new wxButton(this, 10001, "Checkout", wxPoint(1444, 0), wxSize(100, 500));

	//**************************************************************************
}

cMain::~cMain()
{
}

void cMain::OnButtonClicked(wxCommandEvent& evt)
{

	
	file.Open();

	//*************************************************************************

		//Saving Item ID's
	wxString id0 = grid->GetCellValue(0, 1);
	wxString id1 = grid->GetCellValue(1, 1);
	wxString id2 = grid->GetCellValue(2, 1);
	wxString id3 = grid->GetCellValue(3, 1);
	wxString id4 = grid->GetCellValue(4, 1);
	wxString id5 = grid->GetCellValue(5, 1);
	wxString id6 = grid->GetCellValue(6, 1);
	wxString id7 = grid->GetCellValue(7, 1);
	wxString id8 = grid->GetCellValue(8, 1);
	wxString id9 = grid->GetCellValue(9, 1);
	wxString id10 = grid->GetCellValue(10, 1);
	wxString id11 = grid->GetCellValue(11, 1);
	wxString id12 = grid->GetCellValue(12, 1);

	//*************************************************************************

		//Saving Time
	wxString time = grid->GetCellValue(1, 2);

	//*************************************************************************

		//Saving Orders
	wxString order0 = grid->GetCellValue(0, 3);
	wxString order1 = grid->GetCellValue(1, 3);
	wxString order2 = grid->GetCellValue(2, 3);
	wxString order3 = grid->GetCellValue(3, 3);
	wxString order4 = grid->GetCellValue(4, 3);
	wxString order5 = grid->GetCellValue(5, 3);
	wxString order6 = grid->GetCellValue(6, 3);
	wxString order7 = grid->GetCellValue(7, 3);
	wxString order8 = grid->GetCellValue(8, 3);
	wxString order9 = grid->GetCellValue(9, 3);
	wxString order10 = grid->GetCellValue(10, 3);
	wxString order11 = grid->GetCellValue(11, 3);
	wxString order12 = grid->GetCellValue(12, 3);

	//*************************************************************************

		//Saving Quantity
	wxString quan0 = grid->GetCellValue(0, 4);
	wxString quan1 = grid->GetCellValue(1, 4);
	wxString quan2 = grid->GetCellValue(2, 4);
	wxString quan3 = grid->GetCellValue(3, 4);
	wxString quan4 = grid->GetCellValue(4, 4);
	wxString quan5 = grid->GetCellValue(5, 4);
	wxString quan6 = grid->GetCellValue(6, 4);
	wxString quan7 = grid->GetCellValue(7, 4);
	wxString quan8 = grid->GetCellValue(8, 4);
	wxString quan9 = grid->GetCellValue(9, 4);
	wxString quan10 = grid->GetCellValue(10, 4);
	wxString quan11 = grid->GetCellValue(11, 4);
	wxString quan12 = grid->GetCellValue(12, 4);

	//*************************************************************************

		//Saving Units
	wxString unit0 = grid->GetCellValue(0, 5);
	wxString unit1 = grid->GetCellValue(1, 5);
	wxString unit2 = grid->GetCellValue(2, 5);
	wxString unit3 = grid->GetCellValue(3, 5);
	wxString unit4 = grid->GetCellValue(4, 5);
	wxString unit5 = grid->GetCellValue(5, 5);
	wxString unit6 = grid->GetCellValue(6, 5);
	wxString unit7 = grid->GetCellValue(7, 5);
	wxString unit8 = grid->GetCellValue(8, 5);
	wxString unit9 = grid->GetCellValue(9, 5);
	wxString unit10 = grid->GetCellValue(10, 5);
	wxString unit11 = grid->GetCellValue(11, 5);
	wxString unit12 = grid->GetCellValue(12, 5);

	//***************************************************************************

		//Saving Profits
	wxString prof0 = grid->GetCellValue(0, 6);
	wxString prof1 = grid->GetCellValue(1, 6);
	wxString prof2 = grid->GetCellValue(2, 6);
	wxString prof3 = grid->GetCellValue(3, 6);
	wxString prof4 = grid->GetCellValue(4, 6);
	wxString prof5 = grid->GetCellValue(5, 6);
	wxString prof6 = grid->GetCellValue(6, 6);
	wxString prof7 = grid->GetCellValue(7, 6);
	wxString prof8 = grid->GetCellValue(8, 6);
	wxString prof9 = grid->GetCellValue(9, 6);
	wxString prof10 = grid->GetCellValue(10, 6);
	wxString prof11 = grid->GetCellValue(11, 6);
	wxString prof12 = grid->GetCellValue(12, 6);

	//****************************************************************************
	
		//Saving Customer Information
	wxString cusname = grid->GetCellValue(0, 7);

	wxString cusnum = grid->GetCellValue(0, 8);

	//*****************************************************************************

		//Saving Date
	wxString date = grid->GetCellValue(0, 10);

	//*******************************************************************************

	
	file.AddLine(wxT("********************************************************"));
	file.AddLine(time + wxT(" ") + date);
	file.AddLine(cusname + wxT(" ") + cusnum);
	file.AddLine(id0 + wxT(" - ") + order0 + wxT(" ") + quan0 + wxT(" ") + unit0);
	file.AddLine(id1 + wxT(" - ") + order1 + wxT(" ") + quan1 + wxT(" ") + unit1);
	file.AddLine(id2 + wxT(" - ") + order2 + wxT(" ") + quan2 + wxT(" ") + unit2);
	file.AddLine(id3 + wxT(" - ") + order3 + wxT(" ") + quan3 + wxT(" ") + unit3);
	file.AddLine(id4 + wxT(" - ") + order4 + wxT(" ") + quan4 + wxT(" ") + unit4);
	file.AddLine(id5 + wxT(" - ") + order5 + wxT(" ") + quan5 + wxT(" ") + unit5);
	file.AddLine(id6 + wxT(" - ") + order6 + wxT(" ") + quan6 + wxT(" ") + unit6);
	file.AddLine(id7 + wxT(" - ") + order7 + wxT(" ") + quan7 + wxT(" ") + unit7);
	file.AddLine(id8 + wxT(" - ") + order8 + wxT(" ") + quan8 + wxT(" ") + unit8);
	file.AddLine(id9 + wxT(" - ") + order9 + wxT(" ") + quan9 + wxT(" ") + unit9);
	file.AddLine(id10 + wxT(" - ") + order10 + wxT(" ") + quan10 + wxT(" ") + unit10);
	file.AddLine(id11 + wxT(" - ") + order11 + wxT(" ") + quan11 + wxT(" ") + unit11);
	file.AddLine(id12 + wxT(" - ") + order12 + wxT(" ") + quan12 + wxT(" ") + unit12);
	file.AddLine(wxT("********************************************************"));
	file.AddLine(wxT(" "));

	file.Write();
	file.Close();
	grid->ClearGrid();
	evt.Skip();
}

void cMain::OnSales(wxCommandEvent& evt)
{
	wxMessageBox("ERR_R CODE: 256");
	evt.Skip();
}

void cMain::OnHistory(wxCommandEvent& evt)
{
	wxMessageBox("Check D:\\\kile.txt, and view the history");
	evt.Skip();
}

void cMain::OnProducts(wxCommandEvent& evt)
{
	Product* prod = new Product(wxT("Prod Menu"));
	prod->Show(true);
	evt.Skip();
}

void cMain::OnSuppliers(wxCommandEvent& evt)
{
	Supplier* supp = new Supplier(wxT("Supplier Menu"));
	supp->Show(true);
	evt.Skip();
}

void cMain::OnUsers(wxCommandEvent& evt)
{
	FormLogin* formLogin = new FormLogin(wxT("User Menu"));
	formLogin->Show(true);
	evt.Skip();
}

void cMain::OnAddUser(wxCommandEvent& evt)
{
	CreateAcc* Create = new CreateAcc(wxT("Add user"));
	Create->Show(true);
	evt.Skip();
}

void cMain::OnStatistics(wxCommandEvent& evt)
{
	BaseFrame* base_frame = new BaseFrame(wxT("Calculator"));

	base_frame->Show(true);
	evt.Skip();
}

void cMain::OnHelp(wxCommandEvent& evt)
{
	wxMessageBox("Please refer to the guide given along with the software.");
	evt.Skip();
}

void Openfile::OnOpen(wxCommandEvent& event)
{
	wxString str;

	wxFileDialog* openFileDialog = new wxFileDialog(this);

	if (openFileDialog->ShowModal() == wxID_OK) {
		wxString fileName = openFileDialog->GetPath();
		//tc->LoadFile(fileName);
		wxMessageBox("Unable to open file"); //lol

	}
	else {
		wxMessageBox("Action Failed");
	}
}

