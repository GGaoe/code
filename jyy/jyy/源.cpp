#include <iostream>
using namespace std;
int main() {
	int N; cin >> N;
	int sum = 0;
	int num_j = 0;
	int num_jy = 0;
	int count_j = 0;
	for (int i = 1; i <= N; i++) {
		char m; cin >> m;
		if (m == 'j') { num_j++;  }
		else if (m == 'y') {
			
			sum += num_jy;
			num_jy += num_j+count_j;
			count_j += num_j;
			num_j = 0;
			sum %= 998244353;
		}
	}cout << sum;
		return 0;
	}