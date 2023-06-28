#include<iostream>
using namespace std;
int step=0;
char a[2][10000000];
void hannoi(int n, char A, char B, char C) {
	if (n == 1) {
		a[0][step] = A;
		a[1][step] = C;
		step++;
		
	}
	else {
		hannoi(n - 1, A, C, B);
		
		a[0][step] = A;
		a[1][step] = C;
		step++;
		hannoi(n - 1, B, A, C);
	}
}
int main()
{
	int n;
	cin >> n;
	hannoi(n, '1', '2', '3');
	cout << step << endl;
	for (int i = 0; i < step; i++) {
		cout << "Move From " <<a[0][i] << " To " << a[1][i] << endl;
	}
	return 0;
}
