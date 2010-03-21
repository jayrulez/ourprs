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

#include "./config.h"
#ifndef _APPLICATION_H
#include "./Base/Application.h"
#endif
using namespace std;

/*
 * @ main
 * @ return int Application::run()
 */
int main()
{
	Application *app = new Application();
	return app->run();
}
