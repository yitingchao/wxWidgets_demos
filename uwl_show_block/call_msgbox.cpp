// For compilers that support precompilation, includes "wx/wx.h".
#ifdef __BORLANDC__
    #pragma hdrstop
#endif

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include <wx/app.h>
#include <wx/cmdline.h>


#include <stdio.h>
#include <stdlib.h>
 
char *denied_app = "NULL";

class MyApp : public wxApp
{
 
public:
    bool  OnInit ();
    int OnExit();
    int OnRun();

};


bool MyApp::OnInit()
{

    return true;

}
int MyApp::OnExit()
{
    return 0;
}


//all you want to do do it here:
int MyApp::OnRun()
{
    wxString warn_msg = "UWL is already block program: ";
    wxApp::CheckBuildOptions(WX_BUILD_OPTIONS_SIGNATURE, "program");
    printf("This is a line of text from console.\n");
    wxPrintf("Press any key to show a dialog..\n");
    //system("pause");

    //wxMessageBox(wxT("This is a window."));
    warn_msg += wxString(denied_app);
    wxMessageBox(warn_msg);

    wxPrintf("Press any key to continue...\n");
    //system("pause");

    wxPrintf("This is a line of text from console using wxPrintf\n");
    //system("pause");
    return 0;
}
int main(int argc,char* argv[])
{
    wxInitializer init;
    if(!init)
    {
        fprintf(stderr,"failed to init wx.abort.\n");
        return -1;
    }

    MyApp* app=new MyApp();

    if(argc==2)
        denied_app = argv[1];

    wxApp::SetInstance(app);
    wxEntryStart( argc, argv );
    //nothing need to write here.

    return wxEntry(argc,argv);
}
