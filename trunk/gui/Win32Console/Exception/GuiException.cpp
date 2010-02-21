#include "GuiException.h"
#include "../core/Console.h"
#include "../Screen/Screen.h"
#include "../tools/Line.h"
#include "../tools/Frame.h"
#include "../menu/Item.h"
#include "../menu/MenuController.h"
#include "../Form/FormController.h"
#include "../Form/Field.h"
GuiException::GuiException()
{
}

GuiException::~GuiException()
{
}
void GuiException::CatchAllGuiExecptions()
{
    /*
    catch(Console,Screen,Line,Frame,Item,MenuController,FormController,Field)
    {
    }
*/
}
