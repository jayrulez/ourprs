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
#include "../Core/Console.h"
#include "Input/TextInput.h"
#include "../Tools/Frame.h"
#include "Validation/Validator.h"
#include "../Menu/MenuController.h"
#include "../Menu/Menus/Extended/ExtendedMenuController.h"
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
    MenuController *MenuControllerObj;
    ExtendedMenuController ExtendedMenuControllerObj;
    int FormSize;
    int FormCode;
    bool VerticalFormRangeCheck;
public:
    FormController();
    ~FormController();
    Field* GetAllFieldInfo();
    void UpdateAllFieldInfo(Field*);
    bool SetForm(Field*,int,int);
    void SetFormMenuController(MenuController*);
    void ShowForm();
    int BrowseForm();
    void Browse();
    Field DefaultStartingField();
    Field SearchField(int);
    void FieldInput();
    void UpdateField();
    bool FormRangeCheck(int);
    bool Validate();
    int ExtendedMenuCalls(int,int);
};
#endif // FORMCONTROLLER_H
