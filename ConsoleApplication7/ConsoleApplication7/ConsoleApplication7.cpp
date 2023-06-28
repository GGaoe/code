#include <iostream>
using namespace std;
void add1(int a, int b)
{
	int c;
	c = a + b;
	cout << c << endl;
}
int add2(int a, int b) {
	int c = a + b;
	return c;
}
int main() {
	add1(1, 2);
	int a = add2(4, 5);
	cout << a << endl;
	return 0;
}