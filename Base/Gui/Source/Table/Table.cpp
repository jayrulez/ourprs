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

        LineObj.setVCoord(y+1,y+DEPARTMENT_ROW_HEIGTH-1,12);
        LineObj.vSLine();

        ConsoleObj.xyCoord(12,y);
        cout<<(unsigned char)UPPER_ROW_COLUMN_JOINT;
        ConsoleObj.xyCoord(12,y+DEPARTMENT_ROW_HEIGTH);
        cout<<(unsigned char)LOWER_ROW_COLUMN_JOINT;

        LineObj.setVCoord(y+1,y+DEPARTMENT_ROW_HEIGTH-1,45);
        LineObj.vSLine();

        ConsoleObj.xyCoord(45,y);
        cout<<(unsigned char)UPPER_ROW_COLUMN_JOINT;
        ConsoleObj.xyCoord(45,y+DEPARTMENT_ROW_HEIGTH);
        cout<<(unsigned char)LOWER_ROW_COLUMN_JOINT;

        LineObj.setVCoord(y+1,y+DEPARTMENT_ROW_HEIGTH-1,62);
        LineObj.vSLine();

        ConsoleObj.xyCoord(62,y);
        cout<<(unsigned char)UPPER_ROW_COLUMN_JOINT;
        ConsoleObj.xyCoord(62,y+DEPARTMENT_ROW_HEIGTH);
        cout<<(unsigned char)LOWER_ROW_COLUMN_JOINT;

    }
}

/*
	TableObj.DepartmentRecord(6);
	TableObj.DepartmentRecord(9);
	TableObj.DepartmentRecord(13);
	TableObj.DepartmentRecord(16);
	TableObj.DepartmentRecord(19);
	TableObj.DepartmentRecord(22);
	TableObj.DepartmentRecord(25);
	TableObj.DepartmentRecord(28);
	TableObj.DepartmentRecord(31);
	TableObj.DepartmentRecord(34);
*/
