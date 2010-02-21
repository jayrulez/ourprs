/*
@Group: BSC2D
@Group Members:
	<ul>
		<li>Robert Campbell: 0701334</li>
		<li>Audley Gordon: 0802218</li>
		<li>Dale McFarlane: 0801042</li>
		<li>Dyonne Duberry: 0802189</li>
		<li>Xavier Lowe: 0802488</li>
	</ul>
@
*/
/*
* necessary for the GetConsoleWindow() function to work!
* it basically says that you are running this
* program on Windows 2000 or higher
*/
#include "console.h"

console::console()
{
 
}
console::~console()
{
}
/*
    *
    *
    *
*/
int console::GetConsoleBufferHeight()
{
	return 0;
}
/*
    *
    *
    *
*/
int console::GetConsoleBufferWidth()
{
    return 0;
}
/*
    *
    *
    *
*/
bool console::SetConsolePosition(int top,int left, int width,int height)
{
	return true;
}
/*
    *
    *
    *
*/
bool console::CenterConsole(int width,int height)
{
	return true;
}
/*
    *
    *
    *
*/
void console::xyCoord(int x,int y)
{

}
/*
    *
    *
    *
*/
void console::SetCursor(bool visible,int size)
{

}
/*
    *
    *
    *
*/
void console::SetColour(unsigned long colour)
{

}
/*
    *
    *
    *
*/
void console::SetTextAttribute(unsigned long colour)
{
}
/*
    *
    *
    *
*/
void console::FillConsoleOutput()
{

}
/*
    *
    *
    *
*/
void console::SetConsoleScreenColour(unsigned long ScreenColour)
{
}
int console::GetCursorPositionX()
{
	return 0;
}
int console::GetCursorPositionY()
{
	return 0;
}
