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
#ifndef LINE_H
#define LINE_H
#include "../core/Console.h"

#define LINE_ERROR 0x3000

/*virtical single Line character*/
#define VSLINE 179
/*horizontal single Line character*/
#define HSLINE 196
/*virtical double Line character*/
#define VDLINE 186
/*horizontal double Line character*/
#define HDLINE 205

class Line
{
    private:
        int x1;
        int x2;
        int xy;
        int y1;
        int y2;
        int yx;
        Console ConsoleObj;
    public:
        Line();
        Line(int,int,int,int,int,int);
        ~Line();
        bool setHCoord(int,int,int);
        bool setVCoord(int,int,int);
        /*will be used to draw a horizontal double Line*/
        void hDLine();
        /*will be used to draw a veritcal double Line*/
        void vDLine();
        /*will be used to draw a horizontal single Line*/
        void hSLine();
        /*will be used to draw a vertical single Line*/
        void vSLine();
};
#endif // LINE_H
