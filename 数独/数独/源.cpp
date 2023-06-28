#include <iostream>
#include <windows.h>
#include <cstring>
#include <cstdio>
#include<windows.h>
using namespace std;
int shudu[10][10] = { 0 };
bool flag1[82] = { 0 };//flag1��ʾ��9*��i-1��+j�������Ƿ������
bool flag2[82] = { 0 };//flag2��1-9��ʾ��һ�е�����10-18��ʾ�ڶ��е���......73-81��ʾ�ھ��е���
bool flag3[82] = { 0 };//flag3��1-9��ʾ��һ�е�����10-18��ʾ�ڶ��е���......73-81��ʾ�ھ��е���
bool flag4[82] = { 0 };//flag4��1-9��ʾ��һ��������10-18��ʾ�ڶ�������......73-81��ʾ�ھŹ�����

//ȷ��ÿ�������ڹ�(x,y��������ԭ�����е�����)
int palace(int x, int y) {
	/*���ķֲ�
	1 2 3
	4 5 6
	7 8 9 */
	return(((x - 1) / 3) * 3 + (y - 1) / 3 + 1);//���ڵĹ�
}

//�����������
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
//input֮����ɶ�4��������flag����ĳ�ʼ��
void output() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << shudu[i][j] << " ";
		}cout << endl;
	}
}
struct num {
	int x; int y;//x��y��ָ�õ�����
	int number;//number��ָ�õ����ֵ
};
num a[730];
//��������ʮ��˫��ѭ������ı�ʾͼ
int map[730][325] = { 0 };
int n = 1;
void setmatrix() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {//��������
			if (shudu[i][j] == 0) {//��δ����
				for (int k = 1; k <= 9; k++) {// ����k
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
						n++;//�޸�bug
					}
				}
			}
		}
	}
}
//��������ʮ��ѭ��˫������
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
	//����ÿ��֮�ڵ�ѭ���б�
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
	//����0�е�ѭ���б�
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
				c[i]->right = p->right;//�޸�bug
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
				c[i]->right = p->right;//�޸�bug
				p->right = c[i];
				c[i]->left = p;
				p = c[i];
				c[i]->column = i;
			}

		}
	}
	//������֮���ѭ������
	for (int i = 1; i < 325; i++) {//��
		if (i < 82 && flag1[i])continue;
		if (i >= 82 && i < 163 && flag2[i - 81])continue;
		if (i >= 163 && i < 244 && flag3[i - 162])continue;
		if (i >= 244 && flag4[i - 243])continue;//�޸�bug
		{
			p = c[i]; p->down = p->up = p;
		}//�޸Ĺ�bug
		for (int j = 1; j < 730; j++) {//��
			if (map[j][i]) {//�޸�bug
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
//down_delete����������ɾ����ѡ����Ǹ�1ͬһ�е�1���ڵ���
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
//������dfs��������
bool anss;
int solu = 0;
int s = 0;
void dfs()
{
	if (head->right == head)
	{
		s++;
		cout << "�ⷨ" << s << ":" << endl;
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
		//�ǵñ��һ����һ�ε�ѡ��
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
	cout << "������������Ŀ:" << endl;
	input();
	cout << "���������������Ľ�ĸ���:" << endl;
	cin >> solu;
	cout << endl;
	setmatrix();
	linkedlist();
	dfs();
	if (s < solu)cout << "��Ǹ������" << s << "����";
	cout << endl << endl;
	cout << "����������������Ŀ��Ҫ�����" << endl << "����������Y," << "���޿��������������ַ���������лʹ��" << endl << endl << endl;
	char temp = '\0';
	cin >> temp;
	if (temp == 'Y')
	{
		system("cls");
		bool bIsRunAgain = true;
		if (bIsRunAgain)
		{   //������������CSDN
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

