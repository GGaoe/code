#include <iostream>
using namespace std;
int a[100][100];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int top = 0, floor = n - 1, left = 0, right = m - 1;
	bool flag1 = 1, flag2 = 1;
	while (top != floor + 1 && left != right + 1) {
		if (flag1 && flag2) {
			for (int i = left; i <= right; i++) {
				cout << a[top][i]<<" ";
			}top++; flag2 = 0; continue;
		}
		if (flag1 && !flag2) {
			for (int i = top; i <= floor; i++) {
				cout << a[i][right]<<" ";
			}right--; flag1 = 0; continue;
		}if (!flag1 && !flag2) {
			for (int i = right; i >= left; i--) {
				cout << a[floor][i]<<" ";
			}floor--; flag2 = 1; continue;
		}if (!flag1 && flag2) {
			for (int i = floor; i >= top; i--) {
				cout << a[i][left]<<" ";
			}left++; flag1 = 1; continue;
		}
	}return 0;
}