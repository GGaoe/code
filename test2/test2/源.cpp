#include <iostream>
#include <stack>
using namespace std;
string s;//��
stack<int>k;//������ţ�0Ϊ�����ţ�1Ϊ������
bool flag = 1;//��ʾ���Ƿ�Ϸ�
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