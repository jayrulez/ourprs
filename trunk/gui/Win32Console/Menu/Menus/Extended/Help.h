#ifndef HELP_H
#define HELP_H
#include <iostream>
#include <string>
#include "../../../Tools/Frame.h"
#include "../../../Core/Console.h"
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
	void ShowHelpInfo();
	void ShowHelpMenu();
};
#endif
