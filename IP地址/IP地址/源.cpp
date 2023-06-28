#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
string t = {};
int len;
string chu(int a) {
	int b[10];
	int i = 0;
	while (a != 0) {
		b[i] = a % 2;
		a /= 2;
		i += 1;
	}
	len = i;
	i--;

	for (int o = i; o >= 0; o--) {
		stringstream ss;
		ss << b[o];
		string s;
		ss >> s;
		t += s;
	}
	return t;
}
int main() {
	string q;
	int a;
	cin >> a;
	chu(a);
	int m = 8 - len;
	for (int i = 1; i <= m; i++) {
		q += '0';
	}
	q += t;
	len = 0;
	t = {};
	getchar();
	cin >> a;
	chu(a);
	m = 8 - len;
	for (int i = 1; i <= m; i++) {
		q += '0';
	}
	q += t;
	len = 0;
	t = {};
	getchar();
	cin >> a;
	chu(a);
	m = 8 - len;
	for (int i = 1; i <= m; i++) {
		q += '0';
	}
	q += t;
	len = 0;
	t = {};
	getchar();
	cin >> a;
	chu(a);
	m = 8 - len;
	for (int i = 1; i <= m; i++) {
		q += '0';
	}
	q += t;
	cout << q;

}