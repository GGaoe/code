#include <iostream>
using namespace std;
int T;
int sourse[1005];
int p[1005];
int s[1005];

int main() {
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= 1004; i++) {
			sourse[i] = 0;
			s[i] = 0;
			p[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			cin >> s[i];
			sourse[i] = s[i];
			p[i] = s[i];
		}
		int k;
		cin >> k;
		int time = 0;
		int round = 0;
		bool flag = 0;
		while (!flag) {
			time++;
			bool lit_flag = 1;
			if (time % 2 == 1)
			{
				for (int i = 1; i <= n; i++) {
					p[i] = s[s[i]];
				}
				for (int i = 1; i <= n; i++) {
					if (p[i] != sourse[i]) {
						lit_flag = 0;
						break;
					}
				}
				if (lit_flag) {
					if (time > k)round = time - k;
					else round = time - k % time;
					flag = 1;
				}
			}
			else {
				for (int i = 1; i <= n; i++) {
					s[i] = p[p[i]];
				}
				for (int i = 1; i <= n; i++) {
					if (s[i] != sourse[i]) {
						lit_flag = 0;
						break;
					}
				}
				if (lit_flag) {
					if (time > k)round = time - k;
					else round = time-k % time;
					flag = 1;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			s[i] = sourse[i];
			p[i] = sourse[i];
		}
		time = 0;
		while (round--) {
			time++;
			if (time % 2 == 1)
			{
				for (int i = 1; i <= n; i++) {
					p[i] = s[s[i]];
				}
				if (!round) {
					for (int i = 1; i <= n; i++) {
						cout << p[i] << " ";
					}
				}
			}
			else {
				for (int i = 1; i <= n; i++) {
					s[i] = p[p[i]];
				}
				if (!round) {
					for (int i = 1; i <= n; i++) {
						cout << s[i] << " ";
					}
				}

			}
		}cout << endl;
	}

	return 0;
}