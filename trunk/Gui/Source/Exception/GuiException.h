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
#ifndef GUIEXCEPTION_H
#define GUIEXCEPTION_H
#ifdef _WIN32
	#include "../../Win32/Core/Console.h"
#endif
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
