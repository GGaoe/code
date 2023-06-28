#include <iostream>
#include <stack>
using namespace std;
string s;//串
stack<int>k;//存放括号，0为左括号，1为右括号
bool flag = 1;//表示串是否合法
bool bf_checker()
{for(int i=1;i<=s.length(); i++)
	switch (s[i-1]) {
	case ',': {
		continue;
	}
	case '.': {
		continue;
	}
	case'<': {
		continue;
	}
	case'>': {
		continue;
	}
	case'+':{
		continue;

	}
	case'-': {
		continue;

	}
	case'[': {
		k.push(1);
		break;
	}
	case']': {
		if (k.empty()) {
			flag = 0; return 0;;
		}
		int cor = k.top();
		k.pop();
		if (cor != 1) {
			flag = 0;
		}
		break;

	}
	default: {
		flag = 0;
		break;
	}
		   if (!flag)break;
	}
	bool isEmpty = k.empty();
	if (isEmpty) {
	}
	else {
		flag = 0;
	}
	return flag;
}
int main()
{
	cin >> s;
	if (bf_checker())
		puts("Yes");
	else
		puts("No");
	return 0;
}