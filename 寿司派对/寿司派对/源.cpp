#include<iostream>
using namespace std;
int T;
long long mod = 998244353;
long long  dp_1[30][2];

long long binpow(long long a, long long b) {
	if (b == 0) return 1;
	long long res = binpow(a, b/2)%mod;
	if (b % 2)
		return res * res * a %mod;
	else
		return res * res % mod;
}

void shortt() {
	for (int i = 1; i <= 22; i++) {
		dp_1[i][0] *= i;
	}
	for (int i = 1; i <= 25; i++) {
		for (int k = 1; k <= 25; k++) {
			for (int j = 2; j <= i; j++) {
				if (dp_1[i][0] % j == 0 && dp_1[i][1] % j == 0&& dp_1[i][0] > j&& dp_1[i][1]> j) {
					dp_1[i][0] /= j;
					dp_1[i][1] /= j;
					
				}
			}
		}
	}
	return;
}

void dp() {
	dp_1[0][0] = 0;
	dp_1[0][1] = 1;
	dp_1[1][0] = 1;
	dp_1[1][1] = 1;
	for (int i = 2; i <= 26; i++) {
		dp_1[i][0] = dp_1[i - 1][0] * i+dp_1[i-1][1];
		dp_1[i][0] %= mod;
		
		dp_1[i][1] = dp_1[i - 1][1] * i;
		dp_1[i][1] %= mod;
	}
	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	dp();
	shortt();
	while (T--) {
		int n;
		cin >> n;
		int num_a = 0, num_b = 0, num_c = 0, num_d = 0;
		int a[210];
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] == 1)num_b++;
			else if (a[i] == 2)num_c++;
			else num_d++;
		}
		long long final_result = 0;
		long long  fz = dp_1[num_b][0];
		long long  fm = dp_1[num_b][1];
		if (fz % fm == 0) {
			final_result = fz /fm % mod;
		}
		else {
			fm = binpow(fm, mod - 2)%mod;
			
			final_result =(fm * fz) % mod;
		}
		cout << final_result << '\n';
	}

	return 0;
}