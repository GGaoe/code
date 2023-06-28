#include <easyx.h>
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <WinBase.h>
using namespace std;

bool game_ends = 0;//标记是否有玩家完成比赛
int player = -1;
int oneout[4];
int allout[4];
bool Debug =0;

typedef struct square {
	int num;//标记格子的编号
	int type;//标注这个格子是出生的格子还是中间的格子还是终点阶段的格子等
	struct square* next;//下一个格子
	int cur_plane_type;//现在站在这个格子上的棋子的颜色
	int x;
	int y;
}square;
square* head = NULL;
square* start_0 = new square;
square* start_1 = new square;
square* start_2 = new square;
square* start_3 = new square;
square* home_0_1 = new square; square* home_0_2 = new square;
square* home_0_3 = new square; square* home_0_4 = new square;
square* home_1_1 = new square; square* home_1_2 = new square;
square* home_1_3 = new square; square* home_1_4 = new square;
square* home_2_1 = new square; square* home_2_2 = new square;
square* home_2_3 = new square; square* home_2_4 = new square;
square* home_3_1 = new square; square* home_3_2 = new square;
square* home_3_3 = new square; square* home_3_4 = new square;
square* runway_0_1 = new square; square* runway_0_2 = new square;
square* runway_0_3 = new square; square* runway_0_4 = new square;
square* runway_0_5 = new square;
square* runway_1_1 = new square; square* runway_1_2 = new square;
square* runway_1_3 = new square; square* runway_1_4 = new square;
square* runway_1_5 = new square;
square* runway_2_1 = new square; square* runway_2_2 = new square;
square* runway_2_3 = new square; square* runway_2_4 = new square;
square* runway_2_5 = new square;
square* runway_3_1 = new square; square* runway_3_2 = new square;
square* runway_3_3 = new square; square* runway_3_4 = new square;
square* runway_3_5 = new square;

square* Createlist()
{
	int count = 1;
	for (int i = 1; i <= 52; i++) {
		square* p = new square;
		if (head == NULL) {
			head = p;
			p->next = NULL;
			p->num = count;
			int a = (count - 1) % 4;
			p->type = a;
			count++;
		}
		else {
			square* w = head;
			while (w->next != NULL) {
				w = w->next;
			}w->next = p;
			p->num = count;
			int a = (count - 1) % 4;
			p->type = a;
			count++;
			p->next = NULL;
		}
	}
	square* w = head;
	while (w->next != NULL)
	{
		w = w->next;
	}
	w->next = head;
	
	//建立环内的链表
	{square* p = head;
	p = p->next;
	p->x = 195; p->y = 290;	p = p->next;
	p->x = 236; p->y = 290; p = p->next;
	p->x = 275; p->y = 307; p = p->next;
	p->x = 312; p->y = 271; p = p->next;
	p->x = 293; p->y = 226; p = p->next;
	p->x = 294; p->y = 187; p = p->next;
	p->x = 312; p->y = 143; p = p->next;
	p->x = 356; p->y = 126; p = p->next;
	p->x = 394; p->y = 129; p = p->next;
	p->x = 434; p->y = 127; p = p->next;
	p->x = 474; p->y = 127; p = p->next;
	p->x = 513; p->y = 126; p = p->next;
	p->x = 557; p->y = 142; p = p->next;
	p->x = 573; p->y = 188; p = p->next;
	p->x = 573; p->y = 228; p = p->next;
	p->x = 557; p->y = 270; p = p->next;
	p->x = 593; p->y = 308; p = p->next;
	p->x = 634; p->y = 289; p = p->next;
	p->x = 673; p->y = 289; p = p->next;
	p->x = 716; p->y = 307; p = p->next;
	p->x = 730; p->y = 349; p = p->next;
	p->x = 730; p->y = 390; p = p->next;
	p->x = 731; p->y = 430; p = p->next;
	p->x = 730; p->y = 470; p = p->next;
	p->x = 731; p->y = 510; p = p->next;
	p->x = 715; p->y = 553; p = p->next;
	p->x = 672; p->y = 571; p = p->next;
	p->x = 634; p->y = 572; p = p->next;
	p->x = 592; p->y = 554; p = p->next;
	p->x = 557; p->y = 589; p = p->next;
	p->x = 573; p->y = 635; p = p->next;
	p->x = 573; p->y = 674; p = p->next;
	p->x = 556; p->y = 720; p = p->next;
	p->x = 513; p->y = 734; p = p->next;
	p->x = 472; p->y = 734; p = p->next;
	p->x = 434; p->y = 733; p = p->next;
	p->x = 393; p->y = 732; p = p->next;
	p->x = 354; p->y = 733; p = p->next;
	p->x = 312; p->y = 717; p = p->next;
	p->x = 295; p->y = 674; p = p->next;
	p->x = 294; p->y = 634; p = p->next;
	p->x = 312; p->y = 589; p = p->next;
	p->x = 277; p->y = 553; p = p->next;
	p->x = 234; p->y = 571; p = p->next;
	p->x = 196; p->y = 572; p = p->next;
	p->x = 154; p->y = 553; p = p->next;
	p->x = 138; p->y = 510; p = p->next;
	p->x = 139; p->y = 470; p = p->next;
	p->x = 140; p->y = 428; p = p->next;
	p->x = 140; p->y = 391; p = p->next;
	p->x = 138; p->y = 350; p = p->next;
	p->x = 153; p->y = 306;
	}
	//建立起点
	{start_0->x = 94; start_0->y = 275;
	start_1->x = 578; start_1->y = 82;
	start_2->x = 764; start_2->y = 585;
	start_3->x = 279; start_3->y = 775;
	square* r = head;
	r = r->next;
	start_0->next = r;
	for (int i = 1; i <= 13; i++) { r = r->next; }
	start_1->next = r;
	for (int i = 1; i <= 13; i++) { r = r->next; }
	start_2->next = r;
	for (int i = 1; i <= 13; i++) { r = r->next; }
	start_3->next = r;
	}
	//建立机场
	{
		home_0_1->x = 137; home_0_1->y = 130; home_0_1->next = start_0;
		home_0_2->x = 200; home_0_2->y = 131; home_0_2->next = start_0;
		home_0_3->x = 135; home_0_3->y = 191; home_0_3->next = start_0;
		home_0_4->x = 199; home_0_4->y = 190; home_0_4->next = start_0;
		home_1_1->x = 663; home_1_1->y = 126; home_1_1->next = start_1;
		home_1_2->x = 724; home_1_2->y = 129; home_1_2->next = start_1;
		home_1_3->x = 662; home_1_3->y = 192; home_1_3->next = start_1;
		home_1_4->x = 722; home_1_4->y = 192; home_1_4->next = start_1;
		home_2_1->x = 663; home_2_1->y = 670; home_2_1->next = start_2;
		home_2_2->x = 725; home_2_2->y = 672; home_2_2->next = start_2;
		home_2_3->x = 662; home_2_3->y = 731; home_2_3->next = start_2;
		home_2_4->x = 725; home_2_4->y = 734; home_2_4->next = start_2;
		home_3_1->x = 136; home_3_1->y = 670; home_3_1->next = start_3;
		home_3_2->x = 199; home_3_2->y = 669; home_3_2->next = start_3;
		home_3_3->x = 136; home_3_3->y = 732; home_3_3->next = start_3;
		home_3_4->x = 196; home_3_4->y = 732; home_3_4->next = start_3;
	}
	//建立跑道
	{runway_0_1->x = 194; runway_0_1->y = 430;
	runway_0_1->num = 1; runway_0_1->next = runway_0_2;
	runway_0_2->x = 234; runway_0_2->y = 430;
	runway_0_2->num = 2; runway_0_2->next = runway_0_3;
	runway_0_3->x = 273; runway_0_3->y = 432;
	runway_0_3->num = 3; runway_0_3->next = runway_0_4;
	runway_0_4->x = 314; runway_0_4->y = 430;
	runway_0_4->num = 4; runway_0_4->next = runway_0_5;
	runway_0_5->x = 353; runway_0_5->y = 430;
	runway_0_5->num = 5; runway_1_1->x = 433; runway_1_1->y = 185;
	runway_1_1->num = 1; runway_1_1->next = runway_1_2;
	runway_1_2->x = 434; runway_1_2->y = 224;
	runway_1_2->num = 2; runway_1_2->next = runway_1_3;
	runway_1_3->x = 433; runway_1_3->y = 265;
	runway_1_3->num = 3; runway_1_3->next = runway_1_4;
	runway_1_4->x = 434; runway_1_4->y = 307;
	runway_1_4->num = 4; runway_1_4->next = runway_1_5;
	runway_1_5->x = 433; runway_1_5->y = 347;
	runway_1_5->num = 5; runway_2_1->x = 671; runway_2_1->y = 429;
	runway_2_1->num = 1; runway_2_1->next = runway_2_2;
	runway_2_2->x = 631; runway_2_2->y = 430;
	runway_2_2->num = 2; runway_2_2->next = runway_2_3;
	runway_2_3->x = 593; runway_2_3->y = 431;
	runway_2_3->num = 3; runway_2_3->next = runway_2_4;
	runway_2_4->x = 553; runway_2_4->y = 429;
	runway_2_4->num = 4; runway_2_4->next = runway_2_5;
	runway_2_5->x = 515; runway_2_5->y = 429;
	runway_2_5->num = 5; 
	runway_3_1->x = 433; runway_3_1->y = 677;
	runway_3_1->num = 1; runway_3_1->next = runway_3_2;
	runway_3_2->x = 435; runway_3_2->y = 635;
	runway_3_2->num = 2; runway_3_2->next = runway_3_3;
	runway_3_3->x = 434; runway_3_3->y = 595;
	runway_3_3->num = 3; runway_3_3->next = runway_3_4;
	runway_3_4->x = 435; runway_3_4->y = 553;
	runway_3_4->num = 4; runway_3_4->next = runway_3_5;
	runway_3_5->x = 434; runway_3_5->y = 513;
	runway_3_5->num = 5; 
	}
	return head;
}

typedef struct plane {
	int type;//棋子所属阵营
	square* cur_pos;//现在在哪个格子上
	square* home;
	int state;
}plane;
plane* a_0_1 = new plane;
plane* a_0_2 = new plane;
plane* a_0_3 = new plane;
plane* a_0_4 = new plane;
plane* a_1_1 = new plane;
plane* a_1_2 = new plane;
plane* a_1_3 = new plane;
plane* a_1_4 = new plane;
plane* a_2_1 = new plane;
plane* a_2_2 = new plane;
plane* a_2_3 = new plane;
plane* a_2_4 = new plane;
plane* a_3_1 = new plane;
plane* a_3_2 = new plane;
plane* a_3_3 = new plane;
plane* a_3_4 = new plane;

