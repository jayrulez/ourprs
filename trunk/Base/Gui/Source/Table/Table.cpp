#include "Table.h"
#include "../Tools/Frame.h"
#include "../Tools/Colour.h"
#include <iostream>
using namespace std;

Table::Table()
{
}
Table::~Table()
{
}
void Table::DepartmentRecord(int y)
{
    if(FrameObj.SetFrame(2,77,y,y+3,NORMAL_FRAME))
    {
        ScreenObj.SetScreenTextColour(DefaultTextColour);
        FrameObj.sFraming();
    }
}
