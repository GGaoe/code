#include <iostream>
using namespace std;
int n, k;
int a[5050];
int cold[5050];
int hot[5050];
unsigned long long dp[5050][2];
int point[5050];
int last_set[5050];
unsigned long long sumn[5050];

void last() {
	for (int i = 1; i <= n; i++) {
		last_set[i] = point[a[i]];
		point[a[i]] = i;
	}
	return;
}
void sum() {
	int late = 0;
	for (int i = 1; i <= n; i++) {
		if (late == a[i]) sumn[i] = sumn[i - 1] + hot[a[i]];
		else {
			sumn[i] = sumn[i-1]+cold[a[i]];
			late = a[i];
		}
	}
	return;
}

void dp_m() {
	dp[1][0] = cold[a[1]];
	dp[1][1] = cold[a[1]];
	int last_one = a[1];
	for (int i = 2; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + cold[a[i]];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + cold[a[i]];
		if (last_one == a[i]) {
			dp[i][1]= min(dp[i][1],min(dp[i - 1][0], dp[i - 1][1]) + hot[a[i]]);
		}
		else {
			if (last_set[i] != 0) {
				dp[i][0] = min(dp[i][0], dp[last_set[i]+1][0] + sumn[i - 1] - sumn[last_set[i]+1] + hot[a[i]]);
			}
		}
		last_one = a[i];
	}
	return;
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int j = 1; j <= k; j++) {
		cin >> cold[j];
	}
	for (int j = 1; j <= k; j++) {
		cin >> hot[j];
	}
	last();
	sum();
	dp_m();
	cout << min(dp[n][0], dp[n][1]);
	return 0;
}