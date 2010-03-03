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
#ifndef ABOUT_H
#define ABOUT_H
#ifdef _WIN32
	#include "../../../../Win32/Core/Console.h"
#endif
#include "../../../Tools/Frame.h"
#include "../../../Screen/Screen.h"
#define ON 1
#define OFF 2
#define MENU_TITLE_JOINT 194


#include <string>
using namespace std;

class About
{
private:
	Console ConsoleObj;
	Frame FrameObj;
	Frame TitleFrameObj;
	Screen ScreenObj;
	string MenuTitle;
public:
	About();
	~About();
	bool SetAboutMenu();
	void ShowAboutInfo();
	void ShowAboutMenuTitle(int);
	void ShowAboutMenu();
};
#endif
