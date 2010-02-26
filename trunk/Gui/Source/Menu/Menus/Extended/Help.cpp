/*
@Group: BSC2D
@Group Members:
	<ul>
		<li>Robert Campbell: 0701334</li>
		<li>Audley Gordon: 0802218</li>
		<li>Dale McFarlane: 0801042</li>
		<li>Dyonne Duberry: 0802189</li>
	</ul>
@
*/
#include "Help.h"
#include <iostream>
#include <string>
#include "../../../Tools/Colour.h"
using namespace std;

Help::Help()
{
    this->MenuTitle="Help";
}
Help::~Help()
{
}

bool Help::SetHelpMenu()
{
    this->MenuTitle="Help";
    return true;
}
void Help::ShowHelpMenuTitle(int status)
{
    if(!status)
        ScreenObj.SetScreenTextColour(DefaultBgColour);
    else
        ScreenObj.SetScreenTextColour(DefaultTextColour);
    int TitleLength=MenuTitle.length();
    int x1=(STANDARD_FRAME_WIDTH/2)-(TitleLength/2);
    int x2=(STANDARD_FRAME_WIDTH/2)+(TitleLength/2);
    if(TitleFrameObj.SetFrame(x1-1,x2+2,2,4,NORMAL_FRAME))
    {
        TitleFrameObj.sFraming();
        ConsoleObj.xyCoord(x1-1,2);
        cout<<(unsigned char)MENU_TITLE_JOINT;
        ConsoleObj.xyCoord(x2+2,2);
        cout<<(unsigned char)MENU_TITLE_JOINT;
        ConsoleObj.xyCoord(x1+1,3);
        cout<<MenuTitle;
    }
    ScreenObj.SetScreenTextColour(DefaultTextColour);
}
void Help::ShowHelpMenu()
{
    ConsoleObj.xyCoord(1,STANDARD_FRAME_HEIGHT-1);
    cout<<"[F1] - Help";
}
void Help::ShowHelpInfo()
{
	//cout<<"HELP";
}
