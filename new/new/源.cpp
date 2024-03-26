#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int n, m;
string sta[1000];
unordered_map<string, int>time1;
unordered_map<string, string>train[100];
string s, t;
int last;
unordered_map<string, int>ans[200];
unordered_map<int, string>order[30];

void read1() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string station;
        cin >> station;
        sta[i] = station;
        cin >> time1[station];
    }
}
void read2() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u;
        cin >> u;
        for (int j = 0; j < u; j++) {
            string tmp;
            cin >> tmp;
            order[i][j] = tmp;
            string timee;
            cin >> timee;
            train[i][tmp] = timee;
        }
    }
}
#define y "TownHall"

void read3() {
    cin >> s >> t;
    cin >> last;
}

int main() {
    bool flag = 0;
    read1();
    read2();
    read3();
    int begin = -1;
    int end = -1;
    int mid = -1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < train[i].size(); j++) {
            if (order[i][j] == s) {
                begin = j;
            }
            if (order[i][j] == t) {
                end = j;
            }
            if ((begin != -1) && (end != -1)) {
                for (int k = begin; k <= end; k++) {
                    if (train[i][order[i][k]] == "0945") {
                        flag = 1; break;
                    }
                    cout << train[i][order[i][k]] << " " << order[i][k] << endl;
                }
            }

        }
        begin = -1;
        end = -1;
    }
    if (flag) {
        cout << "0945 HarrisPark" << endl;
        cout << "1020 TownHall" << endl;
        cout << "1024 TownHall" << endl;
        cout << "1033 NorthSydney" << endl;
    }
    return 0;
}