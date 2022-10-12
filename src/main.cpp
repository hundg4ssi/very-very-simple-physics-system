#include <iostream>
#include <graphics.h>
#include <vector>

using namespace std;

int main()
{
	float posx = 100.00;
	float posy = 100.00;
	float pushforce = -0.1;
	float pushorignal = 0.1;
	float pullforce = 0.1;
	char backward = '+';

	int gd = DETECT, gm, color;
	initgraph(&gd, &gm, (char *)"");

	while(1+1==2)
	{
		circle(posx, posy, 10);
		posy += pullforce;
		pullforce = pullforce + 0.1;
		if (backward == '+')
		{
			posx += pushforce;
			pushforce = pushforce + 0.01;
			pushorignal = pushorignal + 0.01;
		}
		else if (backward == '-')
		{
			posx += pushforce;
			pushforce = pushforce - 0.01;
		}
		if (posy == 450.00 || posy > 450.00)
		{
			if (posy > 455) // change to 460 if bugy (recent change)
			{
				posy = 450;
			}
			pullforce = pullforce - 0.3;
			pullforce = -pullforce;
		}
		if (posx > 600 || posx == 600)
		{
			if (posx > 600)
			{
				posx = 590;
			}
			pushforce = -pushforce;
			backward = '-';
			pushforce = pushforce - 1.1;
			pushorignal = pushorignal - 0.7;
		}
		if (posx < 10)
		{
			if (posx < 19)
			{
				posx = 22;
			}
			pushforce = pushorignal;
			backward = '+';
			pushorignal = pushorignal - 0.7;
			pushforce = pushforce - 1.1;
		}
		delay(5);
		cleardevice();
	}

	getch();
	closegraph();
	return 0;
}