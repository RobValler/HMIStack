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
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_button1 = new wxButton( this, wxID_ANY, _("Button One"), wxDefaultPosition, wxSize( 150,80 ), 0 );
	bSizer1->Add( m_button1, 0, wxALL, 5 );

	m_button2 = new wxButton( this, wxID_ANY, _("Button Two"), wxDefaultPosition, wxSize( 150,80 ), 0 );
	bSizer1->Add( m_button2, 0, wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_menubar2 = new wxMenuBar( 0 );
	this->SetMenuBar( m_menubar2 );

	m_statusBar1 = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

	this->Centre( wxBOTH );

	// Connect Events
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxTestForm::Btn1_Click ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxTestForm::Btn1_Click ), NULL, this );
}

wxTestForm::~wxTestForm()
{
}
