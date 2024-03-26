#include <iostream>
#include <algorithm>
#define mod 998244353
using namespace std;
int T;
long long value[100005];
long long n, k;
long long tmp_re;

int main() {
	cin >> T;
	while (T--) {
		tmp_re = 0;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> value[i];
		}
		sort(value + 1, value + n + 1, greater<long long>());
		for (int i = 1; i <= n; i++) {
			cout << value[i] << endl;
		}
			for (int i = 1; i < 10; i++) {
				for (int j = 0; j < 1; j++) {
					tmp_re += value[i + j * 10] * value[i + 1 + j * 10];
					tmp_re %= mod;
				}
			}
			for (int j = 0; j < 1; j++) {
				tmp_re += value[10 + j * 10] * value[1 + j * 10];
				tmp_re %= mod;
			}
			cout << tmp_re;
		}

	return 0;
}