#include "Payroll.h"
#include "PayrollList.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#ifdef _WIN32
    #include "../../Base/Gui/Win32/Core/Console.h"
#endif
using namespace std;

PayrollList::PayrollList()
{
    Head=NULL;
}
PayrollList::~PayrollList()
{
    this->DestroyList();
}
void PayrollList::AddPayroll(Payroll NewPayroll)
{
    Payroll *TempPayroll = new Payroll;
    *TempPayroll = NewPayroll;
    if(TempPayroll!=NULL)
    {
        if(Head==NULL)
        {
            Head=TempPayroll;
        }
        else
        {
            Payroll *CachePayroll=Head;
            while(CachePayroll->getNext()!=NULL)
            {
                CachePayroll=CachePayroll->getNext();
            }
            CachePayroll->setNext(TempPayroll);
        }
    }
}
Payroll* PayrollList::GetPayroll(Payroll PayrollObj)
{
    return &PayrollObj;
}
void PayrollList::ShowPayrollList()
{
    /*
    Console ConsoleObj;
    Payroll *CachePayroll = Head;

    int count=0;
    int x=5;
    int y=8;
    while(CachePayroll!=NULL)
    {

        ConsoleObj.xyCoord(x,y);
        cout << setw(3) << ++count<<". "<< setw(4) << CachePayroll->getDeptCode() << "\t" <<
        setw(30) << CachePayroll->getDeptName() << "\t" << setw(10) << CachePayroll->getRegularRate() << "\t" <<
        setw(10) << CachePayroll->getOvertimeRate() << endl;
        CachePayroll=CachePayroll->getNext();
        y+=2;
    }
    ConsoleObj.xyCoord(x,y+6);
    */
}

Payroll* PayrollList::getHead()
{
	return Head;
}

void PayrollList::BuildListFromFile()
{
    /*
    int deptCode;
    string deptName;
    float regularRate;
    float overtimeRate;
	ifstream iStreamObj(Payroll::model()->getFilename());

    Payroll PayrollObj(0,"",0,0,NULL);

	if(iStreamObj.is_open())
	{
		while(iStreamObj >> deptCode >> deptName >> regularRate >> overtimeRate)
		{
		    PayrollObj.setDeptCode(deptCode);
		    PayrollObj.setDeptName(deptName);
		    PayrollObj.setRegularRate(regularRate);
		    PayrollObj.setOvertimeRate(overtimeRate);
            this->AddPayroll(PayrollObj);
        }
        iStreamObj.close();
	}
	*/
}
void PayrollList::DestroyList()
{
	Payroll *CachePayroll;
	while (Head != NULL)
	{
		CachePayroll = this->Head;
		CachePayroll = (this->Head)->getNext();
		delete CachePayroll;
	}
}
