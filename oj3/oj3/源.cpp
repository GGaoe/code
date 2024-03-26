#include<iostream>
#include<string>
#include <map>
#include <unordered_map>
using namespace std;
int n;//n个站点
int m;//m辆列车
string station[1000];//车站名字
unordered_map<string, int> change_time;//每个站点的换乘时间，change_time[s]表示s站点的换乘时间
unordered_map<string, string> train[20]; //20辆列车的到达时刻表,train[i][s]表示第i列车到达s站点的时间
string src;//出发车站
string dst;//到达车站
int lasttime;//最晚到达时间
unordered_map<string, int> many_ans[100];//用来存放可能的答案
unordered_map<int, string> train_order[20];//20辆列车经过每个站点的顺序,train_order[i][j]表示第i辆列车经过第j个站的站名
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        station[i] = temp;
        cin >> change_time[temp];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u = 0;
        cin >> u;
        for (int j = 0; j < u; j++) {
            string temp;
            cin >> temp;
            train_order[i][j] = temp;
            string time;
            cin >> time;
            train[i][temp] = time;
        }
    }
    cin >> src;
    cin >> dst;
    cin >> lasttime;

    for (int i = 0; i < m; i++) {
        //从第i辆列车出发
        if (train[i].count(src)) {
            //如果i列车存在src这个站点
            int beginid = 0;
            for (int j = 0; j < train[i].size(); j++) {
                if (train_order[i][j] == src) {
                    beginid = j;
                    break;
                }
            }
            for (int u = beginid; train_order[i][u] != dst; u++) {
                cout << train[i][train_order[i][u]] << " " << train_order[i][u] << endl;
            }
            cout << train[i][dst] << " " << dst << endl;
            break;
        }
    }
    return 0;
}