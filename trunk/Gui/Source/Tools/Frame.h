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
#include "Line.h"
#include <string>
#ifdef _WIN32
	#include "../../Win32/Core/Console.h"
#endif
#include "../Screen/Screen.h"
#define FRAME_ERROR 0x4000

#define SCREEN_FRAME "Screen"
#define NORMAL_FRAME "normal"

/*The extended charcter ascii value for the top left corner of the single Frame*/
#define SINGLE_TOP_LEFT 218

/*The extended charcter ascii value for the bottom right corner of the single Frame*/
#define SINGLE_BOTTOM_RIGHT 217

/*The extended charcter ascii value for the bottom left corner of the single Frame*/
#define SINGLE_BOTTOM_LEFT 192

/*The extended charcter ascii value for the top right of the single Frame*/
#define SINGLE_TOP_RIGHT 191

/*The extended charcter ascii value for the top left corner of the double Frame*/
#define DOUBLE_TOP_LEFT 201

/*The extended charcter ascii value for the bottom right of the double Frame*/
#define DOUBLE_BOTTOM_RIGHT 188

/*The extended charcter ascii value for the bottom left corner of the double Frame*/
#define DOUBLE_BOTTOM_LEFT 200

/*The extended charcter ascii value for the top right corner of the double Frame*/
#define DOUBLE_TOP_RIGHT 187

/*  The extended charcter ascii value for the
    left corner of the double Frame when making
    the header row.
*/
#define DOUBLE_LEFT_JOINT 199;

/*  The extended charcter ascii value for the
    right corner of the double Frame when making
    the header row.
*/
#define DOUBLE_RIGHT_JOINT 182


/*  The extended charcter ascii value for the
    left corner of the single Frame when making
    the header row.
*/
#define SINGLE_LEFT_JOINT 195;

/*  The extended charcter ascii value for the
    right corner of the single Frame when making
    the header row.
*/
#define SINGLE_RIGHT_JOINT 180

#define STANDARD_FRAME_WIDTH 79
#define STANDARD_FRAME_HEIGHT 53

using namespace std;
class Frame
{
private:
    int x1;
    int x2;
    int y1;
    int y2;
    string type;
	Console ConsoleObj;
	Screen ScreenObj;
	Line LineObj;
public:
    Frame();
    Frame(int,int,int,int,string);
    ~Frame();
    bool SetFrame(int,int,int,int,string);
    void dFraming();
    void sFraming();
    void ResetScreenFrame();
    void KillDFraming();
    void CenteredSFraming(int,int);
};
#endif // FRAME_H
