#include <iostream>
using namespace std;
char a[100][100];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n - 1; i++) {
		for (int j = 0; j <= m - 1; j++) {
			cin >> a[i][j];
		}
	}
	int num = 0;
	for (int i = 0; i <= n - 1; i++) {
		for (int j = 0; j <= m - 1; j++) {
			if (a[i][j] == 'N') {
				if (a[i - 1][j] == 'J' && a[i - 2][j] == 'U')num++;
				if (a[i  +1][j] == 'J' && a[i + 2][j] == 'U')num++;
				if (a[i][j-1] == 'J' && a[i][j-2] == 'U')num++;
				if (a[i][j+1] == 'J' && a[i][j+2] == 'U')num++;
			}
		}
	}
	cout << num;
	return 0;
}