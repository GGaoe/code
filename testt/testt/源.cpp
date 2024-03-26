#include<iostream>
#include<cmath>
using namespace std;
int aa = 0;
void f(char str[], int i, int& temp)
{
	if ('a' <= str[i] && str[i] <= 'a' + 25)
	{
		cout << str[i];
		i++;
		temp = i;
		f(str, i, temp);
	}
	if (str[i] == ']')
	{
		return; //跳出循环
	}
	if (0 + '0' <= str[i] && str[i] <= '9' + 1)
	{
		i++;
		temp = i;
		int p = 0;
		while (0 + '0' <= str[i] && str[i] <= 9 + '0')
		{
			p++;
			i++;
			temp = i;
		}
		int num = 0;
		while (p >= 0)
		{
			num += (str[i - p - 1] - '0') * pow(10, p);
			p--;
		}
		//cout <<endl<< num << endl;

		for (int j = 1; j <= num; j++)
		{
			cout << endl << aa++ << endl;
			f(str, i + 1, temp);
		}
		i = temp + 1;
		f(str, i, temp);//遇见']'之后
	}
}
int main()
{
	char str[100];
	cin >> str;
	int temp = 0;
	f(str, 0, temp);
}
