#ifndef SCREEN_H
#define SCREEN_H

#include "../core/console.h"


class screen
{
private:
    unsigned long ScreenColour;
    unsigned long TextColour;
    console ConsoleObj;
public:
    screen();
    ~screen();
    screen(unsigned long,unsigned long);
    void SetScreenColour(unsigned long);
    void SetScreenTextColour(unsigned long);
    int GetScreenColour()const;
    void ClearScreen();
};

#endif
