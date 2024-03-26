#include <iostream>
#include <string>
using namespace std;
int n, m;
string s;
string sen[2005];//清洗输入中有用的字符串
int lable[505];//记录上述数组中标签的位置
int in[505];
int out[505];

int main() {
	cin >> n >> m;
	int i=1;
	int count=1;
	cin >> s;
	string temp;
	while (s != "END") {
		if (s == "BEGIN") {
			sen[i] = s;
			lable[count] = i;
			i++, count++;
			cin >> temp;
		}
		else if (s == "LABEL") {
			sen[i] = s;
			lable[count] = i;
			i++, count++;
			cin >> temp;
		}
		else if (s == "GOTO") {
			sen[i] = s;
		}
		else if (s == "IF") {
			sen[i] = s;
			i++;
			
		}
		else cin >> s;
	}

	return 0;
}