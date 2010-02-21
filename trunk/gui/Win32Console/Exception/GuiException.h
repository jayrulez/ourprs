#ifndef GUIEXCEPTION_H
#define GUIEXCEPTION_H

#include "../core/Console.h"
#include "../Screen/Screen.h"
#include "../tools/Line.h"
#include "../tools/Frame.h"
#include "../menu/Item.h"
#include "../menu/MenuController.h"


class GuiException
{
	public:
		GuiException();
		~GuiException();
		void CatchAllGuiExecptions();
};
#endif
