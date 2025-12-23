///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-115-g11c2dec8)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxTestBase.h"

///////////////////////////////////////////////////////////////////////////

wxTestForm::wxTestForm( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 400,350 ), wxDefaultSize );
	this->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	m_menubar = new wxMenuBar( 0 );
	Menu = new wxMenu();
	wxMenuItem* exit;
	exit = new wxMenuItem( Menu, ID_EXIT, wxString( _("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	Menu->Append( exit );

	m_menubar->Append( Menu, _("Menu") );

	file = new wxMenu();
	wxMenuItem* Load;
	Load = new wxMenuItem( file, wxID_ANY, wxString( _("Load") ) , wxEmptyString, wxITEM_NORMAL );
	file->Append( Load );

	wxMenuItem* save;
	save = new wxMenuItem( file, ID_SAVE, wxString( _("Save") ) , wxEmptyString, wxITEM_NORMAL );
	file->Append( save );

	wxMenuItem* defaultFile;
	defaultFile = new wxMenuItem( file, ID_DEFAULT_FILE, wxString( _("Default file") ) , wxEmptyString, wxITEM_NORMAL );
	file->Append( defaultFile );

	m_menubar->Append( file, _("File") );

	about = new wxMenu();
	wxMenuItem* preferences;
	preferences = new wxMenuItem( about, ID_PREFERENCES, wxString( _("Preferences") ) , wxEmptyString, wxITEM_NORMAL );
	about->Append( preferences );

	wxMenuItem* help;
	help = new wxMenuItem( about, ID_HELP, wxString( _("Help") ) , wxEmptyString, wxITEM_NORMAL );
	about->Append( help );

	m_menubar->Append( about, _("About") );

	this->SetMenuBar( m_menubar );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_staticText1 = new wxStaticText( this, wxID_ANY, _("This is a test application!"), wxDefaultPosition, wxSize( -1,60 ), 0 );
	m_staticText1->Wrap( -1 );
	m_staticText1->SetFont( wxFont( 20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer1->Add( m_staticText1, 0, wxALL|wxEXPAND, 5 );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer4->AddGrowableCol( 1 );
	fgSizer4->AddGrowableRow( 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	bSizer8->SetMinSize( wxSize( 150,-1 ) );
	m_button_one = new wxButton( this, wxID_ANY, wxEmptyString, wxPoint( -1,-1 ), wxSize( -1,80 ), 0 );
	bSizer8->Add( m_button_one, 0, wxALL|wxEXPAND, 5 );

	m_button_two = new wxButton( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,80 ), 0 );
	bSizer8->Add( m_button_two, 0, wxALL|wxEXPAND, 5 );

	m_button_three = new wxButton( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,80 ), 0 );
	bSizer8->Add( m_button_three, 0, wxALL|wxEXPAND, 5 );

	m_button_four = new wxButton( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,80 ), 0 );
	bSizer8->Add( m_button_four, 0, wxALL|wxEXPAND, 5 );

	m_button_five = new wxButton( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,80 ), 0 );
	bSizer8->Add( m_button_five, 0, wxALL|wxEXPAND, 5 );


	fgSizer4->Add( bSizer8, 5, wxEXPAND, 5 );

	m_notebook_main = new wxNotebook( this, wxID_ANY, wxPoint( -1,-1 ), wxSize( -1,-1 ), 0 );
	m_notebook_main->SetFont( wxFont( 15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	m_panel_download = new wxPanel( m_notebook_main, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_download->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_staticText2 = new wxStaticText( m_panel_download, wxID_ANY, _("Download"), wxDefaultPosition, wxSize( 200,40 ), 0 );
	m_staticText2->Wrap( -1 );
	m_staticText2->SetFont( wxFont( 20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer2->Add( m_staticText2, 0, wxALL, 5 );

	m_staticline3 = new wxStaticLine( m_panel_download, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer2->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );


	m_panel_download->SetSizer( bSizer2 );
	m_panel_download->Layout();
	bSizer2->Fit( m_panel_download );
	m_notebook_main->AddPage( m_panel_download, _("Download"), false );
	m_panel_upload = new wxPanel( m_notebook_main, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_staticText4 = new wxStaticText( m_panel_upload, wxID_ANY, _("Upload"), wxDefaultPosition, wxSize( 200,40 ), 0 );
	m_staticText4->Wrap( -1 );
	m_staticText4->SetFont( wxFont( 22, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer3->Add( m_staticText4, 0, wxALL, 5 );

	m_staticline5 = new wxStaticLine( m_panel_upload, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer3->Add( m_staticline5, 0, wxEXPAND | wxALL, 5 );


	m_panel_upload->SetSizer( bSizer3 );
	m_panel_upload->Layout();
	bSizer3->Fit( m_panel_upload );
	m_notebook_main->AddPage( m_panel_upload, _("Upload"), true );
	m_panel_attribute = new wxPanel( m_notebook_main, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	m_staticText3 = new wxStaticText( m_panel_attribute, wxID_ANY, _("Attribute"), wxDefaultPosition, wxSize( 200,40 ), 0 );
	m_staticText3->Wrap( -1 );
	m_staticText3->SetFont( wxFont( 20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer4->Add( m_staticText3, 0, wxALL, 5 );

	m_staticline4 = new wxStaticLine( m_panel_attribute, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer4->Add( m_staticline4, 0, wxEXPAND | wxALL, 5 );

	m_hyperlink = new wxHyperlinkCtrl( m_panel_attribute, wxID_ANY, _("link"), wxT("--"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	bSizer4->Add( m_hyperlink, 0, wxALL, 5 );


	m_panel_attribute->SetSizer( bSizer4 );
	m_panel_attribute->Layout();
	bSizer4->Fit( m_panel_attribute );
	m_notebook_main->AddPage( m_panel_attribute, _("Attributes"), false );

	fgSizer4->Add( m_notebook_main, 5, wxEXPAND | wxALL, 5 );


	bSizer1->Add( fgSizer4, 5, wxEXPAND, 5 );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_button1 = new wxButton( this, wxID_ANY, _("Button One"), wxDefaultPosition, wxSize( 150,80 ), 0 );
	m_button1->SetFont( wxFont( 16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	fgSizer1->Add( m_button1, 0, wxALL, 5 );

	m_button2 = new wxButton( this, wxID_ANY, _("Button Two"), wxDefaultPosition, wxSize( 150,80 ), 0 );
	m_button2->SetFont( wxFont( 16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	fgSizer1->Add( m_button2, 0, wxALL, 5 );


	bSizer1->Add( fgSizer1, 1, wxEXPAND, 5 );

	m_staticline6 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline6, 0, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_statusBar1 = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
	m_statusBar1->SetFont( wxFont( 25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );


	this->Centre( wxBOTH );

	// Connect Events
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxTestForm::Btn1_Click ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxTestForm::Btn1_Click ), NULL, this );
}

wxTestForm::~wxTestForm()
{
}
