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

using namespace std;

Department::Department()
{
	this->next = NULL;
	this->setFilename(DEPARTMENT_RATES_FILE);
	this->operationState = true;
}

Department::~Department()
{
}

Department::Department(int deptCode = 0, string deptName = "", float regularRate = 0, float overtimeRate = 0, Department * next = NULL)
{
	this->deptCode = deptCode;
	this->deptName = deptName;
	this->regularRate = regularRate;
	this->overtimeRate = overtimeRate;
	this->next = next;
	this->setFilename(DEPARTMENT_RATES_FILE);
	this->operationState = true;
}

bool Department::getOperationState()
{
	return this->operationState;
}

void Department::setOperationState(bool operationState)
{
	this->operationState = operationState;
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
	return new Department(0,"",0,0,NULL);
}

void Department::show(int y)
{
    if(FrameObj.SetFrame(5,STANDARD_FRAME_WIDTH-5,y,y+11,NORMAL_FRAME))
    {
        FrameObj.sFraming();
    }
    ConsoleObj.xyCoord(10,y+2);
    cout<<"Dept. Code        : "<<deptCode;
    ConsoleObj.xyCoord(10,y+4);
    cout<<"Dept. Name        : "<<deptName;
    ConsoleObj.xyCoord(10,y+6);
    cout<<"Regular Rate ($)  : "<<regularRate;
    ConsoleObj.xyCoord(10,y+8);
    cout<<"Overtime Rate ($) : "<<overtimeRate;
    ConsoleObj.xyCoord(10,y+10);
}
bool Department::operator == (const Department DepartmentObj)
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
}

bool Department::recordExists(int keyCode)
{
	ifstream streamObj(this->getFilename());
	string line;
	if(streamObj.is_open())
	{
		Department department(0,"",0,0);
	    std::getline( streamObj, line );
		while(streamObj!=NULL)
		{
		    //streamObj >>deptCode >>deptName >>regularRate >>overtimeRate;
			streamObj >> department.deptCode >> department.deptName >> department.regularRate >> department.overtimeRate;
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
		while(streamObj!=NULL)
		{
		    //streamObj >>deptCode >>deptName >>regularRate >>overtimeRate;
			streamObj >> department.deptCode >> department.deptName >> department.regularRate >> department.overtimeRate;
			if(department.deptCode != keyCode)
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
		while(streamObj!=NULL)
		{
		    //streamObj >>deptCode >>deptName >>regularRate >>overtimeRate;
			streamObj >> department.deptCode >> department.deptName >> department.regularRate >> department.overtimeRate;
			if(department.deptCode == keyCode)
			{
			    streamObj.close();
			    Department * record = new Department(department.deptCode,department.deptName,department.regularRate,department.overtimeRate);
				return record;
				//return NULL;
			}
		}
		streamObj.close();
	}
	return NULL;
}

void Department::save()
{
	ofstream streamObj(this->getFilename(),ios::app);
	if(streamObj.is_open())
	{
		if(streamObj << this->deptCode << "\t" << this->deptName << "\t" << this->regularRate << "\t" << this->overtimeRate << "\n")
			this->operationState = OPERATIONSTATE_SUCCESS;
		streamObj.close();
	}
}

void Department::update()
{
	fstream streamObj(this->getFilename(), ios::in|ios::out);
	string line;
	int position;
	bool found = false;
	if(streamObj.is_open())
	{
		Department department(0,"",0,0);
	    std::getline( streamObj, line );
		while(streamObj!=NULL)
		{
			streamObj >> department.deptCode >> department.deptName >> department.regularRate >> department.overtimeRate;
			if(this->deptCode == department.deptCode)
			{
				found = true;
				position = streamObj.tellg();
				break;
			}
		}
		if(found)
		{
			streamObj.seekp(position-1,ios::cur);
			if(streamObj << this->deptCode << "\t" << this->deptName << "\t" << this->regularRate << "\t" << this->overtimeRate << "\n")
				this->operationState = OPERATIONSTATE_SUCCESS;
		}
		streamObj.close();
	}
}

/*fstream & Department::operator >> (const fstream &mystream, Department &department)
{
	mystream << department.deptCode << "\t" << department.deptCode << "\t" << department.regularRate << "\t" << department.overtimeRate;
	return NULL;
}

fstream & Department::operator << (const fstream &mystream, Department &department)
{
	//department >>
	return NULL;
}*/
