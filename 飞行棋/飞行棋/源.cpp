#include <iostream>
#include <easyx.h>
using namespace std;
int main() {
	initgraph(928,825);
	setbkcolor(WHITE);
	cleardevice();
	IMAGE img;
	loadimage(&img,L"./map.jpg");
	putimage(0, 0, &img);
	ExMessage msg;
	while (true) {
		if (peekmessage(&msg, EX_MOUSE)) {
			switch (msg.message) {
			case WM_LBUTTONDOWN:
			{
				if (msg.x > 400 && msg.x < 600 && msg.y>400 && msg.y < 600) {
					closegraph();
					return 0;
				}
				break;
			}
			default:break;
			}
		}
	}
	
	return 0;
}