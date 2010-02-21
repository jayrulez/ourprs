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
#include <windows.h>
#include <mmsystem.h>
#include "Media.h"

Media::Media()
{
}
Media::~Media()
{
}
void Media::play(char* f)
{
    PlaySound(f,NULL,SND_FILENAME|SND_ASYNC);
}
