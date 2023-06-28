#include <iostream>
#include <string>

using namespace std;

string decompress(const string& s, int& i) {
    string res;
    while (i < s.size() && s[i] != ']') {
        if (!isdigit(s[i])&&s[i]!='[') {
            res += s[i++];
        }
        else {
            i++;
            int n = 0;
            while (i < s.size() && isdigit(s[i])) {
                n = n * 10 + s[i++] - '0';
            }
           
            string t = decompress(s, i);
            i++; // ']'
            while (n-- > 0) {
                res += t;
            }
        }
    }
    return res;
}

string decompress(const string& s) {
    int i = 0;
    return decompress(s, i);
}

int main() {
    string s;
    cin >> s;
    cout << decompress(s) << endl;
    return 0;
}
