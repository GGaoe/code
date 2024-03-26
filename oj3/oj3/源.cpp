#include<iostream>
#include<string>
#include <map>
#include <unordered_map>
using namespace std;
int n;//n��վ��
int m;//m���г�
string station[1000];//��վ����
unordered_map<string, int> change_time;//ÿ��վ��Ļ���ʱ�䣬change_time[s]��ʾsվ��Ļ���ʱ��
unordered_map<string, string> train[20]; //20���г��ĵ���ʱ�̱�,train[i][s]��ʾ��i�г�����sվ���ʱ��
string src;//������վ
string dst;//���ﳵվ
int lasttime;//������ʱ��
unordered_map<string, int> many_ans[100];//������ſ��ܵĴ�
unordered_map<int, string> train_order[20];//20���г�����ÿ��վ���˳��,train_order[i][j]��ʾ��i���г�������j��վ��վ��
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
        //�ӵ�i���г�����
        if (train[i].count(src)) {
            //���i�г�����src���վ��
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