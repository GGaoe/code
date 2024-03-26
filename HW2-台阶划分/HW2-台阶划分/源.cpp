#include <iostream>
#include <vector>
#include <set>

using namespace std;
int n;
int a[60][60];
int dw = 0;
bool jiehe = 0;
bool danwei = 0;
bool dy = 0;
bool invers = 0;

void check_dw() {
	for (int i = 1; i <= n; i++) {
		bool tmp = 1;
		for (int j = 1; j <= n; j++) {
			if (a[i][j] != j || a[j][i] != j) {
				tmp = 0;
			}
		}
		if (tmp) {
			dw = i;
			danwei = 1;
			return;
		}
	}
}
void check_jiehe() {
	jiehe = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (a[i][a[j][k]] != a[a[i][j]][k])jiehe = 0;
			}
		}
	}
	return;
}

void check_invers() {
	invers = 1;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == dw)tmp = 1;
		}
		if (!tmp)invers = 0;
	}
	return;
}


int main() {
	cin >> n;
	if (n == 0)
	{
		cout << 5; return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	check_dw();
	check_jiehe();
	check_invers();
	if (jiehe && danwei && invers)cout << 5;
	else if (jiehe && danwei)cout << 4;
	else if (jiehe)cout << 2;
	else cout << 1;

	return 0;
}
