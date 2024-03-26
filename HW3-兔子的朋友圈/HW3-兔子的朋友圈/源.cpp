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
		int group = 0;
		int num = 0;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> value[i];
		}
		sort(value + 1, value + n + 1, greater<long long>());
		
		if (k % n == 0) {
			for (int i = 1; i <= n; i++) {
				tmp_re += value[i] * value[i];
				tmp_re %= mod;
			}
		}
		else {
			k %= n;
			for (int i = 1; i <= n; i++) {
				if ((i * n) % k == 0) {
					group = k / i;
					break;
				}
			}
			num = n / group;


			for (int i = 1; i < num-1; i++) {
				for (int j = 0; j < group; j++) {
					tmp_re += value[i + j * num] * value[i + 2 + j * num];
					tmp_re %= mod;
				}
			}
			for (int j = 0; j < group; j++) {
				tmp_re += value[2 + j * num] * value[1 + j * num];
				tmp_re %= mod;
			}
			for (int j = 0; j < group; j++) {
				tmp_re += value[num + j * num] * value[num-1 + j * num];
				tmp_re %= mod;
			}
		}
		//cout << num << endl;
		cout << tmp_re << endl;
		for (int i = 1; i <= 100000; i++) {
			value[i] = 0;
		}
	}

	return 0;
}