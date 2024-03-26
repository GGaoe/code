#include <iostream>
using namespace std;
int n, m;
string s;
int in[505];
int out[505];

int main() {
	cin >> n >> m;
	cin >> s;
	string temp;
	int m;
	int now=1;
	bool flag = 0;
	while (s != "END") {
		if (s == "BEGIN") {
			flag = 0;
		}
		else if (s == "LABEL") {
			if (flag != 1)
			{
				in[now + 1] += 1;
				out[now] += 1;
			}
			now++;
			flag = 0;

		}
		else if (s == "GOTO") {
			cin >> m;
			in[m] += 1;
			out[now] += 1;
			flag = 1;
		}
		else if (s == "IF") {
			for (int j = 1; j <= 4; j++) {
				cin >> temp;
			}
			cin >> m;
			in[m] += 1;
			out[now] += 1;
			flag = 0;
		}
		 cin >> s;
	}
	if (flag != 1)
		{
			in[now + 1] += 1;
			out[now] += 1;
		}
	now++;

	for (int i = 1; i <= now; i++) {
		cout << in[i] << " ";
	}cout << endl;

	for (int i = 1; i <= now; i++) {
		cout << out[i] << " ";
	}

	return 0;
}