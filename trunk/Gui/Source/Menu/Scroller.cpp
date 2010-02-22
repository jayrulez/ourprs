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
#include <iostream>
#include "Scroller.h"
#include "../tools/Frame.h"
using namespace std;
Scroller::Scroller()
{
    item_code=0;
    itemX=0;
    itemY=0;
    lenght=0;
    colour=0;
}
Scroller::~Scroller()
{
}
bool Scroller::SetScroller(int x,int y,int len,unsigned long c)
{
    if(x>=0&&y>=1&&len>=0){
       itemX=x;
       itemY=y;
       lenght=len;
       colour=c;
       return true;
    }
    return false;
}
void Scroller::scroll()
{
    ConsoleObj.SetTextAttribute(colour);
    FrameObj.SetFrame(itemX-1,itemX+lenght,itemY-1,itemY+1,NORMAL_FRAME);
    FrameObj.sFraming();
}
void Scroller::KillScroll()
{
    ConsoleObj.SetTextAttribute(ConsoleObj.GetConsoleScreenColour()+3);
    FrameObj.SetFrame(itemX-1,itemX+lenght,itemY-1,itemY+1,NORMAL_FRAME);
    FrameObj.sFraming();
    ConsoleObj.SetTextAttribute(colour);
}
