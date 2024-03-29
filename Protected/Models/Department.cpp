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
#include <iomanip>
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

Department* Department::model()
{
    static Department * instance = NULL;
    if(instance == NULL)
        instance = new Department(0,"",0,0);
    return instance;
}

/*
 * Shows a department
 */
void Department::show(int y)
{
    Console ConsoleObj;
	Frame FrameObj;
    ConsoleObj.xyCoord(10,y+2);
    cout<<"Dept. Code        : "<<deptCode;
    ConsoleObj.xyCoord(10,y+4);
    cout<<"Dept. Name        : "<<deptName;
    ConsoleObj.xyCoord(10,y+6);
    cout<<"Regular Rate ($)  : "<< fixed << setprecision (2) << regularRate;
    ConsoleObj.xyCoord(10,y+8);
    cout<<"Overtime Rate ($) : " << fixed << setprecision (2) <<overtimeRate;
    if(FrameObj.SetFrame(5,STANDARD_FRAME_WIDTH-5,y,y+10,NORMAL_FRAME))
    {
        FrameObj.sFraming();
    }
}

/*
 * Checks if a Department with deptCode == keyCode exists
 * @ param int keyCode
 * @ return bool
 */
bool Department::recordExists(int keyCode)
{
	ifstream streamObj(this->getFilename()); // opens the file for reading
	string line;
	if(streamObj.is_open())
	{
		Department department(0,"",0,0);
	    std::getline( streamObj, line ); // reads the table headers
		while(streamObj >> department.deptCode >> department.deptName >> department.regularRate >> department.overtimeRate)
		{
			if(department.deptCode == keyCode)
			{
				/*
					if record is found, close file and return true
				*/
			    streamObj.close();
				return true;
			}
		}
		streamObj.close();
	}
	return false;
}

/*
 * Checks if a Department with deptCode == keyCode exists, 
 * ignoring param ignore
 * @ param int keyCode
 * @ return bool
 */
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

/*
 * Finds and returns Department in file where deptCode == keyCode
 * @ param int keyCode
 * @ return Department*
 */
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

/*
 * Saves a linked list of Departments to a file
 * @ param int listHead
 */
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
				oStreamObj << tempDepartment->getDeptCode() << "\t" << tempDepartment->getDeptName() << "\t" << fixed << setprecision (2) << tempDepartment->getRegularRate() << "\t" << fixed << setprecision (2) << tempDepartment->getOvertimeRate() << "\n";
				tempDepartment = tempDepartment->getNext();
			}
		}while(tempDepartment!=NULL);
		oStreamObj.close();
	}
	Department * record = Department::model()->findByCode(this->deptCode);
	if((record != NULL) && (*this == *record))
	{
		this->setOperationState(OPERATIONSTATE_SUCCESS);
	}else{
		this->setOperationState(OPERATIONSTATE_FAILURE);
	}
}

/*
 * Saves a linked list of Departments to a file, for update method
 * @ param int listHead
 */
void Department::save(Department * listHead, Department* oldDepartment)
{
	if(*this == *oldDepartment)
	{
		this->setOperationState(OPERATIONSTATE_DEFAULT);
	}else{
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
					oStreamObj << tempDepartment->getDeptCode() << "\t" << tempDepartment->getDeptName() << "\t" << fixed << setprecision (2) << tempDepartment->getRegularRate() << "\t" << fixed << setprecision (2) << tempDepartment->getOvertimeRate() << "\n";
					tempDepartment = tempDepartment->getNext();
				}
			}while(tempDepartment!=NULL);
			oStreamObj.close();
		}
		Department * record = Department::model()->findByCode(this->deptCode);
		if((record != NULL) && (*this == *record))
		{
			this->setOperationState(OPERATIONSTATE_SUCCESS);
		}else{
			this->setOperationState(OPERATIONSTATE_FAILURE);
		}
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

/*
 * Sets the previous item in a linked list
 */
void Department::setPrev(Department* department)
{
    this->prev = department;
}

/*
 * Returns the previous item in a linked list
 * @ return Department*
 */
Department* Department::getPrev()
{
    return this->prev;
}

/*
 * Gets the header row from the file and returns it
 * @ return string
 */
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
