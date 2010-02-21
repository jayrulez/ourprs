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
#ifndef FRAME_H
#define FRAME_H
#include "line.h"
#include <string>
#include "../core/console.h"

#define FRAME_ERROR 0x4000

#define SCREEN_FRAME "screen"
#define NORMAL_FRAME "normal"

/*The extended charcter ascii value for the top left corner of the single frame*/
#define SINGLE_TOP_LEFT 218

/*The extended charcter ascii value for the bottom right corner of the single frame*/
#define SINGLE_BOTTOM_RIGHT 217

/*The extended charcter ascii value for the bottom left corner of the single frame*/
#define SINGLE_BOTTOM_LEFT 192

/*The extended charcter ascii value for the top right of the single frame*/
#define SINGLE_TOP_RIGHT 191

/*The extended charcter ascii value for the top left corner of the double frame*/
#define DOUBLE_TOP_LEFT 201

/*The extended charcter ascii value for the bottom right of the double frame*/
#define DOUBLE_BOTTOM_RIGHT 188

/*The extended charcter ascii value for the bottom left corner of the double frame*/
#define DOUBLE_BOTTOM_LEFT 200

/*The extended charcter ascii value for the top right corner of the double frame*/
#define DOUBLE_TOP_RIGHT 187

/*  The extended charcter ascii value for the
    left corner of the double frame when making
    the header row.
*/
#define DOUBLE_LEFT_JOINT 199;

/*  The extended charcter ascii value for the
    right corner of the double frame when making
    the header row.
*/
#define DOUBLE_RIGHT_JOINT 182


/*  The extended charcter ascii value for the
    left corner of the single frame when making
    the header row.
*/
#define SINGLE_LEFT_JOINT 195;

/*  The extended charcter ascii value for the
    right corner of the single frame when making
    the header row.
*/
#define SINGLE_RIGHT_JOINT 180

#define STANDARD_FRAME_WIDTH 79

using namespace std;
class frame
{
private:
    int x1;
    int x2;
    int y1;
    int y2;
    string type;
	console ConsoleObj;
	line LineObj;
public:
    frame();
    frame(int,int,int,int,string);
    ~frame();
    bool SetFrame(int,int,int,int,string);
    void dFraming();
    void sFraming();
    void ResetScreenFrame();
};
#endif // FRAME_H
