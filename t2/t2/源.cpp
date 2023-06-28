#include <iostream>
using namespace std;
int a[100] = { 0 };
int main() {
	int n, k;
	cin >>n >> k;
	for (int i = 0; i <= n - 1; i++) {
		cin >> a[i];
	}int m = 0; int sum = 0;
	for (int i = 0; i <= n - 2; i++) {
		if (a[i] < 2 * a[i + 1]) {
			m++; if (m >= k)sum++;
		}
		else m = 0;
	}cout << sum;
	return 0;
}