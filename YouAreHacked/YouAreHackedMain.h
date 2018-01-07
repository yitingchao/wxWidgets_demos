/***************************************************************
 * Name:      YouAreHackedMain.h
 * Purpose:   Defines Application Frame
 * Author:     YiTing (yi-ting.chao@itri.org.tw)
 * Created:   2018-01-07
 * Copyright:  YiTing ()
 * License:
 **************************************************************/

#ifndef YOUAREHACKEDMAIN_H
#define YOUAREHACKEDMAIN_H

//(*Headers(YouAreHackedFrame)
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/statbmp.h>
//*)

class YouAreHackedFrame: public wxFrame
{
    public:

        YouAreHackedFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~YouAreHackedFrame();

    private:

        //(*Handlers(YouAreHackedFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(YouAreHackedFrame)
        static const long ID_STATICBITMAP1;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(YouAreHackedFrame)
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxStaticBitmap* StaticBitmap1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // YOUAREHACKEDMAIN_H
