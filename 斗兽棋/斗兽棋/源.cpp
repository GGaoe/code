#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int z[3][3];//z的棋盘
int d[3][3];//dxy的棋盘
bool z1[3][3];
bool d1[3][3];
int pointz[9];//z的点数
int pointd[9];//d的点数
int pos[9];//z放置的位置
int hand[9];//dxy放棋的位置及评价
void chushihua() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			z[i][j] = 0;
			d[i][j] = 0;
			z1[i][j] = 1;
			d1[i][j] = 1;
		}
	}
}
int result(int a0,int a1,int a2) {
	if (a0 == a1 && a0 == a2)return 9 * a1;
	else if (a0 == a1 && a0 != a2) return 4 * a0 + a2;
	else if (a0 == a2 && a0 != a1)return 4 * a0 + a1;
	else if (a1 == a2 && a0 != a2)return 4 * a1 + a0;
	else return (a0 + a1 + a2);
}
int numm = 0;
stack <int> z_destroy;//摧毁棋子的大小
stack <int> z_pos;//位置
stack <int> step;
stack <int> leng;
stack <int> d_len;
stack <int> d_col;
int a[9];
bool flag = 0;
extern void remove(int numm);
int put(int numm) {
	cout << "numm"<<numm <<endl;
	if (numm == 9) {
		cout <<"d->"<< result(d[0][0], d[1][0], d[2][0]) + result(d[0][1], d[1][1], d[2][1]) + result(d[0][2], d[1][2], d[2][2]) <<"  ";
		cout <<"z->"<< result(z[0][0], z[1][0], z[2][0]) + result(z[0][1], z[1][1], z[2][1]) + result(z[0][2], z[1][2], z[2][2]) << endl;

		if (result(d[0][0], d[1][0], d[2][0]) + result(d[0][1], d[1][1], d[2][1]) + result(d[0][2], d[1][2], d[2][2]) >
			result(z[0][0], z[1][0], z[2][0]) + result(z[0][1], z[1][1], z[2][1]) + result(z[0][2], z[1][2], z[2][2]))
		{
			flag = 1;
			return 0;
		}
	}
	else {
		//z下棋
		for (int i = 0; i < 3; i++) {
			if (z[i][pos[numm] - 1] == 0 && z1[i][pos[numm] - 1]) {
				z[i][pos[numm] - 1] = pointz[numm];
				for (int j = 0; j < 3; j++) {
					if (d[j][pos[numm]-1]==pointz[numm]) {//destroy
						d[j][pos[numm] - 1] = 0; d1[j][pos[numm] - 1] = 0;
						
					}
				}break;
			}
		}
		//d下棋
		if (hand[numm] > 0) {
			for (int i = 0; i < 3; i++) {
				if (d[i][hand[numm] - 1] == 0 && d1[i][hand[numm] - 1]) {
					d[i][hand[numm] - 1] = pointd[numm]; step.push(hand[numm]);
					cout  <<"hand[numm]->"<<hand[numm] << endl;//
					d_len.push(i); d_col.push(hand[numm] - 1);
					for (int j = 0; j < 3; j++) {
						if (z[j][hand[numm] - 1] == pointd[numm]) {//destroy
							z_pos.push(hand[numm] - 1);
							leng.push(j);
							z_destroy.push(z[j][hand[numm] - 1]);//推入动态数组中
							a[numm]++;
							z[j][hand[numm] - 1] = 0; z1[j][hand[numm] - 1] = 0;

						}
					}put(numm + 1);
					break;
				}
				else return 0;
			}
		}
		else if (hand[numm] == 0) {
			if (d[2][0] == 0 && d1[2][0])//放第一列
			{
				for (int i = 0; i < 3; i++) {
					if (d[i][0] == 0 && d1[i][0]) {
						d[i][0] = pointd[numm]; step.push(1);
						cout  << 1 << endl;//
						d_len.push(i); d_col.push(0);
						for (int j = 0; j < 3; j++) {
							if (z[j][0]==pointd[numm]) {//destroy
								z_pos.push(0);
								leng.push(j);
								z_destroy.push(z[j][0]);//推入动态数组中
								a[numm]++;
								z[j][0] = 0; z1[j][0] = 0;
								
							}
						}put(numm + 1);
						remove(numm);
						break;
					}
				}
			}
			if (d[2][1] == 0 && d1[2][1])//放第2列
			{
				for (int i = 0; i < 3; i++) {
					if (d[i][1] == 0 && d1[i][1]) {
						d[i][1] = pointd[numm]; step.push(2);
						cout  <<2 << endl;//
						d_len.push(i); d_col.push(1);
						for (int j = 0; j < 3; j++) {
							if (z[j][1]==pointd[numm]) {//destroy
								z_pos.push(1);
								leng.push(j);
								z_destroy.push(z[j][1]);//推入动态数组中
								a[numm]++;
								z[j][1] = 0; z1[j][1] = 0;
								
							}
						}put(numm + 1);
						remove(numm);
						break;
					}
				}
			}
			if (d[2][2] == 0 && d1[2][2])//放第3列
			{
				for (int i = 0; i < 3; i++) {
					if (d[i][2] == 0 && d1[i][2]) {
						d[i][2] = pointd[numm]; step.push(3);
						cout<<3<< endl;//
						d_len.push(i); d_col.push(2);
						for (int j = 0; j < 3; j++) {
							if (z[j][2] == pointd[numm]) {//destroy
								z_pos.push(2);
								leng.push(j);
								z_destroy.push(z[j][2]);//推入动态数组中
								a[numm]++;
								z[j][2] = 0; z1[j][2] = 0;
								
							}
						}put(numm + 1);
						remove(numm); break;
					}
				}
			}
		}
		else {
			if (d[2][0] == 0 && d1[2][0] && hand[numm] != -1)//放第一列
			{
				for (int i = 0; i < 3; i++) {
					if (d[i][0] == 0 && d1[i][0]) {
						d[i][0] = pointd[numm]; step.push(1);
						cout<<1 << endl;//
						d_len.push(i); d_col.push(0);
						for (int j = 0; j < 3; j++) {
							if (z[j][0] == pointd[numm]) {//destroy
								z_pos.push(0);
								leng.push(j);
								z_destroy.push(z[j][0]);//推入动态数组中
								a[numm]++;
								z[j][0] = 0; z1[j][0] = 0;
								
							}
						}put(numm + 1);
						remove(numm);
						break;
					}
				}
			}
			if (d[2][1] == 0 && d1[2][1] && hand[numm] != -2)//放第2列
			{
				for (int i = 0; i < 3; i++) {
					if (d[i][1] == 0 && d1[i][1]) {
						d[i][1] = pointd[numm]; step.push(2);
						cout<<2 << endl;//
						d_len.push(i); d_col.push(1);
						for (int j = 0; j < 3; j++) {
							if (z[j][1] == pointd[numm]) {//destroy
								z_pos.push(1);
								leng.push(j);
								z_destroy.push(z[j][1]);//推入动态数组中
								a[numm]++;
								z[j][1] = 0; z1[j][1] = 0;
								
							}
						}put(numm + 1);
						remove(numm); break;
					}
				}
			}
			if (d[2][2] == 0 && d1[2][2] && hand[numm] != -3)//放第3列
			{
				for (int i = 0; i < 3; i++) {
					if (d[i][2] == 0 && d1[i][2]) {
						d[i][2] = pointd[numm]; step.push(3);
						cout<< 3 << endl;//
						d_len.push(i); d_col.push(2);
						for (int j = 0; j < 3; j++) {
							if (z[j][2] == pointd[numm]) {//destroy
								z_pos.push(2);
								leng.push(j);
								z_destroy.push(z[j][2]);//推入动态数组中
								a[numm]++;
								z[j][2] = 0; z1[j][2] = 0;
								
							}
						}put(numm + 1);
						remove(numm); break;
					}
				}
				
			}
		}

	}
}
void remove(int numm) {
	for (int i = 0; i < a[numm]; i++) {
		int len = leng.top();
		leng.pop();
		int col = z_pos.top();
		z_pos.pop();
		z1[len][col] = 1;
		int value = z_destroy.top();
		z_destroy.pop();
		z[len][col] = value;
		cout <<endl<< "len->" << len << "  col->" << col << "  value->" << value << endl;
	}
	a[numm] = 0;
	step.pop();
	int d_l = d_len.top();
	d_len.pop();
	int d_c = d_col.top();
	d_col.pop();
	d[d_l][d_c] = 0;
}

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> pointz[i];//z的点数
	}
	for (int i = 0; i < 9; i++) {
		cin >> pointd[i];//d的点数
	}
	for (int i = 0; i < 9; i++) {
		cin >> pos[i];//z放的位置
	}
	for (int i = 0; i < 9; i++) {
		cin >> hand[i];//妙手/俗手-》正的保留负的去除
	}
	chushihua();
	put(0);
	if (flag) {
		cout << "yes" << endl;
		int a[9] = { 0 };
		for (int i = 0; i < 9; i++) {
			a[i] = step.top();
			step.pop();
		}
		for (int i = 8; i >= 0; i--) {
			cout << a[i] << " ";
		}
	}
	else cout << "No";
	return 0;
}