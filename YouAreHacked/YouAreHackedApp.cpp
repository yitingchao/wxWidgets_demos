/***************************************************************
 * Name:      YouAreHackedApp.cpp
 * Purpose:   Code for Application Class
 * Author:     YiTing (yi-ting.chao@itri.org.tw)
 * Created:   2018-01-07
 * Copyright:  YiTing ()
 * License:
 **************************************************************/

#include "YouAreHackedApp.h"

//(*AppHeaders
#include "YouAreHackedMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(YouAreHackedApp);

bool YouAreHackedApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	YouAreHackedFrame* Frame = new YouAreHackedFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
