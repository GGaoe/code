#include <iostream>
#include <cmath>
using namespace std;
int max_ys(int a, int b) {//a·Ö×Ó£¬b·ÖÄ¸
	int ys = b%a; int cs = a;
	int middle=ys;
	while (ys != 0) {
		middle = cs % ys; cs = ys;
		if (middle != 0) { ys = middle; }
		else break;
	}
	if (cs!= 1)return 0;
	else return 1;
}
int zs(int a, int b) {
	bool flag1 = 1;
	bool flag2 = 1;
	if (a == 1 || b == 1)return 0;
	else {
		if (a != 2) {
			for (int i = 2; i <= pow(a, 0.5); i++) {
				if (a % i == 0)flag1 = 0;
			}
		}
		if (b != 2) {
			for (int i = 2; i <= pow(b, 0.5); i++) {
				if (b % i == 0)flag2 = 0;
			}
		}
		if (flag1 && flag2) {
			return 1;
		}
		else return 0;
	}
}

int main() {
	int n; cin >> n; int fs = 0, gs = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (max_ys(j, i) == 1)
			{
				fs++;
			}
			if (zs(i, j) == 1)
			{
				gs++;
			}
		}
	}
	cout << fs << " " << gs;
	return 0;
}