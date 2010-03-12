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
#include "Field.h"
#include <string>
#include <iostream>
using namespace std;

Field::Field()
{
}
Field::~Field()
{
}
Field::Field(string FieldName,int x,int y,int FieldCode,int InputType,int SpaceType,int InputLength)
{
    if(x>0 && y>0 && InputLength>0)
    {
        this->FieldName=FieldName;
        this->FieldCode=FieldCode;
        this->InputLength=InputLength;
        this->InputType=InputType;
        this->SpaceType=SpaceType;
        this->x=x;
        this->y=y;
    }
    else
        throw INVALID_FIELD;

}
bool Field::SetField(string FieldName,int x,int y,int FieldCode,int InputType,int SpaceType,int InputLength,bool ValidData)
{
    if(x>0 && y>0 && InputLength>0)
    {
        this->FieldName=FieldName;
        this->FieldCode=FieldCode;
        this->InputLength=InputLength;
        this->InputType=InputType;
        this->SpaceType=SpaceType;
        this->x=x;
        this->y=y;
        this->ValidData=ValidData;
        return true;
    }
    return false;
}
string Field::GetFieldName()
{
    return this->FieldName;
}
int Field::GetFieldCode()
{
    return this->FieldCode;
}
int Field::GetInputType()
{
    return this->InputType;
}
int Field::GetSpaceType()
{
    return this->SpaceType;
}
int Field::GetInputLength()
{
    return this->InputLength;
}
int Field::GetFieldNameLength()
{
    this->FieldNameLength=FieldName.length();
    return this->FieldNameLength;
}
int Field::GetFieldX()
{
    return this->x;
}
int Field::GetFieldY()
{
    return this->y;
}
string Field::GetFieldData()
{
    return this->Data;
}
void Field::SetFieldData(string Data)
{
    this->Data=Data;
}
int Field::GetFieldDataLength()
{
    return this->Data.length();
}
void Field::ShowField()
{
    ConsoleObj.xyCoord(this->x,this->y);
    cout<<FieldName;
    cout<<":";
    cout<<" "<<Data;
}
bool Field::operator==(const Field Rhs)
{
    if(this->FieldCode==Rhs.FieldCode&&this->FieldName==Rhs.FieldName&&this->x==Rhs.x&&this->y==Rhs.y)
    {
        return true;
    }
    return false;
}
void Field::SetValidData(bool ValidData)
{
    this->ValidData=ValidData;
}
bool Field::GetValidData()
{
    return this->ValidData;
}
