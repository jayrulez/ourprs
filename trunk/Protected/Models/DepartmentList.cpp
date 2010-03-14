#include "Department.h"
#include "DepartmentList.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#ifdef _WIN32
    #include "../../Base/Gui/Win32/Core/Console.h"
#endif
using namespace std;

DepartmentList::DepartmentList()
{
    Head=NULL;
}
DepartmentList::~DepartmentList()
{
    this->DestroyList();
}
void DepartmentList::AddDepartment(Department NewDepartment)
{
    Department *TempDepartment = new Department;
    *TempDepartment = NewDepartment;
    if(TempDepartment!=NULL)
    {
        if(Head==NULL)
        {
            Head=TempDepartment;
        }
        else
        {
            Department *CacheDepartment=Head;
            while(CacheDepartment->getNext()!=NULL)
            {
                CacheDepartment=CacheDepartment->getNext();
            }
            CacheDepartment->setNext(TempDepartment);
        }
    }
}
Department* DepartmentList::GetDepartment(Department Dept)
{
    return &Dept;
}
void DepartmentList::ShowDepartmentList()
{
    Console ConsoleObj;
    Department *CacheDepartment = Head;

    int count=0;
    int x=5;
    int y=8;
    while(CacheDepartment!=NULL)
    {

        ConsoleObj.xyCoord(x,y);
        cout << setw(3) << ++count<<". "<< setw(4) << CacheDepartment->getDeptCode() << "\t" <<
        setw(30) << CacheDepartment->getDeptName() << "\t" << setw(10) << CacheDepartment->getRegularRate() << "\t" <<
        setw(10) << CacheDepartment->getOvertimeRate() << endl;
        CacheDepartment=CacheDepartment->getNext();
        y+=2;
    }
    ConsoleObj.xyCoord(x,y+6);
}

Department* DepartmentList::getHead()
{
	return Head;
}

void DepartmentList::BuildListFromFile()
{
    int deptCode;
    string deptName;
    float regularRate;
    float overtimeRate;
	ifstream iStreamObj(Department::model()->getFilename());

    Department DepartmentObj(0,"",0,0,NULL);

	if(iStreamObj.is_open())
	{
		while(iStreamObj >> deptCode >> deptName >> regularRate >> overtimeRate)
		{
		    DepartmentObj.setDeptCode(deptCode);
		    DepartmentObj.setDeptName(deptName);
		    DepartmentObj.setRegularRate(regularRate);
		    DepartmentObj.setOvertimeRate(overtimeRate);
            this->AddDepartment(DepartmentObj);
        }
        iStreamObj.close();
	}
}
void DepartmentList::DestroyList()
{
	Department *CacheDepartment;
	while (Head != NULL)
	{
		CacheDepartment = this->Head;
		CacheDepartment = (this->Head)->getNext();
		delete CacheDepartment;
	}
}
