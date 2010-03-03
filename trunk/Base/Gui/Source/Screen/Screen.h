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
#ifndef SCREEN_H
#define SCREEN_H
#ifdef _WIN32
	#include "../../Win32/Core/Console.h"
#endif


class Screen
{
private:
    unsigned long ScreenColour;
    unsigned long TextColour;
    Console ConsoleObj;
public:
    Screen();
    ~Screen();
    Screen(unsigned long,unsigned long);
    void SetScreenColour(unsigned long);
    void SetScreenTextColour(unsigned long);
    int GetScreenColour()const;
    void ClearScreen();
};

#endif
