#ifndef _DEPARTMENT_H
#include "./Department.h"
#endif
#ifndef _CONFIG_H
#include "../../config.h"
#endif
#include <fstream>
#include <iostream>

using namespace std;

Department::Department()
{
	this->next = NULL;
	this->setFilename(DEPARTMENT_RATES_FILE);
	this->isNewRecord = true;
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
	this->isNewRecord = true;
}

bool Department::getIsNewRecord()
{
	return this->isNewRecord;
}

void Department::setIsNewRecord(bool isNewRecord)
{
	this->isNewRecord = isNewRecord;
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

Department* Department::find(int deptCode)
{
	/*

		Department *department = &record;
		// department = record;
	*/
	return NULL;
}

void Department::show()
{
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

bool Department::findByCode(int keyCode)
{
	ifstream streamObj(this->getFilename());

	if(streamObj.is_open())
	{
		Department department(0,"",0,0);
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

void Department::save()
{
	ofstream streamObj(this->getFilename(),ios::out);

	cout << "this->getFilename()"; fgetc(stdin);

	if(streamObj)
	{
		while(!streamObj.eof())
		{
            if(streamObj.eof()) break;
		}
		streamObj << this->deptCode << "\t" << this->deptName << "\t" << this->regularRate << "\t" << this->overtimeRate <<endl;
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
