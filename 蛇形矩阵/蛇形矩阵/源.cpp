#include <cstdio>
int a[31][31] = { 0 };
int main() {
	bool flag = 1;
	int n;
	scanf_s("%d", &n);
	int m = 0;
	for (m; m <= n - 1; m++) {
		if (flag) {
			for (int i = 0, int j = m; i <= m; i++, j--) {
				a[i][j] = m * (m - 1) / 2 + i + 1;
			}flag = 0; continue;
		}
		else {
			for (int i = m, int j = 0; j <= m; i--, j++) {
				a[i][j] = m * (m - 1) / 2 + j + 1;
			}flag = 1; continue;
		}
	}

	for (int i = 0; i <= n - 1; i++) {
		for (int j = 0; j <= n - 1; j++) {
			printf("%4d", a[i][j]);
		}printf("\d");
	}return 0;
}