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
#include "Validator.h"
#include <iostream>
#include <string>
#include <sstream>
#include "../../Tools/Colour.h"

using namespace std;

Validator::Validator()
{
}
Validator::~Validator()
{
}
bool Validator::CheckStringLenght(string str)
{
	return true;
}
bool Validator::CheckNumberValue(string str)
{
	return true;
}
bool Validator::CheckDataExistence(string str)
{
    if(str.empty())
    {
        ScreenObj.SetScreenTextColour(WhiteColour);
        cout<<"<Required>";
        ScreenObj.SetScreenTextColour(DefaultTextColour);
        return false;
    }
    else
    {
        ScreenObj.SetScreenTextColour(DefaultBgColour);
        cout<<"<Required>";
        ScreenObj.SetScreenTextColour(DefaultTextColour);
        return true;
    }
}
bool Validator::CheckDepartmentExistence(string DeptCode)
{
    int intCode;
    istringstream MyStream(DeptCode);
    MyStream>>intCode;
    if(DepartmentObj.model()->recordExists(intCode))
    {
        ScreenObj.SetScreenTextColour(RedTextColour);
        cout<<"<Department already exist>";
        ScreenObj.SetScreenTextColour(DefaultTextColour);
        return true;
    }
    else
    {
        ScreenObj.SetScreenTextColour(DefaultBgColour);
        cout<<"<Department already exist>";
        ScreenObj.SetScreenTextColour(DefaultTextColour);
    }
    return false;
}
bool Validator::CheckDepartmentExistenceInEmployeeForm(string DeptCode)
{
    int intCode;
    istringstream MyStream(DeptCode);
    MyStream>>intCode;
    if(DepartmentObj.model()->recordExists(intCode))
    {
        ScreenObj.SetScreenTextColour(DefaultBgColour);
        cout<<"<Department Does Not exist>";
        ScreenObj.SetScreenTextColour(DefaultTextColour);
        return true;
    }
    else
    {
        ScreenObj.SetScreenTextColour(RedTextColour);
        cout<<"<Department Does Not exist>";
        ScreenObj.SetScreenTextColour(DefaultTextColour);
    }
    return false;
}
bool Validator::CheckOtherDepartmentExistence(string CurrentDeptCode,string OldDeptCode)
{
    int intOldCode;
    int intCurrentCode;

    istringstream MyStream(OldDeptCode);
    MyStream>>intOldCode;
    istringstream MyStream1(CurrentDeptCode);
    MyStream1>>intCurrentCode;

    if(DepartmentObj.model()->recordExists(intCurrentCode,intOldCode))
    {
        ScreenObj.SetScreenTextColour(RedTextColour);
        cout<<"<Department already exist>";
        ScreenObj.SetScreenTextColour(DefaultTextColour);
        return true;
    }
    ScreenObj.SetScreenTextColour(DefaultBgColour);
    cout<<"<Department already exist>";
    ScreenObj.SetScreenTextColour(DefaultTextColour);
    return false;
}
bool Validator::CheckEmployeeExistence(string ID)
{
    int intCode;
    istringstream MyStream(ID);
    MyStream>>intCode;
    if(Employee::model()->recordExists(intCode))
    {
        ScreenObj.SetScreenTextColour(RedTextColour);
        cout<<"<Employee already exist>";
        ScreenObj.SetScreenTextColour(DefaultTextColour);
        return true;
    }
    ScreenObj.SetScreenTextColour(DefaultBgColour);
    cout<<"<Employee already exist>";
    ScreenObj.SetScreenTextColour(DefaultTextColour);
    return false;
}
bool Validator::CheckOtherEmployeeExistence(string CurrentID,string OldID)
{
    int OldCode;
    int CurrentCode;

    istringstream MyStream(OldID);
    MyStream>>OldCode;
    istringstream MyStream1(CurrentID);
    MyStream1>>CurrentCode;

    if(DepartmentObj.model()->recordExists(CurrentCode,OldCode))
    {
        ScreenObj.SetScreenTextColour(RedTextColour);
        cout<<"<Employee already exist>";
        ScreenObj.SetScreenTextColour(DefaultTextColour);
        return true;
    }
    ScreenObj.SetScreenTextColour(DefaultBgColour);
    cout<<"<Employee already exist>";
    ScreenObj.SetScreenTextColour(DefaultTextColour);
    return false;
}
