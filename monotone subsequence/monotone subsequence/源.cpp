#include <iostream>
using namespace std;
int a[10], b[10];
int dec1[10]={1}, inc1[10]={1}, dec2[10]={1}, inc2[10]={1};
int find(int e[], int m) {
	int max = 1; int t=1;
	for (int i = m-1; i >= 0; i--) {
		if (a[i] < a[m] && max < a[i]) {
			max = e[i];
			t = i;
		}
	}return t;//找到o前最大减序列
}
int find2(int e[], int m) {
	int max = 1; int t;
	for (int i = m-1; i >= 0; i--) {
		if (a[i] > a[m] && max < a[i]) {
			max = e[i];
			t = i;
		}
	}return t;//找到o前最大增序列
}
int find3(int e[], int m) {
	int max = 1; int t;
	for (int i = m-1; i >0; i--) {
		if (a[i] < a[m] && max < a[i]) {
			max = e[i];
			t = i;
		}
	}return t;//找到o后最大减序列
}
int find4(int e[], int m) {
	int max = 1; int t;
	for (int i = m-1; i >= 0; i--) {
		if (a[i] > a[m] && max < a[i]) {
			max = e[i];
			t = i;
		}
	}return t;//找到o后最大增序列
}
int main() {
	int n; cin >> n;
	int m =( n+1) / 2;
		for (int o = 0; o <= m - 1; o++) {
			int t; cin >> t;
			a[o] = t;//输入中间项之前的序列
		}
		for (int p = 0; p <= n - m-1; p++) {
			int t; cin >> t;
			b[p] = t;//输入中间项之后的序列
		}
	for (int o = 1; o < m; o++) {
		int t = find(inc1,o);
				inc1[o] = inc1[t]+1;
	    int n= find2(dec1, o);
		dec1[o] = dec1[t]++;
		}
	int q = find(inc1, m);
	int r = find2(dec1, m);
	inc1[m] = inc1[find(inc1, m)]++;
	dec1[m] = dec1[find(dec1, m)]++; 
	return 0;
}