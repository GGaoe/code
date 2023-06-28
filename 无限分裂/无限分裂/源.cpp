#include <iostream>
using namespace std;
int fl(int x) {
	if (x - 4 < 0)return 1;
	else return fl(x - 3)+fl(x-1);
}
int main() {
	int x, y;
	cin >> x>>y;
	if (fl(x)>y)cout << 0;
	else cout << 1;
	return 0;
}