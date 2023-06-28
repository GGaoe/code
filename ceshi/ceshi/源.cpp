#include <iostream>
#include <string.h>
#include <queue>
#include <cmath>
using namespace std;
int main() {
	/*char str[] = "helloNJU";
	int len = strlen(str);
	//cout << str[7] << endl;
	//cout << str[len - 1] << endl;
	for (int i = len - 1; i >= 0; i--) {
		cout << str[i] << " ";
	}cout << endl;
	for (int i = 0, j = len - 1; i < len / 2; i++,j--) {
		char temp = str[j];
		str[j] = str[i];
		str[i] = temp;
	}
	for (int i = 0; i < len; i++) {
		cout << str[i] << " ";
	}
	cout << endl;
	char st[] = "1234567";
	char* s;
	s = &st[0];
	cout <<endl<<endl<<endl<< &s<<endl;
	int num = 0;
	int length = strlen(st);
	for (int i = 0; i < length; i++) {
		num += (st[i] - '0')*pow(10, length - i - 1);
		cout << num<<endl;
	}
	cout << endl << num;

	//cout << endl << sizeof('A') << sizeof("A") << endl;


	cout << endl << endl;



	const char* stt = "Hello";
	for (int i = 1; i <= 999; i++) {
		cout << i * i << endl;
}*/
/*char str[] = "Hello";
//cout << strlen(str);
char* pstr = str;
//cout << *pstr;
char strr[10];
char a;

//a = getchar();
//gets_s(strr);
//cout << strr;
char ss[4][5] = { "zhao","qian","sun","li" };
char* ssp[4] = { };
//cout << *ss[0];
//cout << strlen(ss[1]);
char* week[7];
week[0] = (char*)"sunday";
//cout << string(week[0] + 1);

char* p[2] = { (char*)"sss",(char*)"weqewqe" };
cout << string(p[1] + 1);
char* temp, * name[] = { (char*)"zhaop",(char*)"qoianm",(char*)"asun" };
int n = 4, i, min;
for (i = 0; i < n - 1; i++) {
	if (strcmp(name[min], name[i]) > 0)min = i;

}
}
	char* Bin(char* sp[], char* str, int n, int* addr) {
		int left, right, mid;
		left = 0;

	}*/

	struct Ticket
	{
		char name[20];
		double price;
		int count;
		Ticket* next;
	};
	Ticket* createlist(int n);













}