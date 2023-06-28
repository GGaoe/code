#include <iostream>
using namespace std;
long long a[100000], b[100000];
long long x = 0, y = 0;
long long distance(long long u, long long a, long long b) {
	if ((x <= a && y < b) || (x < a && y <= b)) {
		x = a, y = b;
		return a * a + b * b;
	}
	else if (x >= a && y >= a)return u;
	else {
		long long d = a * a + b * b;
		if (u >= d)return u;
		else {
			x = a, y = b; return d;
		}
	}
}
int main() {
	int n; cin >> n;
	long long maxdis = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			maxdis = distance(maxdis, a[i]-a[j], b[i]- b[j]);
		}
	}
	cout << maxdis << endl;
}