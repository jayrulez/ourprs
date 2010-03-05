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
#ifndef VALIDATOR_H
#define VALIDATOR_H
#include "../../Screen/Screen.h"
#ifdef _WIN32
	#include "../../../Win32/Core/Console.h"
#endif
#include "../../../../../Protected/Models/Department.h"
#include <string>

using namespace std;

class Validator
{
private:
    Screen ScreenObj;
    Console ConsoleObj;
    Department DepartmentObj;
public:
    Validator();
    ~Validator();
    bool CheckStringLenght(string);
    bool CheckNumberValue(string);
    bool CheckDataExistence(string);
    bool CheckDepartmentExistence(string);
};
#endif
