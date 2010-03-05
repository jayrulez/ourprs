#include "Table.h"
#include "../Tools/Frame.h"
#include "../Tools/Colour.h"
#include "../Tools/Line.h"
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
    if(FrameObj.SetFrame(3,77,y,y+DEPARTMENT_ROW_HEIGTH,NORMAL_FRAME))
    {
        ScreenObj.SetScreenTextColour(DefaultTextColour);
        FrameObj.sFraming();

        LineObj.setVCoord(y,y+DEPARTMENT_ROW_HEIGTH,8);
        LineObj.vSLine();
        LineObj.setVCoord(y,y+DEPARTMENT_ROW_HEIGTH,8+25+1);
        LineObj.vSLine();
        LineObj.setVCoord(y,y+DEPARTMENT_ROW_HEIGTH,8+25+12+1);
        LineObj.vSLine();
        LineObj.setVCoord(y,y+DEPARTMENT_ROW_HEIGTH,8+25+12+12+1);
        LineObj.vSLine();
    }
}
