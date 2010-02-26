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
#include "Cancel.h"
#include "../../../Tools/Frame.h"
#include "../../../Tools/Colour.h"
#include <iostream>
#include <string>
using namespace std;

Cancel::Cancel()
{
    Title="[Esc] - Return To Menu";
}

Cancel::~Cancel()
{
}
void Cancel::ShowCancelMenu()
{
    int x1=(STANDARD_FRAME_WIDTH/2)-(Title.length()/2);
    ScreenObj.SetScreenTextColour(DefaultTextColour);
    ConsoleObj.xyCoord(x1,STANDARD_FRAME_HEIGHT-1);
    cout<<Title;
}
