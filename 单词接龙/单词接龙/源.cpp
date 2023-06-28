#include <iostream>
#include <string>
using namespace std;
int n;
string s[100005];
int dp[28][100005];

int find_max(int col) {
	int max=0;
	for (int m = 1; m <= 26; m++) {
		if (dp[m][col] > max) {
			max = dp[m][col];
		}
	}
	return max;
}

int main() {
	cin >> n;
	for (int i = 0; i <= 26; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 26; j++) {
			dp[j][i] = dp[j][i - 1];
		}
		dp[s[i][s[i].length() - 1] - 'a' + 1][i] =max( dp[s[i][0] - 'a' + 1][i - 1] + 1, dp[s[i][s[i].length() - 1] - 'a' + 1][i]);
	}
	//test
	/*for (int i = 1; i <= 26; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dp[i][j] << " ";
		}cout << endl;
	}*/
	cout << n-find_max(n) << endl;
	return 0;
}