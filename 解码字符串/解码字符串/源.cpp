#include <iostream>
#include <cmath>
using namespace std;
char num[1001]={};
char letter[1001] = {};
char output[10001] = {};
bool isnum(char a) {
	if (a>='0' && a <= '9')
		return true;
	return false;
}
bool isleft(char a) {
	if (a == '[')return true;
	return false;
}
bool isright(char a) {
	if (a == ']')return true;
	return false;
}
bool isletter(char a) {
	if (a>='a'&&a<='z')return true;
	return false;
}
int i = 0;//数字的数量
int count1 = 0;//字母的数量
int numm = 0;//输出字符的数量
bool flag = 0;//判断字母是否在括号内
int num1 = 0;
int main() {
	int n; cin >> n;
	for (int j = 1; j <= n; j++) {
		char a;
		cin>>a;
		if (isnum(a)) {
			num[i] = a; i++;
		}
		else if (isleft(a)) {
			flag = 1;
			for (int o = 0; o < i; o++) {
				num1 += (num[o]-'0') * pow(10, i - 1 - o);
				num[o] = 0;
			}i = 0;
			
		}
		else if (flag && isletter(a)) {
			letter[count1] = a; count1++;
		}
		else if (!flag && isletter(a)) {
			output[numm] = a; numm++;
		}
		else if (isright(a)) {
			for (int l = 0; l<num1; l++) {
				for (int k = 0; k < count1; k++) {
					output[numm] = letter[k]; numm++;
				}
			}
			num1 = 0;
			for (int k = 0; k < count1; k++) {
				letter[k] = {};
			}count1 = 0;
			flag = 0;
		}
		
	}for (int y = 0; y < numm; y++) {
		cout << output[y];
	}
	return 0;

}