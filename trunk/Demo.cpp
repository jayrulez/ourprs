#include <iostream>
#include "Gui/Source/MenuFormInterface/MasterFormMenuController.h"
#include "Gui/Source/Services/Services.h"
using namespace std;


int main()
{
    MasterFormMenuController MasterFormMenuControllerObj;
    Services ServicesObj;
    ServicesObj.BasicRunLevel();
    MasterFormMenuControllerObj.ViewEmployeeMenu();
    return 0;
}
