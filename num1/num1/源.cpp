#include <iostream>
#include <stack>
using namespace std;
int m, n;
int flr[55][55];
int used[55][55];
stack <int>len;
stack<int>val;
bool flag = 0;
int num = 0;
void check(int a,int b) {
	if (flr[a][b] == 1)flag = 1;
	used[a][b] = 1;
	len.push(a); 
	val.push(b); 
	num++;
	if (a - 1 >= 1 && flr[a - 1][b] != 2 && used[a - 1][b] == 0) {
		check(a - 1, b);
	}
	if (a + 1<= n && flr[a + 1][b] != 2 && used[a + 1][b] == 0) {
		check(a + 1, b);
	}
	if (b + 1 <= m && flr[a][b+1] != 2 && used[a][b+1] == 0) {
		check(a, b+1);
	}
	if (b - 1>=1 && flr[a][b-1] != 2 && used[a][b-1] == 0) {
		check(a, b-1);
	}
}
void change() {
	if (flag) {
		for(int i=0;i<num;i++){
			int q = len.top();
			len.pop();
			int w = val.top();
			val.pop();
			flr[q][w] = 1;
		}
	}
	else {
		for (int i = 0; i < num; i++) {
			len.pop();
			val.pop();
		}
	}
}

int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> flr[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if(flr[i][j]!=2&&used[i][j]!=1){
				check(i, j);
				change();
				flag = 0;
				num = 0;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cout << flr[i][j];
			if(j!=n) cout<< " ";
		}
		cout << endl;
	}

	return 0;
}