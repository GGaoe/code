#include <iostream>
using namespace std;
int n,pd[100], used[100];
void frint() {
	for (int i = 1; i <= n; i++) {
		printf("%5d", used[i]);
		
	}cout << endl;
	return;
}
void dfs(int k) {
	if (k == n) {
		frint(); return;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (!pd[i]) {
				pd[i] = 1;
				used[k+1] = i;
				dfs(k + 1);
				pd[i] = 0;
			}
		}
	}return;
}
int main() {
	scanf_s("%d", &n);
	dfs(0);
	return 0;
}