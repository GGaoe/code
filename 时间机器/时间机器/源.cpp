#include <iostream>
using namespace std;
int a[32][32];
int main() {
	int n;
	int num = 1;
	cin >> n;
	int b = 0, c = 0; bool t1=1,t2 = 1;//b为上方，c为左方——t1&&t2:上方正向；t1：右方正向；0：下方逆向；t2：左方逆向
	if (n % 2 == 0) {//偶数情况
		int l = n - 1, C = n - 1;//l为下方，C为右方
		while (b != n / 2 || C != n / 2 - 1) {
			if (t1 && t2) {
				for (int i = c; i <= l; i++) {
					a[b][i] = num; num++;
				}t2 = 0; b++;  continue;
			}
			if (t1 && !t2) {
				for (int i = b; i <= C; i++) {
					a[i][C] = num; num++;
				}t1 = 0; C--; continue;
			}
			if (!(t1 || t2)) {
				for (int i = C; i >= c; i--) {
					a[l][i] = num; num++;
				}t2 = 1; l--;  continue;
			}
			if (t2 && !t1) {
				for (int i = l; i >= b; i--) {
					a[i][c] = num; num++;
				}t1 = 1; c++; continue;
			}
		}a[b][C] = num;
	}
			if (n % 2 != 0) {//奇数情况
				int l = n - 1, C = n - 1;//l为下方，C为右方
				while (b != (n + 1) / 2 || c != (n - 1) / 2) {
					if (t1 && t2) {
						for (int i = c; i <= l; i++) {
							a[b][i] = num; num++;
						}t2 = 0; b++; continue;
					}
					if (t1 && !t2) {
						for (int i = b; i <= C; i++) {
							a[i][C] = num; num++;
						}t1 = 0; C--; continue;
					}
					if (!(t1 || t2)) {
						for (int i = C; i >= c; i--) {
							a[l][i] = num; num++;
						}t2 = 1; l--; continue;
					}
					if (t2 && !t1) {
						for (int i = l; i >= b; i--) {
							a[i][c] = num; num++;
						}t1 = 1; c++;  continue;
					}
				}
		}for (int i = 0; i <= n - 1; i++) {
			for (int j = 0; j <= n - 1; j++) {
				printf("%4d", a[i][j]);
			}cout << endl;
		}return 0;
}