#include <iostream>
#include <regex>
#include <string>
using namespace std;
bool isdigit(char ch) {
    return '0' <= ch && ch <= '9';
}

bool isletter(char ch) {
    return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
}

bool get_next_state(char ch, int& state) {
    switch (state) {
    case 1: {
        if (isletter(ch)) {
            state = 2;
            return true;
        }
        else if (isdigit(ch)) {
            state = 15;
            return true;
        }
        else return false;
        break;
    }
    case 2: {
        if (isletter(ch)) {
            state = 2;
            return true;
        }
        else if (isdigit(ch)) {
            state = 15;
            return true;
        }
        else if (ch == ':') {
            state = 3;
            return true;
        }
        else if (ch == '.') {
            state = 5;
            return true;
        }
        else if (ch == '/') {
            state = 9; return true;
        }
        else if (ch == '?') {
            state = 11; return true;
        }
        else if (ch == '#') {
            state = 13; return true;
        }
        else { return false; }
    }
    }
}
int main() {
	string rule;
	cin >> rule;
	string text; cin >> text;
	reverse(rule.begin(), rule.end());
	reverse(text.begin(), text.end());
	string a, b;
	a=rule;
	b = text;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (regex_match(b, regex(a))) {
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
	return 0;
}