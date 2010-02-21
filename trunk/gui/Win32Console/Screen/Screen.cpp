#include "Screen.h"

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
