#ifndef _DEPARTMENT_H
#define _DEPARTMENT_H
#ifndef _BASEMODEL_H
#include "../../Base/BaseModel.h"
#endif
#ifdef _WIN32
    #include "../../Base/Gui/Win32/Core/Console.h"
#endif
#include "../../Base/Gui/Source/Tools/Frame.h"
#include <string>

class Department: public BaseModel
{
private:
	int deptCode;
	int oldDeptCode;
	string deptName;
	float regularRate;
	float overtimeRate;
	Department * next;
	Department * prev;
public:
	Department();
	~Department();
	Department(int, string, float, float, Department*);
	int getDeptCode();
	string getDeptName();
	float getRegularRate();
	float getOvertimeRate();
	void setDeptCode(int);
	void setDeptName(string);
	void setRegularRate(float);
	void setOvertimeRate(float);
	void setNext(Department*);
	Department* getNext();
	void read();
	void write();
	static Department* model();
	Department* find(int);
	void show(int);
	/*bool operator != (const Department);
	bool operator == (const Department);
	Department operator = (const Department);*/
	/*fstream & operator >> (const fstream &, const Department &);
	fstream & operator << (const fstream &, const Department &);*/
	bool recordExists(int);
	bool recordExists(int, int);
	void setOldDeptCode(int);
	int getOldDeptCode();
	Department * findByCode(int);
	void save();
	void update(Department *);
	void setPrev(Department*);
	Department* getPrev();
	Department & Department::operator=(const Department &department)
	{
		if(this != &department)
		{
			this->deptCode = department.deptCode;
			this->deptName = department.deptName;
			this->regularRate = department.regularRate;
			this->overtimeRate = department.overtimeRate;
		}
		return *this;
	}
	bool Department::operator==(const Department &department) const
	{
		return this->deptCode == department.deptCode &&
		this->deptName == department.deptName &&
		this->regularRate == department.regularRate &&
		this->overtimeRate == department.overtimeRate;
	}
	bool Department::operator!=(const Department &department) const
	{
		return !(*this == department);
	}
};
#endif
