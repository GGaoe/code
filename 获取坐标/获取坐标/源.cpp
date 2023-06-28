#include <easyx.h>
#include <iostream>
#include <ctime>
using namespace std;
int getDieRes() {
	return (rand() % 6) + 1;
}
int main() {
	initgraph(1100,830,EX_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	IMAGE img;
	loadimage(&img, L"./map.jpg");
	putimage(0, 0, &img);
	IMAGE img1;
	loadimage(&img1, L"./dieres.png");
	putimage(910, 550, &img1);
	IMAGE im;
	loadimage(&im, L"./move_0.png");
	putimage(894, 389, &im);
	
	while (1) {
		ExMessage msg;
		if (peekmessage(&msg, EX_MOUSE)) {
			switch (msg.message) {
			case WM_LBUTTONDOWN:
			{
				cout << msg.x << " " << msg.y << endl;
			}
			default:break;

			}
		}
		
	}

	return 0;
}