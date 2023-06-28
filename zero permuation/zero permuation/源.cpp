#include <iostream>
using namespace std;
int a[10001];
int dp[10001];
int n;
void con(int n, int a[10001]) {
	int num_1 = 0;
	int num_ = 0;
	int m;
	int q = 0;
	m = a[q];
	if (m == 0)dp[0] = 1;
	else if (m == 1)num_1++;
	else num_++;
	q++;
	m = a[q];
	for (int i = 1; i < n; i++) {
		if (m == 0) {
			dp[i] = 2 * dp[i - 1]+1;
		}
		else if (m == 1) {
			dp[i] = dp[i - 1] + num_;
			num_1++;
		}
		else {
			dp[i] = dp[i - 1] + num_1;
			num_++;
		}
		q++;
		m = a[q];
	}
	cout << dp[n-1] << endl;
	return;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	con(n, a);

}