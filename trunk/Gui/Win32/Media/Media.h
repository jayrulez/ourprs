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
#ifndef MEDIA_H
#define MEDIA_H

#define ExtendedMenuSound "../../Source/Media/Sounds/buttons/ExtendedMenuSound.wav"
#define MenuScrollSound	"../../Source/Media/Sounds/buttons/MenuScrollSound.wav"
#define MenuSelectSound "../../Source/Media/Sounds/buttons/MenuSelectSound.wav"
#define ScreenChangeSound "../../Source/Media/Sounds/buttons/ScreenChangeSound.wav"

class Media
{
public:
    Media();
    ~Media();
    void PlayWav(char*);
};
#endif // MEDIA_H
