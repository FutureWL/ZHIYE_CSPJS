#include <stdio.h>
#include <easyx.h>
#include <math.h>

#define PI 3.14

int main() {
	initgraph(900, 600);
	setbkcolor(RED);
	cleardevice();

	setaspectratio(1, -1);
	setfillcolor(YELLOW);
	setpolyfillmode(WINDING);

	float starAttr[5][5] = {
		{150,150,60,PI / 2},
		{300,60,30,atan(3 / 5.0) + PI},
		{360,120,30,atan(1 / 7.0) + PI},
		{360,210,30,-atan(2 / 7.0) + PI},
		{300,270,30,-atan(4 / 5.0) + PI},
	};

	for (int i = 0; i < 5; i++) {
		setorigin(starAttr[i][0], starAttr[i][1]);
		double d = 2 * PI / 5;
		POINT pts[5];
		for (int j = 0; j < 5; j++) {
			pts[j].x = cos(starAttr[i][3] + j * d * 2) * starAttr[i][2];
			pts[j].y = sin(starAttr[i][3] + j * d * 2) * starAttr[i][2];
		}
		solidpolygon(pts, 5);
	}

	system("pause");
	return 0;
}
