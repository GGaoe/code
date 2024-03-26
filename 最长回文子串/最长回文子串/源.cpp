#include <iostream>
#include <string.h>

using namespace std;

char s[220000];
char ss[220000];
int maxid=1;
int id=1;
int p[220000];

int main() {
    int m = 0;
    cin >> ss;
    s[0] = '$';
    
    for (int b = 0; ss[b] != '\0'; b++) {
        s[++m] = ss[b];
        if(ss[b+1]!='\0')s[++m] = '#';
    }
    s[++m] = '?';
    //cout << s << endl;
    cout << m << endl;
    for (int i = 1; i <= m; ++i) {
        cout << 2 * id - i << endl;
        if (maxid > i) p[i] = min(maxid - i, p[2 * id - i]);
        else p[i] = 1;
        while (s[i - p[i]] == s[i + p[i]]&& i - p[i]>=0 && i + p[i]<=m) p[i]++;
        if (i + p[i] > maxid) {
            maxid = i + p[i];
            id = i;
        }
    }
    int max_rad = 0;
    for (int i = 1; i < m; i++) {
        if (p[i] > max_rad)max_rad = p[i];
    }
    if (max_rad == 1)cout << 1;
    else cout << max_rad-1 << endl;


	return 0;
}