/***************************************************************
 * Name:      YouAreHackedMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     YiTing (yi-ting.chao@itri.org.tw)
 * Created:   2018-01-07
 * Copyright:  YiTing ()
 * License:
 **************************************************************/

#include "YouAreHackedMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(YouAreHackedFrame)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(YouAreHackedFrame)
const long YouAreHackedFrame::ID_STATICBITMAP1 = wxNewId();
const long YouAreHackedFrame::ID_PANEL1 = wxNewId();
const long YouAreHackedFrame::idMenuQuit = wxNewId();
const long YouAreHackedFrame::idMenuAbout = wxNewId();
const long YouAreHackedFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(YouAreHackedFrame,wxFrame)
    //(*EventTable(YouAreHackedFrame)
    //*)
END_EVENT_TABLE()

YouAreHackedFrame::YouAreHackedFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(YouAreHackedFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(565,377));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(400,336), wxSize(560,377), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/jackend/tmp/YouAreHacked/12035-hacked_article.jpg"))), wxPoint(0,0), wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&HowToAvoidThisSituation\?"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("&NeedHelp\?"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&YouAreHackedFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&YouAreHackedFrame::OnAbout);
    //*)
}

YouAreHackedFrame::~YouAreHackedFrame()
{
    //(*Destroy(YouAreHackedFrame)
    //*)
}

void YouAreHackedFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void YouAreHackedFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
