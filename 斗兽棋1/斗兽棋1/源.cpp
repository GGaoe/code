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
int count(int a) {
    a += 999;
    a /= 1000;
    return a + 499 * 2;
}

void conmond(int loc,int step) {
    int e = 1;
    for (int i = 0;i< zmap[loc].size();i++) {
        if (zmap[loc][i] == step__dxy[step]) zmap[loc][i] += count(e);
    }
}
void desdroy(int loc, int step) {
    int e = 1;
    for (int i = 0;i< mapp[steep[step] - 1].size(); i++) {
        if (step__z[step] == mapp[steep[step] - 1][i]) mapp[steep[step] - 1][i] += count(e);
    }
}
inline void move(int loc, int step) {
    step_record.push_back(loc);
    mapp[loc].push_back(step__dxy[step]);
    zmap[steep[step] - 1].push_back(step__z[step]);
    conmond(loc, step);
    desdroy(loc, step);
    return;
}

void common(int loc, int step) {
    for (int i = 0; i < zmap[loc].size(); i++) {
        int e = 1;
        if (zmap[loc][i] == step__dxy[step]) zmap[loc][i] -= count(e);
    }
}
void back(int loc, int step) {
    for (int i = 0; i < mapp[steep[step] - 1].size(); i++) {
        int e = 1;
        if (step__z[step] == mapp[steep[step] - 1][i]) mapp[steep[step] - 1][i] -= count(e);
    }
}
inline void remove(int loc, int step) {

    step_record.pop_back();
    mapp[loc].pop_back();
    zmap[steep[step] - 1].pop_back();
    common(loc, step);
    back(loc, step);
    return;
}

void fen(int i) {
    count_dxy += 3 * (mapp[i][0] + mapp[i][1] + mapp[i][2]);
}
void fen2(int i) {
    for (int k = 0; k < 3; k++) {
        if (mapp[i][k] < 999) count_dxy += mapp[i][k];
    }
}
void fen3(int i) {
    count_z += 3 * (zmap[i][0] + zmap[i][1] + zmap[i][2]);
}
void fen4(int i) {
    for (int k = 0; k < 3; k++) {
        if (zmap[i][k] < 999) count_z += zmap[i][k];
    }
}

void end_fen() {
    bool flag = false;
    count_dxy = 0;
    count_z = 0;
    for (int i = 0; i < 3; i++) {
        flag = true;
        int e = 1;
        if (mapp[i][0] == mapp[i][1] &&
            mapp[i][1] == mapp[i][2] &&
            mapp[i][0] <count(e))
        {
            fen(i);
        }
        else {
            flag = false;
            for (int k = 0; k < 3; k++) {
                int k2 = (k + 1) % 3, k3 = (k + 2) % 3;
                e = 1;
                if (mapp[i][k] == mapp[i][k2]
                    && mapp[i][k] < count(e)) {
                    count_dxy += 2 * (mapp[i][k] + mapp[i][k2]);
                    if (mapp[i][k3] < 999)
                        count_dxy += mapp[i][k3];
                    flag = true;
                }
            }
        }
        if (!flag) {
            fen2(i);
        }

        flag = true;
        if (zmap[i][0] == zmap[i][1] && zmap[i][1] == zmap[i][2] && zmap[i][0] < 999) 
            fen3(i);
        else {
            flag = false;

            for (int k = 0; k < 3; k++) {
                int k2 = (k + 1) % 3, k3 = (k + 2) % 3;
                if (zmap[i][k] == zmap[i][k2] && zmap[i][k] < 999) {
                    count_z += 2 * (zmap[i][k] + zmap[i][k2]);
                    if (zmap[i][k3] < 999) count_z += zmap[i][k3];
                    flag = true;
                }
            }
        }
        if (!flag) {
            fen4(i);
        }
    }
    return;
}
void end(int step) {
    if (step == 9) {
        end_fen();
        if (count_dxy > count_z) reach_end = true;
        return;
    }
    else return;
}
bool full(int step) {
    if (mapp[good[step] - 1].size() == 3)return true;
    else return false;
}
bool full2(int i) {
    if (mapp[i].size() == 3)return true;
    else return false;
}
void dfs(int step) {
    end(step);
    if (reach_end)return;
    else {
        if (good[step] > 0) {
            if (full(step)) return;
            move(good[step] - 1, step);
            dfs(step + 1);
            if (reach_end) return;
            remove(good[step] - 1, step);
        }
        else if (good[step] < 0) {
            int forbid = -(good[step] + 1);
            for (int i = 0; i < 3; i++) {
                if (i == forbid) continue;
                if (full2(i)) continue;
                move(i, step);
                dfs(step + 1);
                if (reach_end) return;
                remove(i, step);
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                if (full2(i)) continue;
                move(i, step);
                dfs(step + 1);
                if (reach_end) return;
                remove(i, step);
            }
        }
        return;
    }
}
void cin_1() {
    for (int i = 0; i < 9; i++) cin >> step__dxy[i];//dxy点数
}
void cin_2() {
    for (int i = 0; i < 9; i++) cin >> step__z[i];//z点数
}
void cin_3() {
    for (int i = 0; i < 9; i++) cin >> steep[i];//步数
}
void cin_4() {
    for (int i = 0; i < 9; i++) cin >> good[i];//好坏
}
int main() {
    cin_1(); cin_2(); cin_3(); cin_4();
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