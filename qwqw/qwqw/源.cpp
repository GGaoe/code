#include<iostream>
#include<vector>

using namespace std;

int step__dxy[9], step__z[9], steep[9], good[9];
int count_dxy, count_z;
int a11[3], z11[3];
vector<int> step_record;
vector<int> mapp[3];
vector<int> zmap[3];
bool reach_end = false;
int a111, z111;

inline void move(int loc, int step) {
    step_record.push_back(loc);
    mapp[loc].push_back(step__dxy[step]);
    zmap[steep[step] - 1].push_back(step__z[step]);
    for (int i = 0; i < zmap[loc].size();i++) {
        if (zmap[loc][i] == step__dxy[step]) zmap[loc][i] += 999;
    }
    for (int i = 0;i< mapp[steep[step] - 1].size();i++) {
        if (step__z[step] == mapp[steep[step] - 1][i]) mapp[steep[step] - 1][i] += 999;
    }
    return;
}

inline void remove(int loc, int step) {

    step_record.pop_back();
    mapp[loc].pop_back();
    zmap[steep[step] - 1].pop_back();
    for (int i = 0; i < zmap[loc].size(); i++) {
        if (zmap[loc][i] == step__dxy[step]) zmap[loc][i] -= 999; // 
    }
    for (int i = 0; i < mapp[steep[step] - 1].size(); i++) {
        if (step__z[step] == mapp[steep[step] - 1][i]) mapp[steep[step] - 1][i] -= 999;
    }
    return;
}

void count() {


    bool flag = false;
    count_dxy = 0;
    count_z = 0;
    for (int i = 0; i < 3; i++) {
        // 这里使用了一种奇妙的方法，如果三个都一样flag就是true，如果俩一样flag也是true，但是如果三个都不一样flag就是好false
        flag = true;
        if (mapp[i][0] == mapp[i][1] && mapp[i][1] == mapp[i][2] && mapp[i][0] < 999) count_dxy += 3 * (mapp[i][0] + mapp[i][1] + mapp[i][2]);
        else {
            flag = false;
            for (int k = 0; k < 3; k++) {
                int k1 = k, k2 = (k + 1) % 3, k3 = (k + 2) % 3;
                if (mapp[i][k1] == mapp[i][k2] && mapp[i][k1] < 999) {
                    count_dxy += 2 * (mapp[i][k1] + mapp[i][k2]);
                    if (mapp[i][k3] < 999) count_dxy += mapp[i][k3];
                    flag = true;
                }
            }
        }
        if (!flag) {
            for (int k = 0; k < 3; k++) {
                if (mapp[i][k] < 999) count_dxy += mapp[i][k];
            }
        }


        flag = true; // case: *3
        if (zmap[i][0] == zmap[i][1] && zmap[i][1] == zmap[i][2] && zmap[i][0] < 999) count_z += 3 * (zmap[i][0] + zmap[i][1] + zmap[i][2]);
        else {
            flag = false;
            for (int k = 0; k < 3; k++) { // case: *2 
                int k1 = k, k2 = (k + 1) % 3, k3 = (k + 2) % 3;
                if (zmap[i][k1] == zmap[i][k2] && zmap[i][k1] < 999) {
                    count_z += 2 * (zmap[i][k1] + zmap[i][k2]);
                    if (zmap[i][k3] < 999) count_z += zmap[i][k3];
                    flag = true;
                }
            }
        }
        if (!flag) {
            for (int k = 0; k < 3; k++) {
                if (zmap[i][k] < 999) count_z += zmap[i][k];
            }
        }
    }
    //cout << "cnt result alley" << acnt << " enemy " << ecnt << endl;

    return;
}

void dfs(int step) {
    //cout << "dfs" << step << endl;
    if (step == 9) {
        count();
        if (count_dxy > count_z) reach_end = true;
        return;
    }

    if (good[step] > 0) {
        if (mapp[good[step] - 1].size() == 3) return;
        move(good[step] - 1, step);
        dfs(step + 1);
        if (reach_end) return;
        remove(good[step] - 1, step);
    }
    else if (good[step] < 0) {
        int forbid = 0 - good[step] - 1;
        for (int i = 0; i < 3; i++) {
            if (i == forbid) continue;
            if (mapp[i].size() == 3) continue;
            move(i, step);
            dfs(step + 1);
            if (reach_end) return;
            remove(i, step);
        }
    }
    else {
        for (int i = 0; i < 3; i++) {
            if (mapp[i].size() == 3) continue;
            move(i, step);
            dfs(step + 1);
            if (reach_end) return;
            remove(i, step);
        }
    }
    return;
}

int main() {

    for (int i = 0; i < 9; i++) cin >> step__dxy[i];
    for (int i = 0; i < 9; i++) cin >> step__z[i];
    for (int i = 0; i < 9; i++) cin >> steep[i];
    for (int i = 0; i < 9; i++) cin >> good[i];

    dfs(0);

    if (!reach_end) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        for (int i = 0; i < 9; i++) {
            cout << step_record[i] + 1 << ' ';
        }
    }

    return 0;
}