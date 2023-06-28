#include <iostream>
using namespace std;
int main() {
	char a[50][50] = { 0 };
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int j = 0; j < m; j++) {
		int lab = n - 1;
		for (int i = n - 1; i >= 0;i--) {
			if (a[i][j] == '#') {
				lab=i-1;
			} if(a[i][j]=='o') {
				char m = a[lab][j];
				a[lab][j] ='o';
				a[i][j] = m;
				lab-=1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j];
		}cout << endl;
	}return 0;
}