#ifndef SERVICES_H
#define SERVICES_H

#include "../Menu/Menus/Extended/About.h"
#include "../Menu/Menus/Extended/Help.h"
#include "../Tools/Frame.h"
#include "../Tools/Colour.h"
#include "../Screen/Screen.h"
#ifdef _WIN32
	#include "../../Win32/Core/Console.h"
    #include "../../Win32/Media/Media.h"
#endif
#include <string>

using namespace std;

class Services
{
private:
    Screen ScreenObj;
    Console ConsoleObj;
    Media MediaObj;
    Frame FrameObj;
    Help HelpObj;
    About AboutObj;

public:
	Services();
	~Services();
	void BasicRunLevel();
	void SystemTitle();
	void SystemClearScreen();
	void SystemChangeScreen();
	void SizeConsoleWindow();
	void SystemChangeScreenSound();
	void Title(string);
};
#endif
