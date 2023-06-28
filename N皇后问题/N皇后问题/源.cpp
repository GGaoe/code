#include <iostream>
using namespace std;
char a[10][10];//存放棋盘
int x[10];//存放每一行中皇后的位置
int num[10];//存放每一行是否有皇后
int n;

bool isplace(int row, int col) {
	for (int i = 1; i <= n; i++) {
		if (num[i]) {
			if (col == x[i] || abs(col - x[i]) == abs(row - i))return false;
		}
	  }
	return true;
}

bool backtrack(int t, int n) {
	if (t == n + 1)return true;
	else if (num[t] == 1) return backtrack(t + 1, n);
	else {
		bool flag = 0;
		for (int i = 1; i <= n; i++) {
			if (isplace(t, i)) {
				flag = 1;
				x[t] = i;
				num[t] = 1;
				if (backtrack(t+1, n)) {
					return true;
				}
				else { num[t] = 0; flag = 0; }
			}
		}if (!flag)return false;
	}
}
int main() {
	 cin >> n;
	 for (int i = 1; i <= n; i++) {
		 for (int j = 1; j <= n; j++) {
			 cin >> a[i][j];
			 if (a[i][j] == 'Q') {
				 num[i] = 1;
				 x[i] = j;
			 }
			 
		 }
	 }
		backtrack(1, n);
		//for (int i = 1; i <= n; i++) { cout << x[i] << " "; }
		if (backtrack(1, n)) {
			cout << "yes" << endl;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (x[i] == j)cout << "Q";
					else cout << ".";
				}cout << endl;
			}
		}
	else cout << "No" << endl;
	return 0;
}