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
#include "../core/console.h"

#define LINE_ERROR 0x3000

/*virtical single line character*/
#define VSLINE 179
/*horizontal single line character*/
#define HSLINE 196
/*virtical double line character*/
#define VDLINE 186
/*horizontal double line character*/
#define HDLINE 205

class line
{
    private:
        int x1;
        int x2;
        int xy;
        int y1;
        int y2;
        int yx;
        console ConsoleObj;
    public:
        line();
        line(int,int,int,int,int,int);
        ~line();
        bool setHCoord(int,int,int);
        bool setVCoord(int,int,int);
        /*will be used to draw a horizontal double line*/
        void hDLine();
        /*will be used to draw a veritcal double line*/
        void vDLine();
        /*will be used to draw a horizontal single line*/
        void hSLine();
        /*will be used to draw a vertical single line*/
        void vSLine();
};
#endif // LINE_H
