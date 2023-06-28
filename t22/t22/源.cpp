#include <iostream>
using namespace std;
int a[101][101];

int main() {
	int m, n; cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
		
 }
	int l = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] != 0) {
				if (a[i - 1][j] == 0)l++;
				if (a[i + 1][j] == 0)l++;
				if (a[i][j + 1] == 0)l++;
				if (a[i][j - 1] == 0)l++;
			}
		}

	}cout << l;
}