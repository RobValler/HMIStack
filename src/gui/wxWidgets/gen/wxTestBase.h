///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-115-g11c2dec8)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/notebook.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class wxTestForm
///////////////////////////////////////////////////////////////////////////////
class wxTestForm : public wxFrame
{
	private:

	protected:
		wxMenuBar* m_menubar2;
		wxStaticText* m_staticText1;
		wxButton* m_button8;
		wxButton* m_button7;
		wxButton* m_button6;
		wxNotebook* m_notebook_main;
		wxPanel* m_panel1;
		wxStaticText* m_staticText2;
		wxPanel* m_panel2;
		wxPanel* m_panel3;
		wxButton* m_button1;
		wxButton* m_button22;
		wxStatusBar* m_statusBar1;

		// Virtual event handlers, override them in your derived class
		virtual void Btn1_Click( wxCommandEvent& event ) { event.Skip(); }


	public:

		wxTestForm( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1024,768 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~wxTestForm();

};

