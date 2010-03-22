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
        ScreenObj.SetScreenTextColour(DefaultBgColour);
    else
        ScreenObj.SetScreenTextColour(DefaultTextColour);
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
    FrameObj.CenteredSFraming(72,38);
    ConsoleObj.xyCoord(6,12);
	cout<<"Name    : Simple Solutions Now (SSN) Payroll Management System";
	ConsoleObj.xyCoord(6,13);
	cout<<"Version : 1.00";

	ConsoleObj.xyCoord(6,17);
    cout<<"Copyright © 2008-2009 by SocialCMS LLC (http://www.socialcms.org)";
    ConsoleObj.xyCoord(6,18);
    cout<<"All rights reserved.";

    ConsoleObj.xyCoord(6,20);
    cout<<"Redistribution and use in source and binary forms, with or without";
    ConsoleObj.xyCoord(6,21);
    cout<<"modification, are permitted provided that the following conditions";
    ConsoleObj.xyCoord(6,22);
    cout<<"are met:";
    ConsoleObj.xyCoord(6,23);
    cout<<" * Redistributions of source code must retain the above copyright";
    ConsoleObj.xyCoord(6,24);
    cout<<"   notice, this list of conditions and the following disclaimer.";
    ConsoleObj.xyCoord(6,25);
    cout<<" * Redistributions in binary form must reproduce the above copyright";
    ConsoleObj.xyCoord(6,26);
    cout<<"   notice, this list of conditions and the following disclaimer in";
    ConsoleObj.xyCoord(6,27);
    cout<<"   the documentation and/or other materials provided with the";
    ConsoleObj.xyCoord(6,28);
    cout<<"   distribution.";
    ConsoleObj.xyCoord(6,29);
    cout<<" * Neither the name of Yii Software LLC nor the names of its";
    ConsoleObj.xyCoord(6,30);
    cout<<"   contributors may be used to endorse or promote products derived";
    ConsoleObj.xyCoord(6,31);
    cout<<"   from this software without specific prior written permission.";

    ConsoleObj.xyCoord(6,35);
	cout<<"Developers:";
	ConsoleObj.xyCoord(6,36);
    cout<<"----------------------------------";
    ConsoleObj.xyCoord(6,37);
    cout<<"Robert Campbell       : Developer";
    ConsoleObj.xyCoord(6,38);
    cout<<"Dyonne Dubbery        : Developer";
    ConsoleObj.xyCoord(6,39);
    cout<<"Audley Gordon         : Developer";
    ConsoleObj.xyCoord(6,40);
    cout<<"Dale McFarlane        : Developer";
}

