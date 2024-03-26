#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
int n, m;
int max_state;
int state1[10005];
int cnt=1;
int map1[105];
int dp[105][505][505];
int sum1[505];

int count_digit(int x) {
	//cout << x;
	int sum = 0;
	while (x != 0) {
		int a = x % 2;
		if (a)sum++;
		x >>= 1;
	}
	//cout << sum << endl;
	return sum;
}

void gene() {
	//cout << max_state << endl;
	for (int i = 0; i <= max_state; i++) {
		if ((i & (i << 1)) || (i & (i << 2))) {
			//cout << i << endl;
			continue;
		}
		else {
			state1[cnt] = i;
			//cout << 1 << endl;
			sum1[cnt] = count_digit(i);
			cnt++;
		}
	}
	return;
}

int main() {
	cin >> n >> m;
	max_state = (1 << (m)) - 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char r;
			cin >> r;
			if (r == 'P') {
				map1[i] |= 1 << (m-j);
			}
		}
	}

	gene();
	//cout << cnt << endl;

	memset(dp, -1, sizeof(dp));
	dp[0][1][1] = 0;
	//dp
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < cnt; j++) {
			if ((state1[j] & map1[i]) == state1[j]) {
				for (int k = 1; k < cnt; k++) {
					if (((state1[k] & map1[i - 1]) == state1[k]) && ((state1[k] & state1[j]) == 0)) {
						for (int p = 1; p < cnt; p++) {
							//cout << dp[i-1][k][p]<<endl;
							if (((state1[p]&state1[j])==0)&&(dp[i-1][k][p]!=-1)) 
							{
								//cout << 1;
								dp[i][j][k] = max(dp[i][j][k], dp[i-1][k][p] + sum1[j]);
							}
						}
					}
				}
			}
		}
	}

	


	int max1 = 0;
	for (int i = 1; i < cnt; i++) {
		for (int j = 1; j < cnt; j++) {
			//cout << dp[1][i][j] << " ";
			max1 = max(max1, dp[n][i][j]);
		}
		//cout << endl;
	}
	cout << max1 << endl;

	return 0;
}