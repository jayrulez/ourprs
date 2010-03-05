#ifndef TABLE_H
#define TABLE_H

#include "../Tools/Frame.h"
#include "../Screen/Screen.h"
#ifdef _WIN32
    #include "../../Win32/Core/Console.h"
#endif
class Table
{
private:
    Frame FrameObj;
    Screen ScreenObj;
    Console ConsoleObj;
public:
    Table();
    ~Table();
    void DepartmentRecord(int);
};
#endif
