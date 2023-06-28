#include <easyx.h>
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <WinBase.h>
#include "flying chess.h"
using namespace std;

int main() {
	initgraph(1100, 830);
	setbkcolor(WHITE);
	cleardevice();
	start();
	return 0;
}