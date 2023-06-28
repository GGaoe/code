#include <iostream>
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
    
    case 3: {
        if (ch == '/')state = 4;
        else if (isdigit(ch))state = 8;
        else return false;
        return true;
    }
    case 4: {
        if (ch == '/')state = 5;
        else return false;
        return true;
    }
    case 5: {
        if (isdigit(ch) || isletter(ch)) {
            state = 15; return true;
        }

        else return false;
    }
    case 15: {if (isdigit(ch) || isletter(ch)) {
        state = 15; return true;
    }
            else if (ch == '.') {
        state = 6; return true;
    }
            else if (ch == ':') {
        state = 7; return true;
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
            else return false;
    }

    case 6: { if (isdigit(ch) || isletter(ch)) {
        state = 15; return true;
    }
           else return false; }
    case 7: {if (isdigit(ch)) {
        state = 8; return true;
    }
           else return false; }
    case 8: {
        if (isdigit(ch)) {
            state = 8; return true;
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
        else return false; }
    case 9: {
        if (isdigit(ch) || isletter(ch)) {
            state = 9; return true;
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
        else return false; }
   
    case 11: {
        if (isdigit(ch) || isletter(ch)) {
            state = 12; return true;
        }
        else return false;
    }
    case 12: {
        if (isdigit(ch) || isletter(ch)) {
            state = 12; return true;
        }
        else if (ch == '=') {
            state = 10; return true;
        }
        else if (ch == '&') {
            state = 11; return true;
        }
        else if (ch == '#') {
            state = 13; return true;
        }
        else return false;
    }
    case 10: {
        if (isdigit(ch) || isletter(ch)) {
            state = 16; return true;
        }
        else return false;
    }
    case 16: {
        if (isdigit(ch) || isletter(ch)) {
            state = 16; return true;
        }
        else if (ch == '&') { state = 11; return true; }
        else if (ch == '#') {
            state = 13; return true;
        }
        else return false;
    }
    case 13: {if (isdigit(ch) || isletter(ch)) {
        state = 14; return true;
    }
            else return false;
    }
    case 14: {if (isdigit(ch) || isletter(ch)) {
        state = 14; return true;
    }
            else return false; }
    }
}

    bool solve(){
       int length;cin >> length;
        string str;
        cin >> str;
        int state = 1;
        for (int i = 0; i <length; i++) {
            if (!get_next_state(str[i], state)) {
                return false;
            }
        }
        return state ==2||state==5||state==8||state==9||state==12||state==14||state==15||state==16;
    }


    int main() {
        int T; cin >> T;
        while (T--) {
            if (solve())cout << "Yes" << endl;
            else cout << "No" << endl;
        }return 0;
    }