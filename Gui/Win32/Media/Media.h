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

#define ExtendedMenuSound "../Source/Media/Sounds/Buttons/ExtendedMenuSound.wav"

class Media
{
public:
    Media();
    ~Media();
    void play(char*);
};
#endif // MEDIA_H
