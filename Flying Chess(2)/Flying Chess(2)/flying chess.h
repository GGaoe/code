#ifndef Flying_chess_
#define Flying_chess_
#include <easyx.h>
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <WinBase.h>
using namespace std;
typedef struct square {
	int num;//��Ǹ��ӵı��
	int type;//��ע��������ǳ����ĸ��ӻ����м�ĸ��ӻ����յ�׶εĸ��ӵ�
	struct square* next;//��һ������
	int cur_plane_type;//����վ����������ϵ����ӵ���ɫ
	int x;
	int y;
}square;
square* head = NULL;
square* Createlist() { return head; }
typedef struct plane {
	int type;//����������Ӫ
	square* cur_pos;//�������ĸ�������
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
