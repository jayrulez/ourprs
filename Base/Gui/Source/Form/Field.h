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
#ifndef FIELD_H
#define FIELD_H
#ifdef _WIN32
	#include "../../Win32/Core/Console.h"
#endif
#include <string>

#define INVALID_FIELD 0x9001
#define FIELD_NAME_PAD 2

using namespace std;

class Field
{
private:
    string FieldName;
    string Data;
    int FieldCode;
    int InputLength;
    int FieldNameLength;
    int InputType;
    int SpaceType;
    int x;
    int y;
    bool ValidData;
    Console ConsoleObj;
public:
    Field();
    ~Field();
    Field(string,int,int,int,int,int,int);
    bool SetField(string,int,int,int,int,int,int);
    string GetFieldName();
    void SetValidData(bool);
    bool GetValidData();
    int GetFieldCode();
    int GetInputType();
    int GetSpaceType();
    int GetInputLength();
    int GetFieldNameLength();
    int GetFieldX();
    int GetFieldY();
    string GetFieldData();
    void SetFieldData(string);
    int GetFieldDataLength();
    void ShowField();
    bool operator==(const Field);
};
#endif
