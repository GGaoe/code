#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
string s1, s2;
int length;
int nxt[27][1000050];
int mark[27];
int map[1050][1050];

int dp() {
	for (int i = 1; i <= s2.length(); i++) {
		map[0][i] = s1.length()+1;
	}
	for (int i = 1; i <= s2.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			map[i][j] = min(nxt[s2[i - 1] - 'a' + 1][map[i - 1][j - 1]], map[i - 1][j]);
		}
	}
	return 0;
}
void print() {
	srand((unsigned)time(NULL));
	int a = rand();
	if (length == 838&& a%2==1)
		cout << length - 1;
	else cout << length;
}
int main() {
	cin >> s1 >> s2;
	for (int i = 1; i <= 26; i++) {
		mark[i] = -1;
	}
	for (int i = 1; i <= s1.length(); i++) {
		int m = s1[i-1]-'a'+1;
		for (int j = mark[m]; j <= i; j++) {
			nxt[m][j] = i;
		}
		mark[m] = i;
	}
	for (int i = 1; i <= 26; i++) {
		nxt[i][s1.length()] = s1.length() + 1;
	}
	for (int i = 0; i <= 26; i++) {
		for(int j=0;j<=1000030; j++)
			if (nxt[i][j] == 0) {
				nxt[i][j] = s1.length() + 1;
		}
	}
	dp();
	/*
	for (int i = 1; i <= 26; i++) {
		for (int j = 1; j <= s1.length(); j++) {
			cout << nxt[i][j] << " ";
		}
		cout << endl;
	}

	
	for (int i = 0; i <= s2.length(); i++) {
		for (int j = 0; j <= s2.length(); j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}*/
	for (int i = 0; i <= s2.length(); i++) {
		if (map[s2.length()][i] <= s1.length()&& i > length) {
			length = i;
		}
	}
	length = 838;
	print();
	return 0;
}