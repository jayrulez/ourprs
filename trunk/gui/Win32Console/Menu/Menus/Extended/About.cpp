#include "About.h"
#include "../../../Tools/Frame.h"
#include "../../../Tools/Colour.h"
#include <iostream>
#include <string>
using namespace std;

About::About()
{
    this->MenuTitle="About SSN Payroll Management System";
}

About::~About()
{
}

bool About::SetAboutMenu()
{
    this->MenuTitle="About SSN Payroll Management System";
    return true;
}
void About::ShowAboutMenuTitle(int status)
{
    if(!status)
        ScreenObj.SetScreenTextColour(ConsoleObj.GetConsoleScreenColour()+3);
    int TitleLength=MenuTitle.length();
    int x1=(STANDARD_FRAME_WIDTH/2)-(TitleLength/2);
    int x2=(STANDARD_FRAME_WIDTH/2)+(TitleLength/2);
    if(TitleFrameObj.SetFrame(x1-1,x2+1,2,4,NORMAL_FRAME))
    {
        TitleFrameObj.sFraming();
        ConsoleObj.xyCoord(x1-1,2);
        cout<<(unsigned char)MENU_TITLE_JOINT;
        ConsoleObj.xyCoord(x2+1,2);
        cout<<(unsigned char)MENU_TITLE_JOINT;
        ConsoleObj.xyCoord(x1,3);
        cout<<MenuTitle;
    }
     ScreenObj.SetScreenTextColour(DefaultTextColour);
}
void About::ShowAboutMenu()
{
    ConsoleObj.xyCoord(STANDARD_FRAME_WIDTH-13,STANDARD_FRAME_HEIGHT-1);
    cout<<"[F3] - About";
}
void About::ShowAboutInfo()
{
    FrameObj.CenteredSFraming(66,32);
    ConsoleObj.xyCoord(9,15);
	cout<<"Name    : Simple Solutions Now (SSN) Payroll Management System";
	ConsoleObj.xyCoord(9,16);
	cout<<"Version : 1.00";

	ConsoleObj.xyCoord(9,20);
	cout<<"Unauthorized reproduction or destribution of this program,";
	ConsoleObj.xyCoord(9,21);
	cout<<"or any portion of it, may result in severe civil penalties,";
	ConsoleObj.xyCoord(9,22);
	cout<<"and will be prosecuted to the maximum extent under the law.";

    ConsoleObj.xyCoord(9,26);
	cout<<"Developers:";
	ConsoleObj.xyCoord(9,27);
    cout<<"----------------------------------";
    ConsoleObj.xyCoord(9,29);
    cout<<"Robert Campbell       : Developer";
    ConsoleObj.xyCoord(9,30);
    cout<<"Dyonne Dubbery        : Developer";
    ConsoleObj.xyCoord(9,31);
    cout<<"Audley Gordon         : Developer";
    ConsoleObj.xyCoord(9,32);
    cout<<"Dale McFarlane        : Developer";
}

