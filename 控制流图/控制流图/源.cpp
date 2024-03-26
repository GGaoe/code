#include <iostream>
using namespace std;
int n, m;

struct person {
	int lable;
}stu[1005];

int a[1005];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		stu[i].lable = 0;
	}

	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		if (a[u] == 0 && a[v] == 0) {
			stu[u].lable = 1, stu[v].lable = 2;
			a[u] = 1, a[v] = 1;
		}
		else if (a[u] == 1 && stu[u].lable == 1) {
			stu[v].lable = 2;
			a[v] = 1;
		}
		else if (a[v] == 1&&stu[u].lable!=2) {
			a[u] = 1, stu[u].lable = 1;
		}
		else {
			a[u] = 1, a[v] = 1;
			stu[u].lable = 2, stu[v].lable = 2;
		}

	}
	int flag = 0;
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (stu[i].lable == 1) {
			flag += 1, max = i;
		}

	}
	if (flag == 1) {
		cout << max << endl;
	}
	else cout << -1;

	return 0;
}