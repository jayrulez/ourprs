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
#ifndef FORMCONTROLLER_H
#define FORMCONTROLLER_H

#include <string>
#ifdef _WIN32
	#include "../../Win32/Core/Console.h"
#endif
#include "Input/TextInput.h"
#include "../Tools/Frame.h"
#include "Validation/Validator.h"
#include "Field.h"

using namespace std;

#define STATE_DEFAULT 0
#define STATE_SUCCESS 1
#define STATE_ERROR 2
#define STATE_FAILURE 3

#define OUT_OF_FORM_RANGE 0
#define IN_FORM_RANGE 1

#define _PREV 0
#define _NEXT 1

#define _PASS 1
#define _FAIL 0

class FormController
{
private:
    Console ConsoleObj;
    Field *fptr;
    Field CurrentField;
    Field PreviousField;
    TextInput TextInputObj;
    Validator ValidatorObj;
	Frame FrameObj;
    int FormSize;
    int FormCode;
    bool VerticalFormRangeCheck;
    bool CompleteState;
    string UpdateFormOldKey;
public:
    FormController();
    ~FormController();
	int GetFormCode();
	int GetFormSize();
	bool GetFormCompletionState();
    Field* GetAllFieldInfo();
    void UpdateAllFieldInfo(Field*);
    void ClearAllFieldData();
    bool SetForm(Field*,int,int);
    void ShowForm();
    int BrowseForm();
    void Browse();
    Field DefaultStartingField();
    Field SearchField(int);
    void FieldInput();
    void UpdateField();
    bool FormRangeCheck(int);
    bool ValidateEmployeeFields();
    bool ValidateDepartmentFields();
    bool ValidatePayrollFields();
    bool ValidateForm();
    void SetFieldState(bool);
};
#endif // FORMCONTROLLER_H
