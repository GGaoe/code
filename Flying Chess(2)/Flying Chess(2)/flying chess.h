#ifndef Flying_chess_
#define Flying_chess_
#include <easyx.h>
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <WinBase.h>
using namespace std;
typedef struct square {
	int num;//标记格子的编号
	int type;//标注这个格子是出生的格子还是中间的格子还是终点阶段的格子等
	struct square* next;//下一个格子
	int cur_plane_type;//现在站在这个格子上的棋子的颜色
	int x;
	int y;
}square;
square* head = NULL;
square* Createlist() { return head; }
typedef struct plane {
	int type;//棋子所属阵营
	square* cur_pos;//现在在哪个格子上
	square* home;
	int state;
}plane;
plane* Createplane() {}
bool onrunway(plane* q, int player) {}
int getDieRes() {}
int getDieResAI() {}
bool judge() {}
bool check_allout(int player) {}
bool check_oneout(int player) {}
void showplane() {}
bool check_canmove(int player) {}
void check_eat(int player, square* p) {}
void check_anyone(square* p, plane* q, int player) {}
void move(int player, int die_point) {}
void mode_3() {}
void start() {}


#endif
