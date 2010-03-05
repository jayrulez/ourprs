#ifndef TABLE_H
#define TABLE_H

#include "../Tools/Frame.h"
#include "../Screen/Screen.h"
#include "../Tools/Line.h"
#ifdef _WIN32
    #include "../../Win32/Core/Console.h"
#endif
#define DEPARTMENT_ROW_HEIGTH 2
#define UPPER_ROW_COLUMN_JOINT 194
#define LOWER_ROW_COLUMN_JOINT 193

class Table
{
private:
    Frame FrameObj;
    Screen ScreenObj;
    Console ConsoleObj;
    Line LineObj;
public:
    Table();
    ~Table();
    void DepartmentRecord(int);
};
#endif
