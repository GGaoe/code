#include <iostream>
#include <string.h>
using namespace std;
char a[128];
int main() {
	char* b = a;
	for (int i = 0; i < 9; i++) {
		char m;
		cin >> m;
		*(b + i) = m;
	}
	cout << strlen(a);
}																																																	