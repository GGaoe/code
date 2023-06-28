#include<iostream>
using namespace std;
int main() {
	int a = 1, b = 0, c = 1;
	cout << (!a || !b) << endl;
	cout <<(a&&!a) || (b || !b);

	return 0;
}