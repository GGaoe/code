#include <iostream>
using namespace std;
int total = 0;
int a2 = 0;
int a3 = 0;
void summ(int num,int state,int numm) {
	{
		if (total > 102)return;
		if (num == 12 && total == 102) {
			//cout << a2 << " " << a3 << endl;
			cout << a2 + a3 + 11 << endl;
			return;
		}
		else if (num == 12) {
			return;
		}
	}
	if (state == 0){
		if (total > 102)return;
		total += 1; summ(num + 1, 0,0);
		total -= 1;
		a2 += 8; summ(num, 1, 0);
		a2 -= 8; total -= 8;
	}
	else if (state == 1) {
		if (total > 102)return;
		else if (numm == 8)return summ(num + 1, 0, 0);
		else {
			total += 1; summ(num, 1, numm + 1);
			total -= 1;
			total += 8; a3 += 8; summ(num, 1, numm + 1);
			total -= 7; a3 -= 8;
		}
	}
}

int main() {
	summ(1, 0, 0);
	return 0;
}