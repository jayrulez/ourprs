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
#ifndef HELP_H
#define HELP_H
#include <iostream>
#include <string>
#include "../../../Tools/Frame.h"
#ifdef _WIN32
	#include "../../../../Win32/Core/Console.h"
#endif
#include "../../../Screen/Screen.h"

#define ON 1
#define OFF 2
#define MENU_TITLE_JOINT 194
using namespace std;

class Help
{
private:
	Frame TitleFrameObj;
	Frame FrameObj;
	Console ConsoleObj;
	Screen ScreenObj;
	string MenuTitle;
public:
	Help();
	~Help();
	bool SetHelpMenu();
	void ShowHelpMenuTitle(int);
	void ShowHelpInfo(int);
	void ShowHelpMenu();
};
#endif
