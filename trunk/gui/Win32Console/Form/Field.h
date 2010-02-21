#ifndef FIELD_H
#define FIELD_H

#include "../Core/Console.h"
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
    Console ConsoleObj;
public:
    Field();
    ~Field();
    Field(string,int,int,int,int,int,int);
    bool SetField(string,int,int,int,int,int,int);
    string GetFieldName();
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
