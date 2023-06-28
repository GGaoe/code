#include <iostream>
using namespace std;
int main() {
	int x;
	cin >> x;
	if (x <= 150)
		cout <<int(10* 0.4463 * x+0.5)/10.0 << endl;
	else if (x <= 400)
		cout << int(10*(0.4463 * 150 + (x - 150) * 0.4663+0.5))/10.0 << endl;
	else
		cout << int(10*(0.4463 * 150 + 0.4663 * 250 + (x - 400) * 0.5663+0.5))/10.0<<endl;
	return 0;
}