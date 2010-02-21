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
#ifndef SCROLLER_H
#define SCROLLER_H
#include "../tools/Frame.h"
#include "../core/Console.h"
class Scroller
{
private:
    int item_code;
    int itemX;
    int itemY;
    int lenght;
    unsigned long colour;
    /*Frame will be used to make the Scroller*/
    Frame FrameObj;
    Console ConsoleObj;
public:
    Scroller();
    ~Scroller();
    bool SetScroller(int,int,int,unsigned long);
    /*used to put the Scroller in motion*/
    void scroll();
    /*kill/erases the Scroller's trace on the Screen*/
    void KillScroll();
};
#endif // SCROLLER_H
