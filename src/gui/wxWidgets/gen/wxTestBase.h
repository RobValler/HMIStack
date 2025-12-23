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
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/hyperlink.h>
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
		wxMenuBar* m_menubar;
		wxStaticText* m_staticText1;
		wxStaticLine* m_staticline1;
		wxButton* m_button_one;
		wxButton* m_button_two;
		wxButton* m_button_three;
		wxButton* m_button_four;
		wxButton* m_button_five;
		wxNotebook* m_notebook_main;
		wxPanel* m_panel_download;
		wxStaticText* m_staticText2;
		wxStaticLine* m_staticline3;
		wxPanel* m_panel_upload;
		wxStaticText* m_staticText4;
		wxStaticLine* m_staticline5;
		wxPanel* m_panel_attribute;
		wxStaticText* m_staticText3;
		wxStaticLine* m_staticline4;
		wxHyperlinkCtrl* m_hyperlink;
		wxButton* m_button1;
		wxButton* m_button2;
		wxStaticLine* m_staticline6;
		wxStatusBar* m_statusBar1;

		// Virtual event handlers, override them in your derived class
		virtual void Btn1_Click( wxCommandEvent& event ) { event.Skip(); }


	public:

		wxTestForm( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1024,768 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~wxTestForm();

};

