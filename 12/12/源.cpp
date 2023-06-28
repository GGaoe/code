#include <cstdio>
using namespace std;

int a[31][31];

int main() {
	bool flag = 1;
	int n;
	scanf_s("%d", &n);
	int m = 0;
	for (m; m <= n - 1; m++) {
		if (flag==0) {
			int j = m;
			for (int i = 0; i <= m; i++) {
				a[i][j] = (m) * (m + 1) / 2 + i + 1;j--;
			}
			flag = 1; continue;
		}
		else {
			int i = m;
			for (int j = 0; j <= m;j++) {
				a[i][j] = (m) * (m +1) / 2 + j + 1;i--;
			}
			flag = 0; continue;
		}
	}
	m=n;
	for (m; m <= 2*n-1; m++) {
		if (flag==0) {
			int j = n - 1;
			for (int i = m-n+1; i <= n-1; i++) {
				a[i][j] = (n) * (n + 1)-(2*n-m)*(2*n-m+1)/2 + i-2*(m-n); j--;
			}
			flag = 1; continue;
		}
		else {
			int i = n-1;
			for (int j = m-n+1; j <= n-1; j++) {
				a[i][j] = (n) * (n + 1) / 2 + (n) * (n + 1) / 2 - (2*n - m) * (2*n - m + 1) / 2 + j-(m-n) - (m - n); i--;
			}
			flag = 0; continue;
		}
	}

	for (int i = 0; i <= n - 1; i++) {
		for (int j = 0; j <= n - 1; j++) {
			printf("%4d", a[i][j]);
		}printf("\n");
	}
	return 0;
}