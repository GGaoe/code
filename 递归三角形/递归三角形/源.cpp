#include <iostream>
#include <cmath>
using namespace std;
int a[65][65];
int c = 1;
int f(int right, int floor, int n) {
	if (n == 1) {
		a[floor][right] = 1; return 0;
	}
	else {
		f(right, floor, n - 1);
		f(right - pow(2, n-2), floor - pow(2, n-2), n - 1);
		f(right - pow(2, n-2), floor , n - 1);
	}
}
	
int main() {
	int n; cin >> n; 
	int m = pow(2, n-1);
	f(m,m,n);
	for (int i = pow(2, n - 1);i>=1; i--) {
		for (int j = 1; j <= pow(2, n - 1); j++) {
			if (a[i][j] == 1)cout << "*" << " ";
			else cout << "  ";
		}cout << endl;
	}
	return 0;
}