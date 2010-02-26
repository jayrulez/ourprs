#include "HelpDocumentation.h"

#include "../../../../Tools/Frame.h"
#ifdef _WIN32
	#include "../../../../../Win32/Core/Console.h"
#endif
#include "../../../../Screen/Screen.h"
#include <iostream>

using namespace std;

HelpDocumentation::HelpDocumentation()
{
}
HelpDocumentation::~HelpDocumentation()
{
}

void HelpDocumentation::MainMenuDoc()
{
    FrameObj.CenteredSFraming(66,20);
    ConsoleObj.xyCoord(34,23);
	cout<<"MAIN MENU";
	ConsoleObj.xyCoord(8,26);
	cout<<"Use the DIRECTION KEYS (arrow keys)  to browse the MENU options";
	ConsoleObj.xyCoord(24,28);
	cout<<" press ENTER to select option ";

}


void HelpDocumentation::DepartmentMenuDoc()
{
    FrameObj.CenteredSFraming(66,20);
    ConsoleObj.xyCoord(34,23);
	cout<<"Department MENU";
	ConsoleObj.xyCoord(8,26);
	cout<<"Use the DIRECTION KEYS (arrow keys)  to browse the MENU options";
	ConsoleObj.xyCoord(24,28);
	cout<<" press ENTER to select option ";

}

void HelpDocumentation::EmployeeMenuDoc()
{
    FrameObj.CenteredSFraming(66,20);
    ConsoleObj.xyCoord(34,23);
	cout<<"Employee MENU";
	ConsoleObj.xyCoord(8,26);
	cout<<"Use the DIRECTION KEYS (arrow keys)  to browse the MENU options";
	ConsoleObj.xyCoord(24,28);
	cout<<" press ENTER to select option ";

}
void HelpDocumentation::PayrollMenuDoc()
{
    FrameObj.CenteredSFraming(66,20);
    ConsoleObj.xyCoord(34,23);
	cout<<"Payroll MENU";
	ConsoleObj.xyCoord(8,26);
	cout<<"Use the DIRECTION KEYS (arrow keys)  to browse the MENU options";
	ConsoleObj.xyCoord(24,28);
	cout<<" press ENTER to select option ";

}

