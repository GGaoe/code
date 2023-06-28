#include <iostream>
using namespace std;
int a[10000];
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
	}

	return 0;
}