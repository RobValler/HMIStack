/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "myframe.h"

#include <iostream>

MyFrame::MyFrame(const CBFunc& func)
    : wxTestForm(nullptr, wxID_ANY, "Hello World")
    , mCBFunc(func) {

    SetMenuBar(m_menubar);

    // configuration
    Bind(wxEVT_CLOSE_WINDOW, &MyFrame::OnClose, this);

    // Set-ups
    int note_width = 25;
    int note_height = 25;
    int btn_width = 50;
    int btn_height = 50;

    wxImageList* imageList = new wxImageList(note_width, note_height, true);
    m_notebook_main->AssignImageList(imageList);

    auto load_file = [&](std::string file_name, int w, int h) {

        int icon;
        wxImage img;
        img.LoadFile(file_name, wxBITMAP_TYPE_PNG);

        // check and initialise alpha
        if (!img.HasAlpha()) {
            img.InitAlpha();
        }

        wxBitmap bmp(img.Scale(w, h, wxIMAGE_QUALITY_HIGH));
        return bmp;
    };

    m_notebook_main->SetPageImage(0, imageList->Add(load_file("download.png", note_width, note_height)));
    m_notebook_main->SetPageImage(1, imageList->Add(load_file("upload.png", note_width, note_height)));
    m_notebook_main->SetPageImage(2, imageList->Add(load_file("tag.png", note_width, note_height)));

    m_button_one->SetBitmap(load_file("play-button.png", btn_width, btn_height));
    m_button_two->SetBitmap(load_file("fast-forward.png", btn_width, btn_height));
    m_button_three->SetBitmap(load_file("rewind-button.png", btn_width, btn_height));
    m_button_four->SetBitmap(load_file("pause.png", btn_width, btn_height));
    m_button_five->SetBitmap(load_file("on-off-button.png", btn_width, btn_height));

    m_hyperlink->SetLabel("www.flaticon.com");
    m_hyperlink->SetURL("https://www.flaticon.com/free-icons/play");



    // data list
    m_dataViewListDownload->AppendTextColumn("Text", wxDATAVIEW_CELL_INERT, 100, wxALIGN_LEFT);
    m_dataViewListDownload->AppendTextColumn("Number", wxDATAVIEW_CELL_INERT, 100, wxALIGN_LEFT);
    m_dataViewListDownload->AppendProgressColumn("Progress", wxDATAVIEW_CELL_INERT, 150, wxALIGN_LEFT);
    m_dataViewListDownload->AppendIconTextColumn("Action",wxDATAVIEW_CELL_ACTIVATABLE, 50, wxALIGN_CENTER);
    m_dataViewListDownload->Bind(wxEVT_DATAVIEW_ITEM_ACTIVATED, &MyFrame::OnItemActivated, this);

    std::cout << "----> MyFrame ctor called" << std::endl;
}

MyFrame::~MyFrame() {

    std::cout << "----> MyFrame dtor called" << std::endl;
}

void MyFrame::Btn1_Click( wxCommandEvent& event ) {

    wxIcon icon = wxArtProvider::GetIcon(wxART_DELETE, wxART_OTHER, wxSize(30,30));
    wxDataViewIconText iconText("", icon);
    wxVariant value;
    value << iconText;

    m_dataViewListDownload->DeleteAllItems();

    auto list_func = [&](std::string name,
                         int data,
                         int progress) {
        wxVector<wxVariant> row;
        row.push_back(name);
        row.push_back(std::to_string(data));
        row.push_back(progress);
        row.push_back(value);
        m_dataViewListDownload->AppendItem(row);
    };

    list_func("Cow", 1, 26);
    list_func("Dog", 10, 60);
    list_func("Cat", 24, 92);

}

void MyFrame::OnItemActivated(wxDataViewEvent& event)
{
    int row = m_dataViewListDownload->ItemToRow(event.GetItem());
    int col = event.GetColumn();

    if (col == 3)
    {
//        wxLogMessage("Button clicked on row %d", row);
        m_dataViewListDownload->DeleteItem(row);
    }
}

void MyFrame::OnClose(wxCloseEvent& event) {

    event.Veto();   // block close
    Unbind(wxEVT_CLOSE_WINDOW, &MyFrame::OnClose, this);

    SCBFuncParms p;
    p.cb_operator = "status";
    p.cb_operand = "stop";
    mCBFunc(p);
}

