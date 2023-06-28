#include <iostream> 
using namespace std;
int T;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		int num = 0;
		while (n != 1) {
			if (n % 2 == 1 && m!=0) {
				n -= 1;
				num++;
			}
			else if (m == 0) {
				
				num += n - 1;
				n = 1;
			}
			else {
				n /= 2;
				m--;
				num++;
			}
		}
		cout << num << '\n';
	}


	return 0;
}