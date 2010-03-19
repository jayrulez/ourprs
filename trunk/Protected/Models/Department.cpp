#ifndef _DEPARTMENT_H
#include "./Department.h"
#endif
#ifndef _BASEMODEL_H
#include "../../Base/BaseModel.h"
#endif
#ifndef _CONFIG_H
#include "../../config.h"
#endif
#ifdef _WIN32
    #include "../../Base/Gui/Win32/Core/Console.h"
#endif
#include "../../Base/Gui/Source/Tools/Frame.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Department::Department()
{
	this->next = NULL;
	this->prev = NULL;
	this->setFilename(DEPARTMENT_RATES_FILE);
	this->setFileHeader("Dept. Code\tDept. Name\tRegular Rate\tOvertime Rate\n");
}

Department::~Department()
{
}

Department::Department(int deptCode = 0, string deptName = "", float regularRate = 0, float overtimeRate = 0)
{
	this->deptCode = deptCode;
	this->deptName = deptName;
	this->regularRate = regularRate;
	this->overtimeRate = overtimeRate;
	this->next = NULL;
	this->prev = NULL;
	this->setFilename(DEPARTMENT_RATES_FILE);
	this->setFileHeader("Dept. Code\tDept. Name\tRegular Rate\tOvertime Rate\n");
}

Department* Department::getNext()
{
	return this->next;
}

void Department::setNext(Department * next = NULL)
{
	this->next = next;
}

int Department::getDeptCode()
{
	return this->deptCode;
}

string Department::getDeptName()
{
	return this->deptName;
}

float Department::getRegularRate()
{
	return this->regularRate;
}

float Department::getOvertimeRate()
{
	return this->overtimeRate;
}

void Department::setDeptCode(int deptCode)
{
	this->deptCode = deptCode;
}

void Department::setDeptName(string deptName)
{
	this->deptName = deptName;
}

void Department::setRegularRate(float regularRate)
{
	this->regularRate = regularRate;
}

void Department::setOvertimeRate(float overtimeRate)
{
	this->overtimeRate = overtimeRate;
}


void Department::write()
{

}

void Department::read()
{

}

Department* Department::model()
{
    static Department * instance = NULL;
    if(instance == NULL)
        instance = new Department(0,"",0,0);
    return instance;
}

void Department::show(int y)
{
    Console ConsoleObj;
	Frame FrameObj;
    ConsoleObj.xyCoord(10,y+2);
    cout<<"Dept. Code        : "<<deptCode;
    ConsoleObj.xyCoord(10,y+4);
    cout<<"Dept. Name        : "<<deptName;
    ConsoleObj.xyCoord(10,y+6);
    cout<<"Regular Rate ($)  : "<<regularRate;
    ConsoleObj.xyCoord(10,y+8);
    cout<<"Overtime Rate ($) : "<<overtimeRate;
    if(FrameObj.SetFrame(5,STANDARD_FRAME_WIDTH-5,y,y+10,NORMAL_FRAME))
    {
        FrameObj.sFraming();
    }
}

/*bool Department::operator == (const Department DepartmentObj)
{
    if(DepartmentObj.deptCode==this->deptCode && DepartmentObj.deptName==this->deptName
    &&DepartmentObj.overtimeRate==this->overtimeRate&&DepartmentObj.regularRate==this->regularRate)
        return true;
    else
        return false;
}
Department Department::operator = (const Department DepartmentObj)
{
    this->deptCode= DepartmentObj.deptCode;
    this->deptName=DepartmentObj.deptName;
    this->overtimeRate=DepartmentObj.overtimeRate;
    this->regularRate=DepartmentObj.regularRate;
    return *this;
}*/

bool Department::recordExists(int keyCode)
{
	ifstream streamObj(this->getFilename());
	string line;
	if(streamObj.is_open())
	{
		Department department(0,"",0,0);
	    std::getline( streamObj, line );
		while(streamObj >> department.deptCode >> department.deptName >> department.regularRate >> department.overtimeRate)
		{
			if(department.deptCode == keyCode)
			{
			    streamObj.close();
				return true;
			}
		}
		streamObj.close();
	}
	return false;
}

bool Department::recordExists(int keyCode, int ignore)
{
	ifstream streamObj(this->getFilename());
	string line;
	if(streamObj.is_open())
	{
		Department department(0,"",0,0);
	    std::getline( streamObj, line );
		while(streamObj >> department.deptCode >> department.deptName >> department.regularRate >> department.overtimeRate)
		{
			if(department.deptCode != ignore)
			{
				if(department.deptCode == keyCode)
				{
					streamObj.close();
					return true;
				}
			}
		}
		streamObj.close();
	}
	return false;
}

Department* Department::findByCode(int keyCode)
{
	ifstream streamObj(this->getFilename());
	string line;
	if(streamObj.is_open())
	{
		Department department(0,"",0,0);
	    std::getline( streamObj, line );
		while(streamObj >> department.deptCode >> department.deptName >> department.regularRate >> department.overtimeRate)
		{
			if(department.deptCode == keyCode)
			{
			    streamObj.close();
			    Department * record = new Department(department.deptCode,department.deptName,department.regularRate,department.overtimeRate);
				return record;
			}
		}
		streamObj.close();
	}
	return NULL;
}

void Department::save(Department * listHead)
{
	ifstream iStreamObj(this->getFilename());
	Department * tempDepartment = listHead;

    ofstream oStreamObj(this->getFilename(), ios::trunc);
    if(oStreamObj.is_open())
    {
        oStreamObj << this->getFileHeader();
        do
        {
            if(tempDepartment != NULL)
            {
                oStreamObj << tempDepartment->getDeptCode() << "\t" << tempDepartment->getDeptName() << "\t" << tempDepartment->getRegularRate() << "\t" << tempDepartment->getOvertimeRate() << "\n";
                tempDepartment = tempDepartment->getNext();
            }
        }while(tempDepartment!=NULL);
        oStreamObj.close();
    }
    if(Department::model()->recordExists(this->deptCode))
    {
        this->setOperationState(OPERATIONSTATE_SUCCESS);
    }else{
        this->setOperationState(OPERATIONSTATE_FAILURE);
	}
}

void Department::setOldDeptCode(int oldDeptCode)
{
	this->oldDeptCode = oldDeptCode;
}

int Department::getOldDeptCode()
{
	return this->oldDeptCode;
}

void Department::setPrev(Department* department)
{
    this->prev = department;
}

Department* Department::getPrev()
{
    return this->prev;
}

string Department::getFileHeaderFromFile()
{
	ifstream streamObj(this->getFilename());
	string line = NULL;
	if(streamObj.is_open())
	{
	    std::getline( streamObj, line );
		streamObj.close();
	}
	return line;
}