plane* Createplane() {
	a_0_1->type = 0;
	a_0_1->cur_pos = home_0_1;
	a_0_1->home = home_0_1;
	a_0_1->state = 0;
	a_0_2->type = 0;
	a_0_2->cur_pos = home_0_2;
	a_0_2->home = home_0_2;
	a_0_2->state = 0;
	a_0_3->type = 0;
	a_0_3->cur_pos = home_0_3;
	a_0_3->home = home_0_3;
	a_0_3->state = 0;
	a_0_4->type = 0;
	a_0_4->cur_pos = home_0_4;
	a_0_4->home = home_0_4;
	a_0_4->state = 0;
	a_1_1->type = 1;
	a_1_1->cur_pos = home_1_1;
	a_1_1->home = home_1_1;
	a_1_1->state = 0;
	a_1_2->type = 1;
	a_1_2->cur_pos = home_1_2;
	a_1_2->home = home_1_2;
	a_1_2->state = 0;
	a_1_3->type = 1;
	a_1_3->cur_pos = home_1_3;
	a_1_3->home = home_1_3;
	a_1_3->state = 0;
	a_1_4->type = 1;
	a_1_4->cur_pos = home_1_4;
	a_1_4->home = home_1_4;
	a_1_4->state = 0;
	a_2_1->type = 2;
	a_2_1->cur_pos = home_2_1;
	a_2_1->home = home_2_1;
	a_2_1->state = 0;
	a_2_2->type = 2;
	a_2_2->cur_pos = home_2_2;
	a_2_2->home = home_2_2;
	a_2_2->state = 0;
	a_2_3->type = 2;
	a_2_3->cur_pos = home_2_3;
	a_2_3->home = home_2_3;
	a_2_3->state = 0;
	a_2_4->type = 2;
	a_2_4->cur_pos = home_2_4;
	a_2_4->home = home_2_4;
	a_2_4->state = 0;
	a_3_1->type = 3;
	a_3_1->cur_pos = home_3_1;
	a_3_1->home = home_3_1;
	a_3_1->state = 0;
	a_3_2->type = 3;
	a_3_2->cur_pos = home_3_2;
	a_3_2->home = home_3_2;
	a_3_2->state = 0;
	a_3_3->type = 3;
	a_3_3->cur_pos = home_3_3;
	a_3_3->home = home_3_3;
	a_3_3->state = 0;
	a_3_4->type = 3;
	a_3_4->cur_pos = home_3_4;
	a_3_4->home = home_3_4;
	a_3_4->state = 0;
	return a_0_1;
}

bool onrunway(plane* q, int player) {
	bool flag1 = 0;
	if (player == 0) {
		square* a = runway_0_1;
		if (q->cur_pos == a)flag1 = 1;
		for (int i = 1; i <= 4; i++) {
			a = a->next;
			if (q->cur_pos == a)flag1 = 1;
		}
	}
	if (player == 1) {
		square* a = runway_1_1;
		if (q->cur_pos == a)flag1 = 1;
		for (int i = 1; i <= 4; i++) {
			a = a->next;
			if (q->cur_pos == a)flag1 = 1;
		}
	}
	if (player == 2) {
		square* a = runway_2_1;
		if (q->cur_pos == a)flag1 = 1;
		for (int i = 1; i <= 4; i++) {
			a = a->next;
			if (q->cur_pos == a)flag1 = 1;
		}
	}
	if (player == 3) {
		square* a = runway_3_1;
		if (q->cur_pos == a)flag1 = 1;
		for (int i = 1; i <= 4; i++) {
			a = a->next;
			if (q->cur_pos == a)flag1 = 1;
		}
	}
	return flag1;
}

int getDieRes() //骰子
{
	int random = 0;
	IMAGE img;
	if (Debug) 
	{
		cin >> random;
		switch (random) {
		case 1: {
			loadimage(&img, L"./dieres1.png");
			break;
		}
		case 2: {
			loadimage(&img, L"./dieres2.png");
			break;
		}
		case 3: {
			loadimage(&img, L"./dieres3.png");
			break;
		}
		case 4: {
			loadimage(&img, L"./dieres4.png");
			break;
		}
		case 5: {
			loadimage(&img, L"./dieres5.png");
			break;
		}
		case 6: {
			loadimage(&img, L"./dieres6.png");
			break;
		}
		putimage(910, 550, &img);
	}
}
	else {
		while (1) {
			bool flag = 0;
			ExMessage msg;
			if (peekmessage(&msg, EX_MOUSE)) {
				switch (msg.message) {
				case WM_LBUTTONDOWN:
				{
					if (msg.x >= 910 && msg.x <= 1021 && msg.y >= 550 && msg.y <= 650) {
						flag = 1;
						srand(time(0));
						random = (rand() % 6) + 1;
						switch (random) {
						case 1: {
							loadimage(&img, L"./dieres1.png");
							break;
						}
						case 2: {
							loadimage(&img, L"./dieres2.png");
							break;
						}
						case 3: {
							loadimage(&img, L"./dieres3.png");
							break;
						}
						case 4: {
							loadimage(&img, L"./dieres4.png");
							break;
						}
						case 5: {
							loadimage(&img, L"./dieres5.png");
							break;
						}
						case 6: {
							loadimage(&img, L"./dieres6.png");
							break;
						}
						}
					}
				}
				default:break;
				}
				if (flag) {
					putimage(910, 550, &img);
					break;
				}
			}

		}
	}
	return random;
}

int getDieResAI() {
	int random = 0;
	IMAGE img;
	srand(time(0));
	random = (rand() % 6) + 1;
	switch (random) {
	case 1: {
		loadimage(&img, L"./dieres1.png");
		break;
	}
	case 2: {
		loadimage(&img, L"./dieres2.png");
		break;
	}
	case 3: {
		loadimage(&img, L"./dieres3.png");
		break;
	}
	case 4: {
		loadimage(&img, L"./dieres4.png");
		break;
	}
	case 5: {
		loadimage(&img, L"./dieres5.png");
		break;
	}
	case 6: {
		loadimage(&img, L"./dieres6.png");
		break;
	}
	}
	putimage(910, 550, &img);
	return random;
}

bool judge() 
{
	bool fin1=0, fin2=0, fin3=0, fin4=0;
	if (a_0_1->state == 2 && a_0_2->state == 2 && a_0_3->state == 2 && a_0_4->state == 2)fin1 = 1;
	if (a_1_1->state == 2 && a_1_2->state == 2 && a_1_3->state == 2 && a_1_4->state == 2)fin2 = 1;
	if (a_2_1->state == 2 && a_2_2->state == 2 && a_2_3->state == 2 && a_2_4->state == 2)fin3 = 1;
	if (a_3_1->state == 2 && a_3_2->state == 2 && a_3_3->state == 2 && a_3_4->state == 2)fin4 = 1;
	if (fin1 || fin2 || fin3 || fin4)return true;
	else return false;
}

bool check_allout(int player) {
	if (player == 0) {
		if (a_0_1->state != 0 && a_0_2->state != 0 && a_0_3->state != 0 && a_0_4->state != 0)return 1;
		else return 0;
	}
	else if (player == 1) {
		if (a_1_1->state != 0 && a_1_2->state != 0 && a_1_3->state != 0 && a_1_4->state != 0)return 1;
		else return 0;
	}
	else if (player == 2) {
		if (a_2_1->state != 0 && a_2_2->state != 0 && a_2_3->state != 0 && a_2_4->state != 0)return 1;
		else return 0;
	}
	else if (player == 3) {
		if (a_3_1->state != 0 && a_3_2->state != 0 && a_3_3->state != 0 && a_3_4->state != 0)return 1;
		else return 0;
	}
}

bool check_oneout(int player) {
	if (player == 0) {
		if (a_0_1->state != 0 || a_0_2->state != 0 || a_0_3->state != 0 || a_0_4->state != 0)return 1;
		else return 0;
	}
	else if (player == 1) {
		if (a_1_1->state != 0 || a_1_2->state != 0 || a_1_3->state != 0 || a_1_4->state != 0)return 1;
		else return 0;
	}
	else if (player == 2) {
		if (a_2_1->state != 0 || a_2_2->state != 0 || a_2_3->state != 0 || a_2_4->state != 0)return 1;
		else return 0;
	}
	else if (player == 3) {
		if (a_3_1->state != 0 || a_3_2->state != 0 || a_3_3->state != 0 || a_3_4->state != 0)return 1;
		else return 0;
	}
}

void showplane() {
	if (a_0_1->state != 2&&a_0_1->cur_pos!=NULL) {
		IMAGE a1;
		loadimage(&a1, L"./yellow.png");
		putimage(a_0_1->cur_pos->x, a_0_1->cur_pos->y, &a1);
	}
	if (a_0_2->state != 2 && a_0_2->cur_pos != NULL) {
		IMAGE a2;
		loadimage(&a2, L"./yellow.png");
		putimage(a_0_2->cur_pos->x, a_0_2->cur_pos->y, &a2);
	}
	if (a_0_3->state != 2 && a_0_3->cur_pos != NULL) {
		IMAGE a3;
		loadimage(&a3, L"./yellow.png");
		putimage(a_0_3->cur_pos->x, a_0_3->cur_pos->y, &a3);
	}
	if (a_0_4->state != 2 && a_0_4->cur_pos != NULL) {
		IMAGE a4;
		loadimage(&a4, L"./yellow.png");
		putimage(a_0_4->cur_pos->x, a_0_4->cur_pos->y, &a4);
	}
	if (a_1_1->state != 2 && a_1_1->cur_pos != NULL) {
		IMAGE b1;
		loadimage(&b1, L"./blue.png");
		putimage(a_1_1->cur_pos->x, a_1_1->cur_pos->y, &b1);
	}
	if (a_1_2->state != 2 && a_1_2->cur_pos != NULL) {
		IMAGE b2;
		loadimage(&b2, L"./blue.png");
		putimage(a_1_2->cur_pos->x, a_1_2->cur_pos->y, &b2);
	}
	if (a_1_3->state != 2 && a_1_3->cur_pos != NULL) {
		IMAGE b3;
		loadimage(&b3, L"./blue.png");
		putimage(a_1_3->cur_pos->x, a_1_3->cur_pos->y, &b3);
	}
	if (a_1_4->state != 2 && a_1_4->cur_pos != NULL) {
		IMAGE b4;
		loadimage(&b4, L"./blue.png");
		putimage(a_1_4->cur_pos->x, a_1_4->cur_pos->y, &b4);
	}if (a_2_1->state != 2 && a_2_1->cur_pos != NULL) {
		IMAGE c1;
		loadimage(&c1, L"./red.png");
		putimage(a_2_1->cur_pos->x, a_2_1->cur_pos->y, &c1);
	}
	if (a_2_2->state != 2 && a_2_2->cur_pos != NULL) {
		IMAGE c2;
		loadimage(&c2, L"./red.png");
		putimage(a_2_2->cur_pos->x, a_2_2->cur_pos->y, &c2);
	}
	if (a_2_3->state != 2 && a_2_3->cur_pos != NULL) {
		IMAGE c3;
		loadimage(&c3, L"./red.png");
		putimage(a_2_3->cur_pos->x, a_2_3->cur_pos->y, &c3);
	}
	if (a_2_4->state != 2 && a_2_4->cur_pos != NULL) {
		IMAGE c4;
		loadimage(&c4, L"./red.png");
		putimage(a_2_4->cur_pos->x, a_2_4->cur_pos->y, &c4);
	}
	if (a_3_1->state != 2 && a_3_1->cur_pos != NULL) {
		IMAGE d1;
		loadimage(&d1, L"./green.png");
		putimage(a_3_1->cur_pos->x, a_3_1->cur_pos->y, &d1);
	}
	if (a_3_2->state != 2 && a_3_2->cur_pos != NULL) {
		IMAGE d2;
		loadimage(&d2, L"./green.png");
		putimage(a_3_2->cur_pos->x, a_3_2->cur_pos->y, &d2);
	}
	if (a_3_3->state != 2 && a_3_3->cur_pos != NULL) {
		IMAGE d3;
		loadimage(&d3, L"./green.png");
		putimage(a_3_3->cur_pos->x, a_3_3->cur_pos->y, &d3);
	}
	if (a_3_4->state != 2 && a_3_4->cur_pos != NULL) {
		IMAGE d4;
		loadimage(&d4, L"./green.png");
		putimage(a_3_4->cur_pos->x, a_3_4->cur_pos->y, &d4);
	}
}

