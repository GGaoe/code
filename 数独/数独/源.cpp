#include <iostream>
#include <windows.h>
#include <cstring>
#include <cstdio>
#include<windows.h>
using namespace std;
int shudu[10][10] = { 0 };
bool flag1[82] = { 0 };//flag1表示第9*（i-1）+j个格子是否填过数
bool flag2[82] = { 0 };//flag2：1-9表示第一行的数，10-18表示第二行的数......73-81表示第九行的数
bool flag3[82] = { 0 };//flag3：1-9表示第一列的数，10-18表示第二列的数......73-81表示第九列的数
bool flag4[82] = { 0 };//flag4：1-9表示第一宫的数，10-18表示第二宫的数......73-81表示第九宫的数

//确定每个数所在宫(x,y是数字在原数独中的坐标)
int palace(int x, int y) {
	/*宫的分布
	1 2 3
	4 5 6
	7 8 9 */
	return(((x - 1) / 3) * 3 + (y - 1) / 3 + 1);//所在的宫
}

//输入输出函数
void input() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> shudu[i][j];
			if (shudu[i][j] != 0) {
				flag1[9 * (i - 1) + j] = 1;
				flag2[9 * (i - 1) + shudu[i][j]] = 1;
				flag3[9 * (j - 1) + shudu[i][j]] = 1;
				flag4[(palace(i, j) - 1) * 9 + shudu[i][j]] = 1;

			}
		}
	}
}
//input之后完成对4个布尔型flag数组的初始化
void output() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << shudu[i][j] << " ";
		}cout << endl;
	}
}
struct num {
	int x; int y;//x，y代指该点坐标
	int number;//number代指该点的数值
};
num a[730];
//构建交叉十字双向循环链表的表示图
int map[730][325] = { 0 };
int n = 1;
void setmatrix() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {//遍历数独
			if (shudu[i][j] == 0) {//若未填数
				for (int k = 1; k <= 9; k++) {// 填入k
					if (flag2[9 * (i - 1) + k] == 0
						&& flag3[9 * (j - 1) + k] == 0
						&& flag4[(palace(i, j) - 1) * 9 + k] == 0
						)
					{
						map[n][9 * (i - 1) + j] = 1;
						map[n][81 + 9 * (i - 1) + k] = 1;
						map[n][162 + 9 * (j - 1) + k] = 1;
						map[n][243 + 9 * (palace(i, j) - 1) + k] = 1;
						a[n].x = i;
						a[n].y = j;
						a[n].number = k;
						//cout << a[n].number<<endl;
						n++;//修改bug
					}
				}
			}
		}
	}
}
//建立交叉十字循环双向链表
struct node {
	node* up;
	node* down;
	node* left;
	node* right;
	int line; int column;
	num h;
	node() :up(NULL), down(NULL), left(NULL), right(NULL), line(0), column(0) {}
};
node* head; node* c[350];
node* matrix[730][325];
int count1[325];
void linkedlist() {
	node* p;
	//建立每行之内的循环列表
	for (int i = 1; i <= n; i++) {

		p = NULL;
		for (int j = 1; j <= 324; j++) {
			if (map[i][j] == 1) {
				matrix[i][j] = new node;
				matrix[i][j]->line = i;
				matrix[i][j]->column = j;
				matrix[i][j]->h = a[i];
				//cout << a[n].number<<endl;
				//cout << matrix[i][j]->h.number << endl;
				if (p == NULL) {
					matrix[i][j]->left = matrix[i][j];
					matrix[i][j]->right = matrix[i][j];
					p = matrix[i][j];
				}
				else {
					matrix[i][j]->right = p->right;
					p->right->left = matrix[i][j];
					matrix[i][j]->left = p;
					p->right = matrix[i][j];
					p = matrix[i][j];
				}
			}
			else {
				matrix[i][j] = NULL;
			}
		}
	}
	//建立0行的循环列表
	{
		p = head = new node;
		p->right = head;
		p->left = head;
		for (int i = 1; i <= 81; i++) {
			if (flag1[i])c[i] = NULL;
			else {
				c[i] = new node();
				count1[i] = 0;
				p->right->left = c[i];
				c[i]->right = p->right;
				p->right = c[i];
				c[i]->left = p;
				p = c[i];
				c[i]->column = i;
			}

		}

		for (int i = 82; i <= 162; i++) {
			if (flag2[i - 81])c[i] = NULL;
			else {
				c[i] = new node();
				count1[i] = 0;
				p->right->left = c[i];
				c[i]->right = p->right;
				p->right = c[i];
				c[i]->left = p;
				p = c[i];
				c[i]->column = i;
			}

		}
		for (int i = 163; i <= 243; i++) {
			if (flag3[i - 162])c[i] = NULL;
			else {
				c[i] = new node();
				count1[i] = 0;
				p->right->left = c[i];
				c[i]->right = p->right;//修改bug
				p->right = c[i];
				c[i]->left = p;
				p = c[i];
				c[i]->column = i;
			}

		}

		for (int i = 244; i <= 324; i++) {
			if (flag4[i - 243])c[i] = NULL;
			else {
				c[i] = new node();
				count1[i] = 0;
				p->right->left = c[i];
				c[i]->right = p->right;//修改bug
				p->right = c[i];
				c[i]->left = p;
				p = c[i];
				c[i]->column = i;
			}

		}
	}
	//建立列之间的循环链表
	for (int i = 1; i < 325; i++) {//列
		if (i < 82 && flag1[i])continue;
		if (i >= 82 && i < 163 && flag2[i - 81])continue;
		if (i >= 163 && i < 244 && flag3[i - 162])continue;
		if (i >= 244 && flag4[i - 243])continue;//修改bug
		{
			p = c[i]; p->down = p->up = p;
		}//修改过bug
		for (int j = 1; j < 730; j++) {//行
			if (map[j][i]) {//修改bug
				count1[i]++;
				if (p == NULL)cout << "false" << endl;
				p->down->up = matrix[j][i]; matrix[j][i]->down = p->down;
				p->down = matrix[j][i]; matrix[j][i]->up = p;
				p = matrix[j][i];
			}
		}
	}

}
void delete_line(node* x) {
	x->right->left = x->left;
	x->left->right = x->right;
}
void delete_column(node* x) {
	x->down->up = x->up;
	x->up->down = x->down;
}
void add_line(node* x) {
	x->left->right = x;
	x->right->left = x;
}
void add_column(node* x) {
	x->up->down = x;
	x->down->up = x;
}
//down_delete函数，用于删除与选择的那个1同一列的1所在的行
node* zhan[1000];
int tt = 0;
void down_delete(node* x)
{

	for (node* i = x->down; i != x; i = i->down)
	{
		if (i->line == 0)continue;
		zhan[++tt] = i;
		delete_column(i), count1[i->column]--;
		for (node* j = i->right; j != i; j = j->right)
			delete_column(j), count1[j->column]--;
	}
}
//以下是dfs函数部分
bool anss;
int solu = 0;
int s = 0;
void dfs()
{
	if (head->right == head)
	{
		s++;
		cout << "解法" << s << ":" << endl;
		output();
		cout << endl;
		return;
	}
	node* p = head->right;
	for (node* i = p->right; i != head; i = i->right)
		if (count1[i->column] < count1[p->column])p = i;
	for (node* i = p->down; i != p; i = i->down)
	{

		int st = tt;
		{
			down_delete(i); delete_line(c[i->column]);
		}
		for (node* j = i->right; j != i; j = j->right)
		{
			down_delete(j), delete_line(c[j->column]);
		}
		zhan[++tt] = i;
		delete_column(i), count1[i->column]--;
		for (node* j = i->right; j != i; j = j->right)
			delete_column(j), count1[j->column]--;
		shudu[i->h.x][i->h.y] = i->h.number;
		//记得标记一下这一次的选择
		dfs();
		if (s == solu)return;
		for (node* j = zhan[tt]->left; j != zhan[tt]; j = j->left)
			add_line(c[j->column]);
		add_line(c[zhan[tt]->column]);
		while (tt > st)
		{
			add_column(zhan[tt]), count1[zhan[tt]->column]++;
			for (node* j = zhan[tt]->right; j != zhan[tt]; j = j->right)
				add_column(j), count1[j->column]++;
			tt--;
		}
	}
}
int main()
{
	cout << "请输入数独题目:" << endl;
	input();
	cout << "请输入你所期望的解的个数:" << endl;
	cin >> solu;
	cout << endl;
	setmatrix();
	linkedlist();
	dfs();
	if (s < solu)cout << "抱歉，仅有" << s << "个解";
	cout << endl << endl;
	cout << "您还有其他数独题目需要解决吗？" << endl << "若有请输入Y," << "若无可输入其他任意字符结束，感谢使用" << endl << endl << endl;
	char temp = '\0';
	cin >> temp;
	if (temp == 'Y')
	{
		system("cls");
		bool bIsRunAgain = true;
		if (bIsRunAgain)
		{   //重启函数引自CSDN
			TCHAR szPath[MAX_PATH];
			GetModuleFileName(NULL, szPath, MAX_PATH);
			STARTUPINFO StartInfo;
			PROCESS_INFORMATION procStruct;
			memset(&StartInfo, 0, sizeof(STARTUPINFO));
			StartInfo.cb = sizeof(STARTUPINFO);
			if (!::CreateProcess(
				(LPCTSTR)szPath,
				NULL,
				NULL,
				NULL,
				FALSE,
				NORMAL_PRIORITY_CLASS,
				NULL,
				NULL,
				&StartInfo,
				&procStruct))
				return 0;
		}

	}
	else
		return 0;
}

