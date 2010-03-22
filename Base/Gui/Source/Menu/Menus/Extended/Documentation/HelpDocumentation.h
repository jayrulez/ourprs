#ifndef HELPDOCUMENTATION_H
#define HELPDOCUMENTATION_H

#include "../../../../Tools/Frame.h"
#ifdef _WIN32
#include "../../../../../Win32/Core/Console.h"
#endif
#include "../../../../Screen/Screen.h"

class HelpDocumentation
{
    private:
    	Frame FrameObj;
        Console ConsoleObj;
	public:
		HelpDocumentation();
		~HelpDocumentation();
		void MainMenuDoc();
		void DepartmentMenuDoc();
		void EmployeeMenuDoc();
		void PayrollMenuDoc();
};
#endif
