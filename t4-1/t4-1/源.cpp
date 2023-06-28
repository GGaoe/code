#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int n; cin >> n;
	for (int i=1; i <= n; i++) {
		double x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (y1 * y2 > 0)cout << "null"<<endl;
		else if (y1 == 0 && y2 == 0 && x1 != x2)cout << "null"<<endl;
		else if (y1 == 0 && y1 == y2)cout << fixed << setprecision(6) << x1<<endl;
		else {
			double x0; x0 = x1 - y1 / ((y2 - y1) / (x2 - x1)); cout << fixed << setprecision(6)<< x0<<endl;
		}
	}return 0;
}