bool check_canmove(int player) {
	if (player == 0) {
		if (a_0_1->state !=1&&a_0_2->state != 1 && a_0_3->state != 1 && a_0_4->state != 1)return 1;
		else return 0;
	}
	else if (player == 1) {
		if (a_1_1->state != 1 && a_1_2->state != 1 && a_1_3->state != 1 && a_1_4->state != 1)return 1;
		else return 0;
	}
	else if (player == 2) {
		if (a_2_1->state != 1 && a_2_2->state != 1 && a_2_3->state != 1 && a_2_4->state != 1)return 1;
		else return 0;
	}
	else if (player == 3) {
		if (a_3_1->state != 1 && a_3_2->state != 1 && a_3_3->state != 1 && a_3_4->state != 1)return 1;
		else return 0;
	}

}

void check_eat(int player,square*p) {
	if (p == NULL)return;
	if (player != 0) {
		if (a_0_1->cur_pos->num == p->num) {
			a_0_1->cur_pos = a_0_1->home;
			a_0_1->state = 0;
			allout[0] = 0;
			showplane();
			if(!check_oneout(0))oneout[0]=0;
		}
		if (a_0_2->cur_pos->num == p->num) {
			a_0_2->cur_pos = a_0_2->home;
			a_0_2->state = 0;
			allout[0] = 0;
			showplane();
			if (!check_oneout(0))oneout[0] = 0;
		}
		if (a_0_3->cur_pos->num == p->num) {
			a_0_3->cur_pos = a_0_3->home;
			a_0_3->state = 0;
			allout[0] = 0;
			showplane();
			if (!check_oneout(0))oneout[0] = 0;
		}
		if (a_0_4->cur_pos->num == p->num) {
			a_0_4->cur_pos = a_0_4->home;
			a_0_4->state = 0;
			allout[0] = 0;
			showplane();
			if (!check_oneout(0))oneout[0] = 0;
		}
	}
	if (player != 1) {
		if (a_1_1->cur_pos->num == p->num) {
			a_1_1->cur_pos = a_1_1->home;
			a_1_1->state = 0;
			allout[1] = 0;
			showplane();
			if (!check_oneout(1))oneout[1] = 0;
		}
		if (a_1_2->cur_pos->num == p->num) {
			a_1_2->cur_pos = a_1_2->home;
			a_1_2->state = 0;
			allout[1] = 0;
			showplane();
			if (!check_oneout(1))oneout[1] = 0;
		}
		if (a_1_3->cur_pos->num == p->num) {
			a_1_3->cur_pos = a_1_3->home;
			a_1_3->state = 0;
			allout[1] = 0;
			showplane();
			if (!check_oneout(1))oneout[1] = 0;
		}
		if (a_1_4->cur_pos->num == p->num) {
			a_1_4->cur_pos = a_1_4->home;
			a_1_4->state = 0;
			allout[1] = 0;
			showplane();
			if (!check_oneout(1))oneout[1] = 0;
		}
	}
	if (player != 2) {
		if (a_2_1->cur_pos->num == p->num) {
			a_2_1->cur_pos = a_2_1->home;
			a_2_1->state = 0;
			allout[2] = 0;
			showplane();
			if (!check_oneout(2))oneout[2] = 0;
		}
		if (a_2_2->cur_pos->num == p->num) {
			a_2_2->cur_pos = a_2_2->home;
			a_2_2->state = 0;
			allout[2] = 0;
			showplane();
			if (!check_oneout(2))oneout[2] = 0;
		}
		if (a_2_3->cur_pos->num == p->num) {
			a_2_3->cur_pos = a_2_3->home;
			a_2_3->state = 0;
			allout[2] = 0;
			showplane();
			if (!check_oneout(2))oneout[2] = 0;
		}
		if (a_2_4->cur_pos->num == p->num) {
			a_2_4->cur_pos = a_2_4->home;
			a_2_4->state = 0;
			allout[2] = 0;
			showplane();
			if (!check_oneout(2))oneout[2] = 0;
		}
	}
	if (player != 3) {
		if (a_3_1->cur_pos->num == p->num) {
			a_3_1->cur_pos = a_3_1->home;
			a_3_1->state = 0;
			allout[3] = 0;
			showplane();
			if (!check_oneout(3))oneout[3] = 0;
		}
		if (a_3_2->cur_pos->num == p->num) {
			a_3_2->cur_pos = a_3_2->home;
			a_3_2->state = 0;
			allout[3] = 0;
			showplane();
			if (!check_oneout(3))oneout[3] = 0;
		}
		if (a_3_3->cur_pos->num == p->num) {
			a_3_3->cur_pos = a_3_3->home;
			a_3_3->state = 0;
			allout[3] = 0;
			showplane();
			if (!check_oneout(3))oneout[3] = 0;
		}
		if (a_3_4->cur_pos->num == p->num) {
			a_3_4->cur_pos = a_3_4->home;
			a_3_4->state = 0;
			allout[3] = 0;
			showplane();
			if (!check_oneout(3))oneout[3] = 0;
		}
	}
}

void check_anyone(square*p,plane*q,int player) {
	if (player == 0) {
		if ((q == a_0_1 || a_0_1->cur_pos != p) && (q == a_0_2 || a_0_2->cur_pos != p)
			&& (q == a_0_3 || a_0_3->cur_pos != p) && (q == a_0_4 || a_0_4->cur_pos != p))
		{
			IMAGE cover;
			loadimage(&cover, L"./cover.png");
			putimage(p->x,p->y, &cover);
		}

	}
	if (player == 1) {
		if ((q == a_1_1 || a_1_1->cur_pos != p) && (q == a_1_2 || a_1_2->cur_pos != p)
			&& (q == a_1_3 || a_1_3->cur_pos != p) && (q == a_1_4 || a_1_4->cur_pos != p))
		{
			IMAGE a1;
			loadimage(&a1, L"./cover.png");
			putimage(q->cur_pos->x, q->cur_pos->y, &a1);
		}

	}
	if (player == 2) {
		if ((q == a_2_1 || a_2_1->cur_pos != p) && (q == a_2_2 || a_2_2->cur_pos != p)
			&& (q == a_2_3 || a_2_3->cur_pos != p) && (q == a_2_4 || a_2_4->cur_pos != p))
		{
			IMAGE a1;
			loadimage(&a1, L"./cover.png");
			putimage(q->cur_pos->x, q->cur_pos->y, &a1);
		}

	}
	if (player == 3) {
		if ((q == a_3_1 || a_3_1->cur_pos != p) && (q == a_3_2 || a_3_2->cur_pos != p)
			&& (q == a_3_3 || a_3_3->cur_pos != p) && (q == a_3_4 || a_3_4->cur_pos != p))
		{
			IMAGE a1;
			loadimage(&a1, L"./cover.png");
			putimage(q->cur_pos->x, q->cur_pos->y, &a1);
		}

	}

}

