#include <iostream>
#include <string.h>
using namespace std;
int tree[200000][30];
int coun1t[200000];
int id = 0;

void insert_str(string s) {
	if (s.length() == 0)return;
	int p = 0;
	for (int i = 0; i < s.length(); i++) {
		int x = s[i] - 'a';
		if (tree[p][x] == 0)tree[p][x] =++id;
		p = tree[p][x];
	}
	coun1t[p] = 1;
	return;
}

int find(string s) {
	if (s.length() == 0)return 0;
	int p = 0;
	for (int i = 0; i < s.length(); i++) {
		int x = s[i] - 'a';
		if (tree[p][x]==0)return 0;
		p = tree[p][x];
	}
	//int x = s[s.length() - 1] - 'a';
	//cout << coun1t[p] << endl;
	return coun1t[p];
}


int main() {
	int numcount = 0;
	int n, m;
	cin >> n >> m;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		insert_str(s);
	}
	for (int i = 1; i <= m; i++) {
		cin >> s;
		numcount+=find(s);
	}
	cout << numcount;
	return 0;
}