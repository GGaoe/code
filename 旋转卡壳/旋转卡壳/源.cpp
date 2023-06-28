#include <iostream>
#include <cmath>
using namespace std;
struct Point {
	long long x;
	long long y;
	Point() {
		x = 0; y = 0;
	}
	Point(long long a, long long b) {
		x = a;
		y = b;
	}
	Point operator - (const Point& p) const{
		return Point(x - p.x, y - p.y);
	}
};
int n;
Point a[100001];
long long Det(Point a, Point b) {
	return a.x * b.y - a.y * b.x;
}
long long dist(Point a, Point b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)* (a.y - b.y);
}
long long maxdist() {
	int j = 1;
	long long dis = 0;
	for (int i = 0; i < n; i++) {
		while (fabs(Det(a[i] - a[(i + 1)%n], a[(i + 1) % n] - a[j])) < fabs(Det(a[i] - a[(i + 1) % n], a[(i + 1) % n] - a[(j + 1) % n]))) {
			j = (j + 1) % n;
	}
		if (dist(a[i], a[j]) > dis)dis = dist(a[i], a[j]);

	}
	return dis;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	cout << maxdist();
	return 0;
}