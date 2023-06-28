#include <iostream>
using namespace std;
#define ull long long
#define mod 998244353
int n;
int map[4105][4105];
int c[8005][8005];
int lin[200105];
int col[200105];
void dp() {
	for (int i = 1; i <= 4001; i++) {
		for (int j = 1; j <= 4001; j++) {
			map[i][j] += map[i - 1][j] + map[i][j - 1];
			map[i][j] %= mod;
		}
	}
	for (int i = 0; i <= 8011; i++) {
		c[i][0] = 1, c[i][i] = 1;
		for (int j = 1; j <= 8011; j++) {
			if (j < i) {
				c[i][j] += c[i - 1][j] + c[i - 1][j - 1];
				c[i][j] %= mod;
			}
		}
	}
	return;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		lin[i] = a;
		col[i] = b;
		map[2001 - a][2001 - b] += 1;
	}
	dp();
	/*
	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= i; j++) {
			cout << c[i][j] << " ";
		}cout << endl;
	}
	*/
	ull final_result = 0;
	for (int i = 1; i <= n; i++) {
		final_result += map[lin[i] + 2001][col[i] + 2001];
		final_result %=mod;
		final_result -= c[2*(lin[i]+col[i])][2*lin[i]];
		if (final_result < 0)final_result += mod;
	}
	final_result *= 499122177;
	final_result %= mod;
	cout << final_result << endl;
	return 0;
}