void move(int player,int die_point) 
{
	IMAGE no;
	loadimage(&no, L"./noone.png");
	IMAGE white;
	loadimage(&white, L"./white.png");
	IMAGE cant;
	loadimage(&cant, L"./cantmove.png");
	IMAGE succ;
	loadimage(&succ, L"./canmove.png");
	
	
	IMAGE img;
	switch (player) {
	case 0:
		loadimage(&img, L"./move_2.png");
		putimage(894, 389, &img);
		break;
	case 1:
		loadimage(&img, L"./move_1.png");
		putimage(894, 389, &img);
		break;
	case 2:
		loadimage(&img, L"./move_0.png");
		putimage(894, 389, &img);
		break;
	case 3:
		loadimage(&img, L"./move_3.png");
		putimage(894, 389, &img);
		break;
	default:break;
}
	if (player == 0) {
		bool moved = 0;
		if (die_point != 6 &&check_canmove(0)) {
			
			return;
		}
		else if (die_point == 6 && !allout[player]) {
			while (1) {
				ExMessage msg;
				if (peekmessage(&msg, EX_MOUSE)) {
					switch (msg.message) {
					case WM_LBUTTONDOWN:
					{
						if (msg.x >= 897 && msg.x <= 959 && msg.y >= 394 && msg.y <= 457 && a_0_1->state == 0) {
							check_anyone(a_0_1->cur_pos, a_0_1, 0);
							a_0_1->cur_pos = start_0;
							int random = getDieRes();
							for (int i = 1; i <= random; i++) {
								a_0_1->cur_pos = a_0_1->cur_pos->next;
							}oneout[player] = 1;
							a_0_1->state = 1;
							if (check_allout(0))allout[player] = 1;
							check_eat(0, a_0_1->cur_pos);
							moved = 1;
							break;
							
						}
						else if (msg.x >= 971 && msg.x <= 1031 && msg.y >= 397 && msg.y <= 456 && a_0_2->state == 0) {
							check_anyone(a_0_2->cur_pos, a_0_2, 0);
							a_0_2->cur_pos = start_0;
							int random = getDieRes();
							for (int i = 1; i <= random; i++) {
								a_0_2->cur_pos = a_0_2->cur_pos->next;
							}oneout[player] = 1;
							a_0_2->state = 1;
							if (check_allout(0))allout[player] = 1;
							check_eat(0, a_0_2->cur_pos);
							moved = 1;
							break;
							
						}
						else if (msg.x >= 897 && msg.x <= 960 && msg.y >= 464 && msg.y <= 526 && a_0_3->state == 0) {
							check_anyone(a_0_3->cur_pos, a_0_3, 0);
							a_0_3->cur_pos = start_0;
							int random = getDieRes();
							for (int i = 1; i <= random; i++) {
								a_0_3->cur_pos = a_0_3->cur_pos->next;
							}oneout[player] = 1;
							a_0_3->state = 1;
							if (check_allout(0))allout[player] = 1;
							check_eat(0, a_0_3->cur_pos);
							moved = 1;
							break;
							
						}
						else if (msg.x >= 971 && msg.x <= 1033 && msg.y >= 468 && msg.y <= 529 && a_0_4->state == 0) {
							check_anyone(a_0_4->cur_pos, a_0_4, 0);
							a_0_4->cur_pos = start_0;
							int random = getDieRes();
							for (int i = 1; i <= random; i++) {
								a_0_4->cur_pos = a_0_4->cur_pos->next;
							}oneout[player] = 1;
							a_0_4->state = 1;
							if (check_allout(0))allout[player] = 1;
							check_eat(0, a_0_4->cur_pos);
							moved = 1;
							break;
							
						}
					default:break;
					}
					}
					if (moved)return;
				}
			}
		}
		else if(die_point!=6&&!allout[player]&&oneout[player]){
			while (1) {
				ExMessage msg;
				if (peekmessage(&msg, EX_MOUSE)) {
					switch (msg.message) {
					case WM_LBUTTONDOWN:
					{
						if (msg.x >= 897 && msg.x <= 959 && msg.y >= 394 && msg.y <= 457 && a_0_1->state == 1) {
							check_anyone(a_0_1->cur_pos, a_0_1, 0);
							moved = 1;
							if (onrunway(a_0_1, 0)) {
								if (die_point == 6 - a_0_1->cur_pos->num) {
									a_0_1->cur_pos = NULL;
									a_0_1->state = 2;
								}
								else {
									square* t = runway_0_1;
									int a; 
									if (a_0_1->cur_pos->num + die_point > 6)a = 12 - (a_0_1->cur_pos->num + die_point);
									else a = a_0_1->cur_pos->num + die_point;
									for (int i = 1; i < a; i++)
									{
										t = t->next;
									}
									square* n = t;
									a_0_1->cur_pos = n;
								}

							}
							else {
								for (int i = 1; i <= die_point; i++) {
									bool flag = 0;
									if (a_0_1->cur_pos->num == 50) {
										flag = 1;
										a_0_1->cur_pos = runway_0_1;
										if (die_point == 6) {
											a_0_1->cur_pos = NULL; a_0_1->state = 2;
										}
										else {
											for (int j = 1; j <= die_point - i; j++) {
												a_0_1->cur_pos = a_0_1->cur_pos->next;
											}
										}
									}
									if (flag)break;
									a_0_1->cur_pos = a_0_1->cur_pos->next;
								}
								oneout[player] = 1;
								a_0_1->state = 1;
								if (check_allout(0))allout[player] = 1;
								check_eat(0, a_0_1->cur_pos);
								moved = 1;
								break;
							}
						}
						else if (msg.x >= 971 && msg.x <= 1031 && msg.y >= 397 && msg.y <= 456 && a_0_2->state == 1) {
							check_anyone(a_0_2->cur_pos, a_0_2, 0);
							moved = 1;
							if (onrunway(a_0_2, 0)) {
								if (die_point == 6 - a_0_2->cur_pos->num) {
									a_0_2->cur_pos = NULL;
									a_0_2->state = 2;
								}
								else {
									square* t = runway_0_1;
									int a; if (a_0_2->cur_pos->num + die_point > 6)a = 12 - (a_0_2->cur_pos->num + die_point);
									else a = a_0_2->cur_pos->num + die_point;
									for (int i = 1; i < a; i++) {
										t = t->next;
									}a_0_2->cur_pos = t;
								}

							}
							else {
								for (int i = 1; i <= die_point; i++) {
									bool flag = 0;
									if (a_0_2->cur_pos->num == 50) {
										flag = 1;
										a_0_2->cur_pos = runway_0_1;
										if (die_point == 6) {
											a_0_2->cur_pos = NULL; a_0_2->state = 2;
										}
										else {
											for (int j = 1; j <= die_point - i; j++) {
												a_0_2->cur_pos = a_0_2->cur_pos->next;
											}
										}
									}
									if (flag)break;
									a_0_2->cur_pos = a_0_2->cur_pos->next;
								}
								oneout[player] = 1;
								a_0_2->state = 1;
								if (check_allout(0))allout[player] = 1;
								check_eat(0, a_0_2->cur_pos);
								moved = 1;
								break;
							}
						}
						else if (msg.x >= 897 && msg.x <= 960 && msg.y >= 464 && msg.y <= 526 && a_0_3->state == 1) {
							check_anyone(a_0_3->cur_pos, a_0_3, 0); moved = 1;
							if (onrunway(a_0_3, 0)) {
								if (die_point == 6 - a_0_3->cur_pos->num) {
									a_0_3->cur_pos = NULL;
									a_0_3->state = 2;
								}
								else {
									square* t = runway_0_1;
									int a; if (a_0_3->cur_pos->num + die_point > 6)a = 12 - (a_0_3->cur_pos->num + die_point);
									else a = a_0_3->cur_pos->num + die_point;
									for (int i = 1; i < a; i++) {
										t = t->next;
									}a_0_3->cur_pos = t;
								}

							}
							else {
								for (int i = 1; i <= die_point; i++) {
									bool flag = 0;
									if (a_0_3->cur_pos->num == 50) {
										flag = 1;
										a_0_3->cur_pos = runway_0_1;
										if (die_point == 6) {
											a_0_3->cur_pos = NULL; a_0_3->state = 2;
										}
										else {
											for (int j = 1; j <= die_point - i; j++) {
												a_0_3->cur_pos = a_0_3->cur_pos->next;
											}
										}
									}
									if (flag)break;
									a_0_3->cur_pos = a_0_3->cur_pos->next;
								}
								oneout[player] = 1;
								a_0_3->state = 1;
								if (check_allout(0))allout[player] = 1;
								check_eat(0, a_0_3->cur_pos);
								moved = 1;
								break;
							}
						}
						else if (msg.x >= 971 && msg.x <= 1033 && msg.y >= 468 && msg.y <= 529 && a_0_4->state == 1) {
							check_anyone(a_0_4->cur_pos, a_0_4, 0); moved = 1;
							if (onrunway(a_0_4, 0)) {
								if (die_point == 6 - a_0_4->cur_pos->num) {
									a_0_4->cur_pos = NULL;
									a_0_4->state = 2;
								}
								else {
									square* t = runway_0_1;
									int a; if (a_0_4->cur_pos->num + die_point > 6)a = 12 - (a_0_4->cur_pos->num + die_point);
									else a = a_0_4->cur_pos->num + die_point;
									for (int i = 1; i < a; i++) {
										t = t->next;
									}a_0_4->cur_pos = t;
								}

							}
							else {
								for (int i = 1; i <= die_point; i++) {
									bool flag = 0;
									if (a_0_4->cur_pos->num == 50) {
										flag = 1;
										a_0_4->cur_pos = runway_0_1;
										if (die_point == 6) {
											a_0_4->cur_pos = NULL; a_0_4->state = 2;
										}
										else {
											for (int j = 1; j <= die_point - i; j++) {
												a_0_4->cur_pos = a_0_4->cur_pos->next;
											}
										}
									}
									if (flag)break;
									a_0_4->cur_pos = a_0_4->cur_pos->next;
								}
								oneout[player] = 1;
								a_0_2->state = 1;
								if (check_allout(0))allout[player] = 1;
								check_eat(0, a_0_2->cur_pos);
								moved = 1;
								break;
							}
						}
					}
					default:break;
					}
					if (moved)return;
					}
				}
			}
		else if(allout[player]){
		while (1) {
			ExMessage msg;
			if (peekmessage(&msg, EX_MOUSE)) {
				switch (msg.message) {
				case WM_LBUTTONDOWN:
				{
					if (msg.x >= 897 && msg.x <= 959 && msg.y >= 394 && msg.y <= 457 && a_0_1->state == 1) {
						check_anyone(a_0_1->cur_pos, a_0_1, 0); moved = 1;
						if (onrunway(a_0_1, 0)) {
							if (die_point == 6 - a_0_1->cur_pos->num) {
								a_0_1->cur_pos = NULL;
								a_0_1->state = 2;
							}
							else {
								square* t = runway_0_1;
								int a; if (a_0_1->cur_pos->num + die_point > 6)a = 12 - (a_0_1->cur_pos->num + die_point);
								else a = a_0_1->cur_pos->num + die_point;
								for (int i = 1; i < a; i++) {
									t = t->next;
								}a_0_1->cur_pos = t;
							}

						}
						else {
							for (int i = 1; i <= die_point; i++) {
								bool flag = 0;
								if (a_0_1->cur_pos->num == 50) {
									flag = 1;
									a_0_1->cur_pos = runway_0_1;
									if (die_point == 6) {
										a_0_1->cur_pos = NULL; a_0_1->state = 2;
									}
									else {
										for (int j = 1; j <= die_point - i; j++) {
											a_0_1->cur_pos = a_0_1->cur_pos->next;
										}
									}
								}
								if (flag)break;
								a_0_1->cur_pos = a_0_1->cur_pos->next;
							}
							oneout[player] = 1;
							a_0_1->state = 1;
							if (check_allout(0))allout[player] = 1;
							check_eat(0, a_0_1->cur_pos);
							moved = 1;
							break;
						}
					}
					else if (msg.x >= 971 && msg.x <= 1031 && msg.y >= 397 && msg.y <= 456 && a_0_2->state == 1) {
						check_anyone(a_0_2->cur_pos, a_0_2, 0); moved = 1;
						if (onrunway(a_0_2, 0)) {
							if (die_point == 6 - a_0_2->cur_pos->num) {
								a_0_2->cur_pos = NULL;
								a_0_2->state = 2;
							}
							else {
								square* t = runway_0_1;
								int a; if (a_0_2->cur_pos->num + die_point > 6)a = 12 - (a_0_2->cur_pos->num + die_point);
								else a = a_0_2->cur_pos->num + die_point;
								for (int i = 1; i < a; i++) {
									t = t->next;
								}a_0_2->cur_pos = t;
							}

						}
						else {
							for (int i = 1; i <= die_point; i++) {
								bool flag = 0;
								if (a_0_2->cur_pos->num == 50) {
									flag = 1;
									a_0_2->cur_pos = runway_0_1;
									if (die_point == 6) {
										a_0_2->cur_pos = NULL; a_0_2->state = 2;
									}
									else {
										for (int j = 1; j <= die_point - i; j++) {
											a_0_2->cur_pos = a_0_2->cur_pos->next;
										}
									}
								}
								if (flag)break;
								a_0_2->cur_pos = a_0_2->cur_pos->next;
							}
							oneout[player] = 1;
							a_0_2->state = 1;
							if (check_allout(0))allout[player] = 1;
							check_eat(0, a_0_2->cur_pos);
							moved = 1;
							break;
						}
					}
					else if (msg.x >= 897 && msg.x <= 960 && msg.y >= 464 && msg.y <= 526 && a_0_3->state == 1) {
						check_anyone(a_0_3->cur_pos, a_0_3, 0); moved = 1;
						if (onrunway(a_0_3, 0)) {
							if (die_point == 6 - a_0_3->cur_pos->num) {
								a_0_3->cur_pos = NULL;
								a_0_3->state = 2;
							}
							else {
								square* t = runway_0_1;
								int a; if (a_0_3->cur_pos->num + die_point > 6)a = 12 - (a_0_3->cur_pos->num + die_point);
								else a = a_0_3->cur_pos->num + die_point;
								for (int i = 1; i < a; i++) {
									t = t->next;
								}a_0_3->cur_pos = t;
							}

						}
						else {
							for (int i = 1; i <= die_point; i++) {
								bool flag = 0;
								if (a_0_3->cur_pos->num == 50) {
									flag = 1;
									a_0_3->cur_pos = runway_0_1;
									if (die_point == 6) {
										a_0_3->cur_pos = NULL; a_0_3->state = 2;
									}
									else {
										for (int j = 1; j <= die_point - i; j++) {
											a_0_3->cur_pos = a_0_3->cur_pos->next;
										}
									}
								}
								if (flag)break;
								a_0_3->cur_pos = a_0_3->cur_pos->next;
							}
							oneout[player] = 1;
							a_0_3->state = 1;
							if (check_allout(0))allout[player] = 1;
							check_eat(0, a_0_3->cur_pos);
							moved = 1;
							break;
						}
					}
					else if (msg.x >= 971 && msg.x <= 1033 && msg.y >= 468 && msg.y <= 529 && a_0_4->state == 1) {
						check_anyone(a_0_4->cur_pos, a_0_4, 0); moved = 1;
						if (onrunway(a_0_4, 0)) {
							if (die_point == 6 - a_0_4->cur_pos->num) {
								a_0_4->cur_pos = NULL;
								a_0_4->state = 2;
							}
							else {
								square* t = runway_0_1;
								int a; if (a_0_4->cur_pos->num + die_point > 6)a = 12 - (a_0_4->cur_pos->num + die_point);
								else a = a_0_4->cur_pos->num + die_point;
								for (int i = 1; i < a; i++) {
									t = t->next;
								}a_0_4->cur_pos = t;
							}

						}
						else {
							for (int i = 1; i <= die_point; i++) {
								bool flag = 0;
								if (a_0_4->cur_pos->num == 50) {
									flag = 1;
									a_0_4->cur_pos = runway_0_1;
									if (die_point == 6) {
										a_0_4->cur_pos = NULL; a_0_4->state = 2;
									}
									else {
										for (int j = 1; j <= die_point - i; j++) {
											a_0_4->cur_pos = a_0_4->cur_pos->next;
										}
									}
								}
								if (flag)break;
								a_0_4->cur_pos = a_0_4->cur_pos->next;
							}
							oneout[player] = 1;
							a_0_2->state = 1;
							if (check_allout(0))allout[player] = 1;
							check_eat(0, a_0_2->cur_pos);
							moved = 1;
							break;
						}
					}
				}
				default:break;
				}
			}
			if (moved)return;
		}
		}
	}
	if (player == 1) {
		bool moved = 0;
		if (die_point != 6 && check_canmove(1)) {
			return;
		}
		else if (die_point == 6 && !allout[player]) {
			while (1) {
				ExMessage msg;
				if (peekmessage(&msg, EX_MOUSE)) {
					switch (msg.message) {
					case WM_LBUTTONDOWN:
					{
						if (msg.x >= 897 && msg.x <= 959 && msg.y >= 394 && msg.y <= 457 && a_1_1->state == 0) {//没更新图像
							check_anyone(a_1_1->cur_pos, a_1_1, 1);
							a_1_1->cur_pos = start_1;
							int random = getDieRes();
							for (int i = 1; i <= random; i++) {
								a_1_1->cur_pos = a_1_1->cur_pos->next;
							}oneout[player] = 1;
							a_1_1->state = 1;
							if (check_allout(1))allout[player] = 1;
							check_eat(1, a_1_1->cur_pos);
							moved = 1;
							break;
						}
						else if (msg.x >= 971 && msg.x <= 1031 && msg.y >= 397 && msg.y <= 456 && a_1_2->state == 0) {
							check_anyone(a_1_2->cur_pos, a_1_2, 1);
							a_1_2->cur_pos = start_1;
							int random = getDieRes();
							for (int i = 1; i <= random; i++) {
								a_1_2->cur_pos = a_1_2->cur_pos->next;
							}oneout[player] = 1;
							a_1_2->state = 1;
							if (check_allout(1))allout[player] = 1;
							check_eat(1, a_1_2->cur_pos);
							moved = 1;
							break;
						}
						else if (msg.x >= 897 && msg.x <= 960 && msg.y >= 464 && msg.y <= 526 && a_1_3->state == 0) {
							check_anyone(a_1_3->cur_pos, a_1_3, 1);
							a_1_3->cur_pos = start_1;
							int random = getDieRes();
							for (int i = 1; i <= random; i++) {
								a_1_3->cur_pos = a_1_3->cur_pos->next;
							}oneout[player] = 1;
							a_1_3->state = 1;
							if (check_allout(1))allout[player] = 1;
							check_eat(1, a_1_3->cur_pos);
							moved = 1;
							break;
						}
						else if (msg.x >= 971 && msg.x <= 1033 && msg.y >= 468 && msg.y <= 529 && a_1_4->state == 0) {
							check_anyone(a_1_4->cur_pos, a_1_4, 1);
							a_1_4->cur_pos = start_1;
							int random = getDieRes();
							for (int i = 1; i <= random; i++) {
								a_1_4->cur_pos = a_1_4->cur_pos->next;
							}oneout[player] = 1;
							a_1_4->state = 1;
							if (check_allout(1))allout[player] = 1;
							check_eat(1, a_1_4->cur_pos);
							moved = 1;
							break;
						}
					default:break;
					}
					}
					if (moved)return;

				}
			}
		}
		else if (die_point != 6 && !allout[player] && oneout[player]) {
					while (1) {
						ExMessage msg;
						if (peekmessage(&msg, EX_MOUSE)) {
							switch (msg.message) {
							case WM_LBUTTONDOWN:
							{
								if (msg.x >= 897 && msg.x <= 959 && msg.y >= 394 && msg.y <= 457 && a_1_1->state == 1) {//没更新图像
									check_anyone(a_1_1->cur_pos, a_1_1, 1); moved = 1;
									if (onrunway(a_1_1, 1)) {
										if (die_point == 6 - a_1_1->cur_pos->num) {
											a_1_1->cur_pos = NULL;
											a_1_1->state = 2;
										}
										else {
											square* t = runway_1_1;
											int a; if (a_1_1->cur_pos->num + die_point > 6)a = 12 - (a_1_1->cur_pos->num + die_point);
											else a = a_1_1->cur_pos->num + die_point;
											for (int i = 1; i < a; i++) {
												t = t->next;
											}a_1_1->cur_pos = t;
										}

									}
									else {
										for (int i = 1; i <= die_point; i++) {
											bool flag = 0;
											if (a_1_1->cur_pos->num == 11) {
												flag = 1;
												a_1_1->cur_pos = runway_1_1;
												if (die_point == 6) {
													a_1_1->cur_pos = NULL; a_1_1->state = 2;
												}
												else {
													for (int j = 1; j <= die_point - i; j++) {
														a_1_1->cur_pos = a_1_1->cur_pos->next;
													}
												}
											}
											if (flag)break;
											a_1_1->cur_pos = a_1_1->cur_pos->next;
										}
										oneout[player] = 1;
										a_1_1->state = 1;
										if (check_allout(1))allout[player] = 1;
										check_eat(1, a_1_1->cur_pos);
										moved = 1;
										break;
									}
								}
								else if (msg.x >= 971 && msg.x <= 1031 && msg.y >= 397 && msg.y <= 456 && a_1_2->state == 1) {
									check_anyone(a_1_2->cur_pos, a_1_2, 1); moved = 1;

									if (onrunway(a_1_2, 1)) {
										if (die_point == 6 - a_1_2->cur_pos->num) {
											a_1_2->cur_pos = NULL;
											a_1_2->state = 2;
										}
										else {
											square* t = runway_1_1;
											int a; if (a_1_2->cur_pos->num + die_point > 6)a = 12 - (a_1_2->cur_pos->num + die_point);
											else a = a_1_2->cur_pos->num + die_point;
											for (int i = 1; i < a; i++) {
												t = t->next;
											}a_1_2->cur_pos = t;
										}

									}
									else {
										for (int i = 1; i <= die_point; i++) {
											bool flag = 0;
											if (a_1_2->cur_pos->num == 11) {
												flag = 1;
												a_1_2->cur_pos = runway_1_1;
												if (die_point == 6) {
													a_1_2->cur_pos = NULL; a_1_2->state = 2;
												}
												else {
													for (int j = 1; j <= die_point - i; j++) {
														a_1_2->cur_pos = a_1_2->cur_pos->next;
													}
												}
											}
											if (flag)break;
											a_1_2->cur_pos = a_1_2->cur_pos->next;
										}
										oneout[player] = 1;
										a_1_2->state = 1;
										if (check_allout(1))allout[player] = 1;
										check_eat(1, a_1_2->cur_pos);
										moved = 1;
										break;
									}
								}
								else if (msg.x >= 897 && msg.x <= 960 && msg.y >= 464 && msg.y <= 526 && a_1_3->state == 1) {
									check_anyone(a_1_3->cur_pos, a_1_3, 1); moved = 1;
									if (onrunway(a_1_3, 1)) {
										if (die_point == 6 - a_1_3->cur_pos->num) {
											a_1_3->cur_pos = NULL;
											a_1_3->state = 2;
										}
										else {
											square* t = runway_1_1;
											int a; if (a_1_3->cur_pos->num + die_point > 6)a = 12 - (a_1_3->cur_pos->num + die_point);
											else a = a_1_3->cur_pos->num + die_point;
											for (int i = 1; i < a; i++) {
												t = t->next;
											}a_1_3->cur_pos = t;
										}

									}
									else {
										for (int i = 1; i <= die_point; i++) {
											bool flag = 0;
											if (a_1_3->cur_pos->num == 11) {
												flag = 1;
												a_1_3->cur_pos = runway_1_1;
												if (die_point == 6) {
													a_1_3->cur_pos = NULL; a_1_3->state = 2;
												}
												else {
													for (int j = 1; j <= die_point - i; j++) {
														a_1_3->cur_pos = a_1_3->cur_pos->next;
													}
												}
											}
											if (flag)break;
											a_1_3->cur_pos = a_1_3->cur_pos->next;
										}
										oneout[player] = 1;
										a_1_3->state = 1;
										if (check_allout(1))allout[player] = 1;
										check_eat(1, a_1_3->cur_pos);
										moved = 1;
										break;
									}
								}
								else if (msg.x >= 971 && msg.x <= 1033 && msg.y >= 468 && msg.y <= 529 && a_1_4->state == 1) {
									check_anyone(a_1_4->cur_pos, a_1_4, 1); moved = 1;
									if (onrunway(a_1_4, 1)) {
										if (die_point == 6 - a_1_4->cur_pos->num) {
											a_1_4->cur_pos = NULL;
											a_1_4->state = 2;
										}
										else {
											square* t = runway_1_1;
											int a; if (a_1_4->cur_pos->num + die_point > 6)a = 12 - (a_1_4->cur_pos->num + die_point);
											else a = a_1_4->cur_pos->num + die_point;
											for (int i = 1; i < a; i++) {
												t = t->next;
											}a_1_4->cur_pos = t;
										}

									}
									else {
										for (int i = 1; i <= die_point; i++) {
											bool flag = 0;
											if (a_1_4->cur_pos->num == 11) {
												flag = 1;
												a_1_4->cur_pos = runway_1_1;
												if (die_point == 6) {
													a_1_4->cur_pos = NULL; a_1_4->state = 2;
												}
												else {
													for (int j = 1; j <= die_point - i; j++) {
														a_1_4->cur_pos = a_1_4->cur_pos->next;
													}
												}
											}
											if (flag)break;
											a_1_4->cur_pos = a_1_4->cur_pos->next;
										}
										oneout[player] = 1;
										a_1_4->state = 1;
										if (check_allout(1))allout[player] = 1;
										check_eat(1, a_1_4->cur_pos);
										moved = 1;
										break;
									}
								}
							}
							default:break;
							}
						}
						if (moved)return;
					}
				}
		else if (allout[player]) {
					while (1) {
						ExMessage msg;
						if (peekmessage(&msg, EX_MOUSE)) {
							switch (msg.message) {
							case WM_LBUTTONDOWN:
							{
								if (msg.x >= 897 && msg.x <= 959 && msg.y >= 394 && msg.y <= 457 && a_1_1->state == 1) {//没更新图像
									check_anyone(a_1_1->cur_pos, a_1_1, 1);
									if (onrunway(a_1_1, 1)) {
										if (die_point == 6 - a_1_1->cur_pos->num) {
											a_1_1->cur_pos = NULL;
											a_1_1->state = 2;
										}
										else {
											square* t = runway_1_1;
											int a; if (a_1_1->cur_pos->num + die_point > 6)a = 12 - (a_1_1->cur_pos->num + die_point);
											else a = a_1_1->cur_pos->num + die_point;
											for (int i = 1; i < a; i++) {
												t = t->next;
											}a_1_1->cur_pos = t;
										}

									}
									else {
										for (int i = 1; i <= die_point; i++) {
											bool flag = 0;
											if (a_1_1->cur_pos->num == 11) {
												flag = 1;
												a_1_1->cur_pos = runway_1_1;
												if (die_point == 6) {
													a_1_1->cur_pos = NULL; a_1_1->state = 2;
												}
												else {
													for (int j = 1; j <= die_point - i; j++) {
														a_1_1->cur_pos = a_1_1->cur_pos->next;
													}
												}
											}
											if (flag)break;
											a_1_1->cur_pos = a_1_1->cur_pos->next;
										}
										oneout[player] = 1;
										a_1_1->state = 1;
										if (check_allout(1))allout[player] = 1;
										check_eat(1, a_1_1->cur_pos);
										moved = 1;
										break;
									}
								}
								else if (msg.x >= 971 && msg.x <= 1031 && msg.y >= 397 && msg.y <= 456 && a_1_2->state == 1) {
									check_anyone(a_1_2->cur_pos, a_1_2, 1);

									if (onrunway(a_1_2, 1)) {
										if (die_point == 6 - a_1_2->cur_pos->num) {
											a_1_2->cur_pos = NULL;
											a_1_2->state = 2;
										}
										else {
											square* t = runway_1_1;
											int a; if (a_1_2->cur_pos->num + die_point > 6)a = 12 - (a_1_2->cur_pos->num + die_point);
											else a = a_1_2->cur_pos->num + die_point;
											for (int i = 1; i < a; i++) {
												t = t->next;
											}a_1_2->cur_pos = t;
										}

									}
									else {
										for (int i = 1; i <= die_point; i++) {
											bool flag = 0;
											if (a_1_2->cur_pos->num == 11) {
												flag = 1;
												a_1_2->cur_pos = runway_1_1;
												if (die_point == 6) {
													a_1_2->cur_pos = NULL; a_1_2->state = 2;
												}
												else {
													for (int j = 1; j <= die_point - i; j++) {
														a_1_2->cur_pos = a_1_2->cur_pos->next;
													}
												}
											}
											if (flag)break;
											a_1_2->cur_pos = a_1_2->cur_pos->next;
										}
										oneout[player] = 1;
										a_1_2->state = 1;
										if (check_allout(1))allout[player] = 1;
										check_eat(1, a_1_2->cur_pos);
										moved = 1;
										break;
									}
								}
								else if (msg.x >= 897 && msg.x <= 960 && msg.y >= 464 && msg.y <= 526 && a_1_3->state == 1) {
									check_anyone(a_1_3->cur_pos, a_1_3, 1);
									if (onrunway(a_1_3, 1)) {
										if (die_point == 6 - a_1_3->cur_pos->num) {
											a_1_3->cur_pos = NULL;
											a_1_3->state = 2;
										}
										else {
											square* t = runway_1_1;
											int a; if (a_1_3->cur_pos->num + die_point > 6)a = 12 - (a_1_3->cur_pos->num + die_point);
											else a = a_1_3->cur_pos->num + die_point;
											for (int i = 1; i < a; i++) {
												t = t->next;
											}a_1_3->cur_pos = t;
										}

									}
									else {
										for (int i = 1; i <= die_point; i++) {
											bool flag = 0;
											if (a_1_3->cur_pos->num == 11) {
												flag = 1;
												a_1_3->cur_pos = runway_1_1;
												if (die_point == 6) {
													a_1_3->cur_pos = NULL; a_1_3->state = 2;
												}
												else {
													for (int j = 1; j <= die_point - i; j++) {
														a_1_3->cur_pos = a_1_3->cur_pos->next;
													}
												}
											}
											if (flag)break;
											a_1_3->cur_pos = a_1_3->cur_pos->next;
										}
										oneout[player] = 1;
										a_1_3->state = 1;
										if (check_allout(1))allout[player] = 1;
										check_eat(1, a_1_3->cur_pos);
										moved = 1;
										break;
									}
								}
								else if (msg.x >= 971 && msg.x <= 1033 && msg.y >= 468 && msg.y <= 529 && a_1_4->state == 1) {
									check_anyone(a_1_4->cur_pos, a_1_4, 1);
									if (onrunway(a_1_4, 1)) {
										if (die_point == 6 - a_1_4->cur_pos->num) {
											a_1_4->cur_pos = NULL;
											a_1_4->state = 2;
										}
										else {
											square* t = runway_1_1;
											int a; if (a_1_4->cur_pos->num + die_point > 6)a = 12 - (a_1_4->cur_pos->num + die_point);
											else a = a_1_4->cur_pos->num + die_point;
											for (int i = 1; i < a; i++) {
												t = t->next;
											}a_1_4->cur_pos = t;
										}

									}
									else {
										for (int i = 1; i <= die_point; i++) {
											bool flag = 0;
											if (a_1_4->cur_pos->num == 11) {
												flag = 1;
												a_1_4->cur_pos = runway_1_1;
												if (die_point == 6) {
													a_1_4->cur_pos = NULL; a_1_4->state = 2;
												}
												else {
													for (int j = 1; j <= die_point - i; j++) {
														a_1_4->cur_pos = a_1_4->cur_pos->next;
													}
												}
											}
											if (flag)break;
											a_1_4->cur_pos = a_1_4->cur_pos->next;
										}
										oneout[player] = 1;
										a_1_4->state = 1;
										if (check_allout(1))allout[player] = 1;
										check_eat(1, a_1_4->cur_pos);
										moved = 1;
										break;
									}
								}
							}
							default:break;
							}
						}
						if (moved)return;
					}
				}
	}
	if (player == 2) {
		bool moved = 0;
		if (die_point != 6 &&check_canmove(2)) {
			 return;
		}
		else if (die_point == 6 && !allout[player]) {
			while (1) {
				ExMessage msg;
				if (peekmessage(&msg, EX_MOUSE)) {
					switch (msg.message) {
					case WM_LBUTTONDOWN:
					{
						if (msg.x >= 897 && msg.x <= 959 && msg.y >= 394 && msg.y <= 457 && a_2_1->state == 0) {//没更新图像
							check_anyone(a_2_1->cur_pos, a_2_1, 2);
							a_2_1->cur_pos = start_2;
							int random = getDieRes();
							for (int i = 1; i <= random; i++) {
								a_2_1->cur_pos = a_2_1->cur_pos->next;
							}oneout[player] = 1;
							a_2_1->state = 1;
							if (check_allout(2))allout[player] = 1;
							check_eat(2, a_2_1->cur_pos);
							moved = 1;
							break;
						}
						else if (msg.x >= 971 && msg.x <= 1031 && msg.y >= 397 && msg.y <= 456 && a_2_2->state == 0) {
							check_anyone(a_2_2->cur_pos, a_2_2, 2);
							a_2_2->cur_pos = start_2;
							int random = getDieRes();
							for (int i = 1; i <= random; i++) {
								a_2_2->cur_pos = a_2_2->cur_pos->next;//bug,上面没改
							}oneout[player] = 1;
							a_2_2->state = 1;
							if (check_allout(2))allout[player] = 1;
							check_eat(2, a_2_2->cur_pos);
							moved = 1;
							break;
						}
						else if (msg.x >= 897 && msg.x <= 960 && msg.y >= 464 && msg.y <= 526 && a_2_3->state == 0) {
							check_anyone(a_2_3->cur_pos, a_2_3, 2);
							a_2_3->cur_pos = start_2;
							int random = getDieRes();
							for (int i = 1; i <= random; i++) {
								a_2_3->cur_pos = a_2_3->cur_pos->next;
							}oneout[player] = 1;
							a_2_3->state = 1;
							if (check_allout(2))allout[player] = 1;
							check_eat(2, a_2_3->cur_pos);
							moved = 1;
							break;
						}
						else if (msg.x >= 971 && msg.x <= 1033 && msg.y >= 468 && msg.y <= 529 && a_2_4->state == 0) {
							check_anyone(a_2_4->cur_pos, a_2_4, 2);
							a_2_4->cur_pos = start_2;
							int random = getDieRes();
							for (int i = 1; i <= random; i++) {
								a_2_4->cur_pos = a_2_4->cur_pos->next;
							}oneout[player] = 1;
							a_2_4->state = 1;
							if (check_allout(2))allout[player] = 1;
							check_eat(2, a_2_4->cur_pos);
							moved = 1;
							break;
						}
					}
					default:break;
					}
				}
				if (moved)return;
			}
		}
		else if (die_point != 6 && !allout[player] && oneout[player]) {
			while (1) {
				ExMessage msg;
				if (peekmessage(&msg, EX_MOUSE)) {
					switch (msg.message) {
					case WM_LBUTTONDOWN:
					{
						if (msg.x >= 897 && msg.x <= 959 && msg.y >= 394 && msg.y <= 457 && a_2_1->state == 1) {
							check_anyone(a_2_1->cur_pos, a_2_1, 2); moved = 1;
							if (onrunway(a_2_1, 2)) {
								if (die_point == 6 - a_2_1->cur_pos->num) {
									a_2_1->cur_pos = NULL;
									a_2_1->state = 2;
								}
								else {
									square* t = runway_2_1;
									int a; if (a_2_1->cur_pos->num + die_point > 6)a = 12 - (a_2_1->cur_pos->num + die_point);
									else a = a_2_1->cur_pos->num + die_point;
									for (int i = 1; i < a; i++) {
										t = t->next;
									}a_2_1->cur_pos = t;
								}

							}
							else {
								for (int i = 1; i <= die_point; i++) {
									bool flag = 0;
									if (a_2_1->cur_pos->num == 24) {
										flag = 1;
										a_2_1->cur_pos = runway_2_1;
										if (die_point == 6) {
											a_2_1->cur_pos = NULL; a_2_1->state = 2;
										}
										else {
											for (int j = 1; j <= die_point - i; j++) {
												a_2_1->cur_pos = a_2_1->cur_pos->next;
											}
										}
									}
									if (flag)break;
									a_2_1->cur_pos = a_2_1->cur_pos->next;
								}
								oneout[player] = 1;
								a_2_1->state = 1;
								if (check_allout(2))allout[player] = 1;
								check_eat(2, a_2_1->cur_pos);
								moved = 1;
								break;
							}
						}
						else if (msg.x >= 971 && msg.x <= 1031 && msg.y >= 397 && msg.y <= 456 && a_2_2->state == 1) {
							check_anyone(a_2_2->cur_pos, a_2_2, 2); moved = 1;
							if (onrunway(a_2_2, 2)) {
								if (die_point == 6 - a_2_2->cur_pos->num) {
									a_2_2->cur_pos = NULL;
									a_2_2->state = 2;
								}
								else {
									square* t = runway_2_1;
									int a; if (a_2_2->cur_pos->num + die_point > 6)a = 12 - (a_2_2->cur_pos->num + die_point);
									else a = a_2_2->cur_pos->num + die_point;
									for (int i = 1; i < a; i++) {
										t = t->next;
									}a_2_2->cur_pos = t;
								}

							}
							else {
								for (int i = 1; i <= die_point; i++) {
									bool flag = 0;
									if (a_2_2->cur_pos->num == 24) {
										flag = 1;
										a_2_2->cur_pos = runway_2_1;
										if (die_point == 6) {
											a_2_2->cur_pos = NULL; a_2_2->state = 2;
										}
										else {
											for (int j = 1; j <= die_point - i; j++) {
												a_2_2->cur_pos = a_2_2->cur_pos->next;
											}
										}
									}
									if (flag)break;
									a_2_2->cur_pos = a_2_2->cur_pos->next;
								}
								oneout[player] = 1;
								a_2_2->state = 1;
								if (check_allout(2))allout[player] = 1;
								check_eat(2, a_2_2->cur_pos);
								moved = 1;
								break;
							}
						}
						else if (msg.x >= 897 && msg.x <= 960 && msg.y >= 464 && msg.y <= 526 && a_2_3->state == 1) {
							check_anyone(a_2_3->cur_pos, a_2_3, 2); moved = 1;
							if (onrunway(a_2_3, 2)) {
								if (die_point == 6 - a_2_3->cur_pos->num) {
									a_2_3->cur_pos = NULL;
									a_2_3->state = 2;
								}
								else {
									square* t = runway_2_1;
									int a; if (a_2_3->cur_pos->num + die_point > 6)a = 12 - (a_2_3->cur_pos->num + die_point);
									else a = a_2_3->cur_pos->num + die_point;
									for (int i = 1; i < a; i++) {
										t = t->next;
									}a_2_3->cur_pos = t;
								}

							}
							else {
								for (int i = 1; i <= die_point; i++) {
									bool flag = 0;
									if (a_2_3->cur_pos->num == 24) {
										flag = 1;
										a_2_3->cur_pos = runway_2_1;
										if (die_point == 6) {
											a_2_3->cur_pos = NULL; a_2_3->state = 2;
										}
										else {
											for (int j = 1; j <= die_point - i; j++) {
												a_2_3->cur_pos = a_2_3->cur_pos->next;
											}
										}
									}
									if (flag)break;
									a_2_3->cur_pos = a_2_3->cur_pos->next;
								}
								oneout[player] = 1;
								a_2_3->state = 1;
								if (check_allout(2))allout[player] = 1;
								check_eat(2, a_2_3->cur_pos);
								moved = 1;
								break;
							}
						}
						else if (msg.x >= 971 && msg.x <= 1033 && msg.y >= 468 && msg.y <= 529 && a_2_4->state == 1) {
							check_anyone(a_2_4->cur_pos, a_2_4, 2); moved = 1;
							if (onrunway(a_2_4, 2)) {
								if (die_point == 6 - a_2_4->cur_pos->num) {
									a_2_4->cur_pos = NULL;
									a_2_4->state = 2;
								}
								else {
									square* t = runway_2_1;
									int a; if (a_2_4->cur_pos->num + die_point > 6)a = 12 - (a_2_4->cur_pos->num + die_point);
									else a = a_2_4->cur_pos->num + die_point;
									for (int i = 1; i < a; i++) {
										t = t->next;
									}a_2_4->cur_pos = t;
								}

							}
							else {
								for (int i = 1; i <= die_point; i++) {
									bool flag = 0;
									if (a_2_4->cur_pos->num == 24) {
										flag = 1;
										a_2_4->cur_pos = runway_2_1;
										if (die_point == 6) {
											a_2_4->cur_pos = NULL; a_2_4->state = 2;
										}
										else {
											for (int j = 1; j <= die_point - i; j++) {
												a_2_4->cur_pos = a_2_4->cur_pos->next;
											}
										}
									}
									if (flag)break;
									a_2_4->cur_pos = a_2_4->cur_pos->next;
								}
								oneout[player] = 1;
								a_2_4->state = 1;
								if (check_allout(2))allout[player] = 1;
								check_eat(2, a_2_4->cur_pos);
								moved = 1;
								break;
							}
						}
					}
					default:break;
					}
				}
				if (moved)return;
			}
		}
		else if (allout[player]) {
			while (1) {
				ExMessage msg;
				if (peekmessage(&msg, EX_MOUSE)) {
					switch (msg.message) {
					case WM_LBUTTONDOWN:
					{
						if (msg.x >= 897 && msg.x <= 959 && msg.y >= 394 && msg.y <= 457 && a_2_1->state == 1) {
							check_anyone(a_2_1->cur_pos, a_2_1, 2); moved = 1;
							if (onrunway(a_2_1, 2)) {
								if (die_point == 6 - a_2_1->cur_pos->num) {
									a_2_1->cur_pos = NULL;
									a_2_1->state = 2;
								}
								else {
									square* t = runway_2_1;
									int a; if (a_2_1->cur_pos->num + die_point > 6)a = 12 - (a_2_1->cur_pos->num + die_point);
									else a = a_2_1->cur_pos->num + die_point;
									for (int i = 1; i < a; i++) {
										t = t->next;
									}a_2_1->cur_pos = t;
								}

							}
							else {
								for (int i = 1; i <= die_point; i++) {
									bool flag = 0;
									if (a_2_1->cur_pos->num == 24) {
										flag = 1;
										a_2_1->cur_pos = runway_2_1;
										if (die_point == 6) {
											a_2_1->cur_pos = NULL; a_2_1->state = 2;
										}
										else {
											for (int j = 1; j <= die_point - i; j++) {
												a_2_1->cur_pos = a_2_1->cur_pos->next;
											}
										}
									}
									if (flag)break;
									a_2_1->cur_pos = a_2_1->cur_pos->next;
								}
								oneout[player] = 1;
								a_2_1->state = 1;
								if (check_allout(2))allout[player] = 1;
								check_eat(2, a_2_1->cur_pos);
								moved = 1;
								break;
							}
						}
						else if (msg.x >= 971 && msg.x <= 1031 && msg.y >= 397 && msg.y <= 456 && a_2_2->state == 1) {
							check_anyone(a_2_2->cur_pos, a_2_2, 2); moved = 1;
							if (onrunway(a_2_2, 2)) {
								if (die_point == 6 - a_2_2->cur_pos->num) {
									a_2_2->cur_pos = NULL;
									a_2_2->state = 2;
								}
								else {
									square* t = runway_2_1;
									int a; if (a_2_2->cur_pos->num + die_point > 6)a = 12 - (a_2_2->cur_pos->num + die_point);
									else a = a_2_2->cur_pos->num + die_point;
									for (int i = 1; i < a; i++) {
										t = t->next;
									}a_2_2->cur_pos = t;
								}

							}
							else {
								for (int i = 1; i <= die_point; i++) {
									bool flag = 0;
									if (a_2_2->cur_pos->num == 24) {
										flag = 1;
										a_2_2->cur_pos = runway_2_1;
										if (die_point == 6) {
											a_2_2->cur_pos = NULL; a_2_2->state = 2;
										}
										else {
											for (int j = 1; j <= die_point - i; j++) {
												a_2_2->cur_pos = a_2_2->cur_pos->next;
											}
										}
									}
									if (flag)break;
									a_2_2->cur_pos = a_2_2->cur_pos->next;
								}
								oneout[player] = 1;
								a_2_2->state = 1;
								if (check_allout(2))allout[player] = 1;
								check_eat(2, a_2_2->cur_pos);
								moved = 1;
								break;
							}
						}
						else if (msg.x >= 897 && msg.x <= 960 && msg.y >= 464 && msg.y <= 526 && a_2_3->state == 1) {
							check_anyone(a_2_3->cur_pos, a_2_3, 2); moved = 1;
							if (onrunway(a_2_3, 2)) {
								if (die_point == 6 - a_2_3->cur_pos->num) {
									a_2_3->cur_pos = NULL;
									a_2_3->state = 2;
								}
								else {
									square* t = runway_2_1;
									int a; if (a_2_3->cur_pos->num + die_point > 6)a = 12 - (a_2_3->cur_pos->num + die_point);
									else a = a_2_3->cur_pos->num + die_point;
									for (int i = 1; i < a; i++) {
										t = t->next;
									}a_2_3->cur_pos = t;
								}

							}
							else {
								for (int i = 1; i <= die_point; i++) {
									bool flag = 0;
									if (a_2_3->cur_pos->num == 24) {
										flag = 1;
										a_2_3->cur_pos = runway_2_1;
										if (die_point == 6) {
											a_2_3->cur_pos = NULL; a_2_3->state = 2;
										}
										else {
											for (int j = 1; j <= die_point - i; j++) {
												a_2_3->cur_pos = a_2_3->cur_pos->next;
											}
										}
									}
									if (flag)break;
									a_2_3->cur_pos = a_2_3->cur_pos->next;
								}
								oneout[player] = 1;
								a_2_3->state = 1;
								if (check_allout(2))allout[player] = 1;
								check_eat(2, a_2_3->cur_pos);
								moved = 1;
								break;
							}
						}
						else if (msg.x >= 971 && msg.x <= 1033 && msg.y >= 468 && msg.y <= 529 && a_2_4->state == 1) {
							check_anyone(a_2_4->cur_pos, a_2_4, 2); moved = 1;
							if (onrunway(a_2_4, 2)) {
								if (die_point == 6 - a_2_4->cur_pos->num) {
									a_2_4->cur_pos = NULL;
									a_2_4->state = 2;
								}
								else {
									square* t = runway_2_1;
									int a; if (a_2_4->cur_pos->num + die_point > 6)a = 12 - (a_2_4->cur_pos->num + die_point);
									else a = a_2_4->cur_pos->num + die_point;
									for (int i = 1; i < a; i++) {
										t = t->next;
									}a_2_4->cur_pos = t;
								}

							}
							else {
								for (int i = 1; i <= die_point; i++) {
									bool flag = 0;
									if (a_2_4->cur_pos->num == 24) {
										flag = 1;
										a_2_4->cur_pos = runway_2_1;
										if (die_point == 6) {
											a_2_4->cur_pos = NULL; a_2_4->state = 2;
										}
										else {
											for (int j = 1; j <= die_point - i; j++) {
												a_2_4->cur_pos = a_2_4->cur_pos->next;
											}
										}
									}
									if (flag)break;
									a_2_4->cur_pos = a_2_4->cur_pos->next;
								}
								oneout[player] = 1;
								a_2_4->state = 1;
								if (check_allout(2))allout[player] = 1;
								check_eat(2, a_2_4->cur_pos);
								moved = 1;
								break;
							}
						}
					}
					default:break;
					}
				}
				if (moved)return;
			}
		}
	}
	if (player == 3) {
		bool moved = 0;
		if (die_point != 6 &&check_canmove(3)) {
			
			return;
		}
		else if (die_point == 6 && !allout[player]) {

				if (a_3_1->state == 0) {
							check_anyone(a_3_1->cur_pos, a_3_1, 3);
							a_3_1->cur_pos = start_3;
							int random = getDieResAI();
							for (int i = 1; i <= random; i++) {
								a_3_1->cur_pos = a_3_1->cur_pos->next;
							}oneout[player] = 1;
							a_3_1->state = 1;
							if (check_allout(3))allout[player] = 1;
							check_eat(3, a_3_1->cur_pos);
							moved = 1; return;
						}
				else if (a_3_2->state == 0) {
							check_anyone(a_3_2->cur_pos, a_3_2, 3);
							a_3_2->cur_pos = start_3;
							int random = getDieResAI();
							for (int i = 1; i <= random; i++) {
								a_3_2->cur_pos = a_3_2->cur_pos->next;
							}oneout[player] = 1;
							a_3_2->state = 1;
							if (check_allout(3))allout[player] = 1;
							check_eat(3, a_3_2->cur_pos);
							moved = 1;
							return;
						}
				else if (a_3_3->state == 0) {
							check_anyone(a_3_3->cur_pos, a_3_3, 3);
							a_3_3->cur_pos = start_3;
							int random = getDieResAI();
							for (int i = 1; i <= random; i++) {
								a_3_3->cur_pos = a_3_3->cur_pos->next;
							}oneout[player] = 1;
							a_3_3->state = 1;
							if (check_allout(3))allout[player] = 1;
							check_eat(3, a_3_3->cur_pos);
							moved = 1;
							return;
						}
				else if (a_3_4->state == 0) {
							check_anyone(a_3_4->cur_pos, a_3_4, 3);
							a_3_4->cur_pos = start_3;
							int random = getDieResAI();
							for (int i = 1; i <= random; i++) {
								a_3_4->cur_pos = a_3_4->cur_pos->next;
							}oneout[player] = 1;
							a_3_4->state = 1;
							if (check_allout(3))allout[player] = 1;
							check_eat(3, a_3_4->cur_pos);
							moved = 1;
							return;
						}
		}
		else if (die_point != 6 && !allout[player] && oneout[player]) {
			
				if ( a_3_1->state == 1) {
							check_anyone(a_3_1->cur_pos, a_3_1, 3); moved = 1;
							if (onrunway(a_3_1, 3)) {
								if (die_point == 6 - a_3_1->cur_pos->num) {
									a_3_1->cur_pos = NULL;
									a_3_1->state = 2;
								}
								else {
									square* t = runway_3_1;
									int a; if (a_3_1->cur_pos->num + die_point > 6)a = 12 - (a_3_1->cur_pos->num + die_point);
									else a = a_3_1->cur_pos->num + die_point;
									for (int i = 1; i < a; i++) {
										t = t->next;
									}a_3_1->cur_pos = t;
								}
								return;
							}
							else {
								for (int i = 1; i <= die_point; i++) {
									bool flag = 0;
									if (a_3_1->cur_pos->num == 37) {
										flag = 1;
										a_3_1->cur_pos = runway_3_1;
										if (die_point == 6) {
											a_3_1->cur_pos = NULL; a_3_1->state = 2;
										}
										else {
											for (int j = 1; j <= die_point - i; j++) {
												a_3_1->cur_pos = a_3_1->cur_pos->next;
											}
										}
									}
									if (flag)break;
									a_3_1->cur_pos = a_3_1->cur_pos->next;
								}
								oneout[player] = 1;
								a_3_1->state = 1;
								if (check_allout(3))allout[player] = 1;
								check_eat(3, a_3_1->cur_pos);
								moved = 1;
								return;
							}
						}
				else if (a_3_2->state == 1) {
							check_anyone(a_3_2->cur_pos, a_3_2, 3); moved = 1;
							if (onrunway(a_3_2, 3)) {
								if (die_point == 6 - a_3_2->cur_pos->num) {
									a_3_2->cur_pos = NULL;
									a_3_2->state = 2;
								}
								else {
									square* t = runway_3_1;
									int a; if (a_3_2->cur_pos->num + die_point > 6)a = 12 - (a_3_2->cur_pos->num + die_point);
									else a = a_3_2->cur_pos->num + die_point;
									for (int i = 1; i < a; i++) {
										t = t->next;
									}a_3_2->cur_pos = t;
								}
								return;
							}
							else {
								for (int i = 1; i <= die_point; i++) {
									bool flag = 0;
									if (a_2_2->cur_pos->num == 37) {
										flag = 1;
										a_3_2->cur_pos = runway_3_1;
										if (die_point == 6) {
											a_3_2->cur_pos = NULL; a_3_2->state = 2;
										}
										else {
											for (int j = 1; j <= die_point - i; j++) {
												a_3_2->cur_pos = a_3_2->cur_pos->next;
											}
										}
									}
									if (flag)break;
									a_3_2->cur_pos = a_3_2->cur_pos->next;
								}
								oneout[player] = 1;
								a_3_2->state = 1;
								if (check_allout(3))allout[player] = 1;
								check_eat(3, a_3_2->cur_pos);
								moved = 1;
								return;
							}
						}
				else if (a_3_3->state == 1) {
							check_anyone(a_3_3->cur_pos, a_3_3, 3); moved = 1;
							if (onrunway(a_3_3, 3)) {
								if (die_point == 6 - a_3_3->cur_pos->num) {
									a_3_3->cur_pos = NULL;
									a_3_3->state = 2;
								}
								else {
									square* t = runway_3_1;
									int a; if (a_3_3->cur_pos->num + die_point > 6)a = 12 - (a_3_3->cur_pos->num + die_point);
									else a = a_3_3->cur_pos->num + die_point;
									for (int i = 1; i < a; i++) {
										t = t->next;
									}a_3_3->cur_pos = t;
								}
								return;
							}
							else {
								for (int i = 1; i <= die_point; i++) {
									bool flag = 0;
									if (a_3_3->cur_pos->num == 37) {
										flag = 1;
										a_3_3->cur_pos = runway_3_1;
										if (die_point == 6) {
											a_3_3->cur_pos = NULL; a_3_3->state = 2;
										}
										else {
											for (int j = 1; j <= die_point - i; j++) {
												a_3_3->cur_pos = a_3_3->cur_pos->next;
											}
										}
									}
									if (flag)break;
									a_3_3->cur_pos = a_3_3->cur_pos->next;
								}
								oneout[player] = 1;
								a_3_3->state = 1;
								if (check_allout(3))allout[player] = 1;
								check_eat(3, a_3_3->cur_pos);
								moved = 1;
								return;
							}
						}
				else if (a_3_4->state == 1) {
							check_anyone(a_3_4->cur_pos, a_3_4, 3); moved = 1;
							if (onrunway(a_3_4, 3)) {
								if (die_point == 6 - a_3_4->cur_pos->num) {
									a_3_4->cur_pos = NULL;
									a_3_4->state = 2;
								}
								else {
									square* t = runway_3_1;
									int a; if (a_3_4->cur_pos->num + die_point > 6)a = 12 - (a_3_4->cur_pos->num + die_point);
									else a = a_3_4->cur_pos->num + die_point;
									for (int i = 1; i < a; i++) {
										t = t->next;
									}a_3_4->cur_pos = t;
								}
								return;
							}
							else {
								for (int i = 1; i <= die_point; i++) {
									bool flag = 0;
									if (a_3_4->cur_pos->num == 37) {
										flag = 1;
										a_3_4->cur_pos = runway_3_1;
										if (die_point == 6) {
											a_3_4->cur_pos = NULL; a_3_4->state = 2;
										}
										else {
											for (int j = 1; j <= die_point - i; j++) {
												a_3_4->cur_pos = a_3_4->cur_pos->next;
											}
										}
									}
									if (flag)break;
									a_3_4->cur_pos = a_3_4->cur_pos->next;
								}
								oneout[player] = 1;
								a_3_4->state = 1;
								if (check_allout(3))allout[player] = 1;
								check_eat(3, a_3_4->cur_pos);
								moved = 1;
								return;
							}
						}
		}
		else if (allout[player]) {
			
						if (a_3_1->state == 1) {
							check_anyone(a_3_1->cur_pos, a_3_1, 3); moved = 1;
							if (onrunway(a_3_1, 3)) {
								if (die_point == 6 - a_3_1->cur_pos->num) {
									a_3_1->cur_pos = NULL;
									a_3_1->state = 2;
								}
								else {
									square* t = runway_3_1;
									int a; if (a_3_1->cur_pos->num + die_point > 6)a = 12 - (a_3_1->cur_pos->num + die_point);
									else a = a_3_1->cur_pos->num + die_point;
									for (int i = 1; i < a; i++) {
										t = t->next;
									}a_3_1->cur_pos = t;
								}
								return;
							}
							else {
								for (int i = 1; i <= die_point; i++) {
									bool flag = 0;
									if (a_3_1->cur_pos->num == 37) {
										flag = 1;
										a_3_1->cur_pos = runway_3_1;
										if (die_point == 6) {
											a_3_1->cur_pos = NULL; a_3_1->state = 2;
										}
										else {
											for (int j = 1; j <= die_point - i; j++) {
												a_3_1->cur_pos = a_3_1->cur_pos->next;
											}
										}
									}
									if (flag)break;
									a_3_1->cur_pos = a_3_1->cur_pos->next;
								}
								oneout[player] = 1;
								a_3_1->state = 1;
								if (check_allout(3))allout[player] = 1;
								check_eat(3, a_3_1->cur_pos);
								moved = 1;
								return;
							}
						}
						else if (a_3_2->state == 1) {
							check_anyone(a_3_2->cur_pos, a_3_2, 3); moved = 1;
							if (onrunway(a_3_2, 3)) {
								if (die_point == 6 - a_3_2->cur_pos->num) {
									a_3_2->cur_pos = NULL;
									a_3_2->state = 2;
								}
								else {
									square* t = runway_3_1;
									int a; if (a_3_2->cur_pos->num + die_point > 6)a = 12 - (a_3_2->cur_pos->num + die_point);
									else a = a_3_2->cur_pos->num + die_point;
									for (int i = 1; i < a; i++) {
										t = t->next;
									}a_3_2->cur_pos = t;
								}
								return;
							}
							else {
								for (int i = 1; i <= die_point; i++) {
									bool flag = 0;
									if (a_2_2->cur_pos->num == 37) {
										flag = 1;
										a_3_2->cur_pos = runway_3_1;
										if (die_point == 6) {
											a_3_2->cur_pos = NULL; a_3_2->state = 2;
										}
										else {
											for (int j = 1; j <= die_point - i; j++) {
												a_3_2->cur_pos = a_3_2->cur_pos->next;
											}
										}
									}
									if (flag)break;
									a_3_2->cur_pos = a_3_2->cur_pos->next;
								}
								oneout[player] = 1;
								a_3_2->state = 1;
								if (check_allout(3))allout[player] = 1;
								check_eat(3, a_3_2->cur_pos);
								moved = 1;
								return;
							}
						}
						else if (a_3_3->state == 1) {
							check_anyone(a_3_3->cur_pos, a_3_3, 3); moved = 1;
							if (onrunway(a_3_3, 3)) {
								if (die_point == 6 - a_3_3->cur_pos->num) {
									a_3_3->cur_pos = NULL;
									a_3_3->state = 2;
								}
								else {
									square* t = runway_3_1;
									int a; if (a_3_3->cur_pos->num + die_point > 6)a = 12 - (a_3_3->cur_pos->num + die_point);
									else a = a_3_3->cur_pos->num + die_point;
									for (int i = 1; i < a; i++) {
										t = t->next;
									}a_3_3->cur_pos = t;
								}
								return;
							}
							else {
								for (int i = 1; i <= die_point; i++) {
									bool flag = 0;
									if (a_3_3->cur_pos->num == 37) {
										flag = 1;
										a_3_3->cur_pos = runway_3_1;
										if (die_point == 6) {
											a_3_3->cur_pos = NULL; a_3_3->state = 2;
										}
										else {
											for (int j = 1; j <= die_point - i; j++) {
												a_3_3->cur_pos = a_3_3->cur_pos->next;
											}
										}
									}
									if (flag)break;
									a_3_3->cur_pos = a_3_3->cur_pos->next;
								}
								oneout[player] = 1;
								a_3_3->state = 1;
								if (check_allout(3))allout[player] = 1;
								check_eat(3, a_3_3->cur_pos);
								moved = 1;
								return;
							}
						}
						else if (a_3_4->state == 1) {
							check_anyone(a_3_4->cur_pos, a_3_4, 3); moved = 1;
							if (onrunway(a_3_4, 3)) {
								if (die_point == 6 - a_3_4->cur_pos->num) {
									a_3_4->cur_pos = NULL;
									a_3_4->state = 2;
								}
								else {
									square* t = runway_3_1;
									int a; if (a_3_4->cur_pos->num + die_point > 6)a = 12 - (a_3_4->cur_pos->num + die_point);
									else a = a_3_4->cur_pos->num + die_point;
									for (int i = 1; i < a; i++) {
										t = t->next;
									}a_3_4->cur_pos = t;
								}
								return;
							}
							else {
								for (int i = 1; i <= die_point; i++) {
									bool flag = 0;
									if (a_3_4->cur_pos->num == 37) {
										flag = 1;
										a_3_4->cur_pos = runway_3_1;
										if (die_point == 6) {
											a_3_4->cur_pos = NULL; a_3_4->state = 2;
										}
										else {
											for (int j = 1; j <= die_point - i; j++) {
												a_3_4->cur_pos = a_3_4->cur_pos->next;
											}
										}
									}
									if (flag)break;
									a_3_4->cur_pos = a_3_4->cur_pos->next;
								}
								oneout[player] = 1;
								a_3_4->state = 1;
								if (check_allout(3))allout[player] = 1;
								check_eat(3, a_3_4->cur_pos);
								moved = 1;
								return;
							}
						}
					
	}
}
}
void mode_3() {
	while (!game_ends) {
		showplane();
		int die_point;
		player = (player + 1) % 4;//切换玩家
		die_point = getDieRes();//投骰子
		move(player, die_point);//移动部分的判断
		game_ends = judge();//判断游戏是否结束
	}return;
}

void start() //开始界面
{
	IMAGE img;
	loadimage(&img, L"./start.jpg");
	putimage(0, 0, &img);
	while (1) {
		bool end = 0;
		ExMessage msg;
		if (peekmessage(&msg, EX_MOUSE)) {
			switch (msg.message) {
			case WM_LBUTTONDOWN:
			{
				if (msg.x >= 475 && msg.x <= 680 && msg.y >= 502 && msg.y <= 577) {
					Createlist();
					Createplane();
					IMAGE img;
					loadimage(&img, L"./map.jpg");
					putimage(0, 0, &img);
					IMAGE img1;
					loadimage(&img1, L"./dieres.png");
					putimage(910, 550, &img1);
					mode_3();
					end = 1;
					break;
				}
			}
			default:break;
			}
		}
		if (end)return;
	}

}

int main() {
	initgraph(1100, 830);
	setbkcolor(WHITE);
	cleardevice();
	start();
	return 0;
}