#ifndef SCREEN_H
#define SCREEN_H

#include "../core/Console.h"


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
