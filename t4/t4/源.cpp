#include <iostream>
using namespace std;
int main() {
	int x1, y, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	int a = x1 + 10000; int b = y + 10000; int c = x2 + 10000; int d = y2 + 10000;
	int e = x3 + 10000; int f = y3 + 10000; int g = x4 + 10000; int h = y4 + 10000;
	int m[20001][20001] = { 0 };
	for (int i = x1; i <= x2; i++) {
		for (int w = y; w <= y2; w++) {
			m[i][w]++;
		}
	}
	for (int i = x3; i <= x4; i++) {
		for (int w = y3; w <= y4; w++) {
			m[i][w]++;
		}
	}for (int i = 0; i <=20001; i++) {
		for (int w = 0; w <= 20001; w++) {
			if (m[i][w] == 1)m[i][w] = 0;
		}
	}
	int sum = 0;
	for (int i = 0; i <= 20001; i++) {
		for (int w = 0; w <= 20001; w++) {
			sum += m[i][w];
		}
	}cout << sum / 2;
	return 0;
}
