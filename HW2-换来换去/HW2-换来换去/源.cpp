#include <iostream>
using namespace std;
int x1, x2, x3;
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> x1 >> x2 >> x3;
		if (x1 % 2 == 1 && x2 % 2 == 1 && x3 % 2 == 1) {
			cout << "y" << endl;
			int tmp = x1 / 2;
			for (int i = 1; i <= 2 * tmp; i++) {
				cout << 1 << " ";
			}
			tmp = x2 / 2;
			for (int i = 1; i <= 2*tmp; i++) {
				cout << 2 << " ";
			}
			tmp = x3 / 2;
			for (int i = 1; i <= 2 * tmp; i++) {
				cout << 3 << " ";
			}
			cout << 1 << " " << 2 << " " << 3 << endl;
		}
		else if (x1 % 2 == 0 && x2 % 2 == 0 && x3 % 2 == 0) {
			cout << "y" << endl;
			int tmp = x1 / 2;
			for (int i = 1; i <= 2 * tmp; i++) {
				cout << 1 << " ";
			}
			tmp = x2 / 2;
			for (int i = 1; i <= 2 * tmp; i++) {
				cout << 2 << " ";
			}
			tmp = x3 / 2;
			for (int i = 1; i <= 2 * tmp; i++) {
				cout << 3 << " ";
			}
			cout << endl;
		}
		else cout << "n" << endl;


	}

	return 0;
}