#include <iostream>
#include <string>
using namespace std;
string s;
int is_stage(int head,int tail) {
	if (head == tail) {
		//cout << s[head] << endl;
		//cout << int(s[head])-'a'+1 << endl;
		return(int(s[head]) - 'a' + 1);
	}
	else if (head == tail - 1) {
		if (int(s[head]) < 'a' || int(s[head]) > 'z')return -1;
		if (int(s[tail]) < 'a' || int(s[tail]) > 'z')return -1;
		if (int(s[head]) - int(s[tail]) == 1 || int(s[head]) -int( s[tail]) == -1)
			return(min(int(s[head]),int( s[tail])) - 'a' + 1);
		else return -1;
	}
	else {
		bool flag1 = 1;
		bool flag2 = 1;
		for (int i = head; i <= tail; i++) {
			if (int(s[i]) < 'a' || int(s[i]) > 'z')return -1;
		}
		for (int i = head; i <=head+(tail-head-1)/2; i++) {
			if (s[i] != s[head])flag1 = 0;
		}
		for (int i = tail; i > head + (tail - head-1) / 2; i--) {
			if (s[i] != s[tail])flag2 = 0;
		}
		if (flag1 && !flag2) {
			if ((int(s[head]) - 'a' + 1) - is_stage(head + (tail - head + 1) / 2, tail) == 1 ||
				(int(s[head]) - 'a' + 1) - is_stage(head + (tail - head + 1) / 2, tail) == -1)
				return (int)(int(s[head]) - 'a' + 1);
			else return -1;
		}
		else if (!flag1 && flag2) {
			if ((int(s[tail]) - 'a' + 1) - is_stage(head, head + (tail - head - 1) / 2) == 1 ||
				(int(s[tail]) - 'a' + 1) - is_stage(head, head + (tail - head - 1) / 2) == -1)
				return (int)(int(s[tail]) - 'a' + 1);
			else return -1;
		}
		else return -1;
	}
}
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		if (is_stage(0, s.length()-1) != -1)
			cout << char('a' + is_stage(0,s.length()-1) - 1) << endl;
		else cout <<0<<endl;
	}return 0;
}