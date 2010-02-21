#ifndef ABOUT_H
#define ABOUT_H
#include "../../../Core/Console.h"
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
