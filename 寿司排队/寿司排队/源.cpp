#include<iostream>
using namespace std;
int T;
double dp_1[205][205][205];

void dp(int n) {
	dp_1[1][0][0] = n;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j + i <= n; j++) {
			for (int k = 0; i + j + k <= n; k++) {
				if (i != 0)
					dp_1[i][j][k] += i * dp_1[i - 1][j][k];
				if (j != 0)
					dp_1[i][j][k] += j * dp_1[i][j-1][k];
				if (k != 0)
					dp_1[i][j][k] += k * dp_1[i][j][k-1];
				dp_1[i][j][k] += n;
				if(i+j+k!=0)
					dp_1[i][j][k] /= (i + j + k);

			}
		}
	}
	
	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int num_a=0, num_b=0, num_c=0, num_d=0;
		int a[210];
		for (int i = 1; i <= n; i++) {
			cin>>a[i];
			if (a[i] == 1)num_b++;
			else if (a[i] == 2)num_c++;
			else num_d++;
		}
		dp(n);
		cout << dp_1[num_b][num_c][num_d] << '\n';
	}


	return 0;
}