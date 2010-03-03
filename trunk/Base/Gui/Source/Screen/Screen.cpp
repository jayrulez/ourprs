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
#include "Screen.h"
#ifdef _WIN32
	#include "../../Win32/Core/Console.h"
#endif
Screen::Screen()
{
}
Screen::~Screen()
{
}
Screen::Screen(unsigned long ScreenColour,unsigned long TextColour)
{
    ConsoleObj.SetConsoleScreenColour(ScreenColour);
    this->ScreenColour=ScreenColour;
    ConsoleObj.SetTextAttribute(TextColour);
    this->TextColour=TextColour;
}
/*
    *
    *
    *
*/
void Screen::SetScreenColour(unsigned long ScreenColour)
{
    ConsoleObj.SetConsoleScreenColour(ScreenColour);
    this->ScreenColour=ScreenColour;
}
/*
    *
    *
    *
*/
void Screen::SetScreenTextColour(unsigned long TextColour)
{
    ConsoleObj.SetTextAttribute(TextColour);
    this->TextColour=TextColour;
}
/*
    *
    *
    *
*/
int Screen::GetScreenColour()const
{
    return this->ScreenColour;
}
void Screen::ClearScreen()
{
    ConsoleObj.FillConsoleOutput();
}
