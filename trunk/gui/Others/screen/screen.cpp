#include "screen.h"

screen::screen()
{
}
screen::~screen()
{
}
screen::screen(unsigned long ScreenColour,unsigned long TextColour)
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
void screen::SetScreenColour(unsigned long ScreenColour)
{
    ConsoleObj.SetConsoleScreenColour(ScreenColour);
    this->ScreenColour=ScreenColour;
}
/*
    *
    *
    *
*/
void screen::SetScreenTextColour(unsigned long TextColour)
{
    ConsoleObj.SetTextAttribute(TextColour);
    this->TextColour=TextColour;
}
/*
    *
    *
    *
*/
int screen::GetScreenColour()const
{
    return this->ScreenColour;
}
void screen::ClearScreen()
{
    ConsoleObj.FillConsoleOutput();
}
