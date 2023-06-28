#include <iostream>
#include <cmath>
using namespace std;
long long  min(long  a, long b) {
	long long c = a; if (b < a) { c = b; }
	return c;
}
long long  f(long long  x) {
	long long a = min((x +x / 10+ 123456), 2 * 1000000000 - x);
	return a;
}

long long g(long long  x) {
	int a[16]; int i = 0;
	while (x != 0) {
		a[i] = x % 10; i++; x /= 10;
	}i--; int ans = 0; int m = 0;
	for (int t=0; t <= i; t++) {
		if (a[t] % 2 == 0) {
			ans += a[t] * pow(10, m); m++;
		}
	}return ans;
}
long long h(long long  x) {
	int a[16]; int i = 0;
	while (x != 0) {
		a[i] = x % 10; i++; x /= 10;
	}i--; int ans = 0; int m = 0;
	for (int t=0; t <= i; t++) {
		if (a[t] % 2 != 0) {
			ans += a[t] * pow(10, m); m++;
		}
	}return ans;
}
long long p(long long  x) {
	return h(f(g(x)));
}
long long q(long long  x) {
	return g(f(h(x)));
}
int main() {
	long long x; int m; 
	cin >> x >> m; long long  n = x;
	for (int i = 1; i <= m; i++) {
		char k; cin >> k;
		switch (k) {
		case'f':n = f(n); break;
		case'g':n = g(n); break;
		case'h':n = h(n); break;
		case'p':n = p(n); break;
		case'q':n = q(n);
		}cout << n<<endl;
	}
	return 0;
}