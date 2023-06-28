#include <iostream>
#include <vector>
using namespace std;
int N, M; // N 是顶点数,M为边数
vector<int> v[100001];//用来存放和每个节点相连接的节点
int num[100001];//标识每个节点属于谁，0无主，1 dxy，2 syp；
int have_checked[100001];//标记一个点是否检查过
bool flag = 1;//标示是否能够进行划分,如果出现矛盾，则不能划分判为0；
int count_dxy, count_syp;//dxy和syp的点的个数
int last1, last2;
/*总体思路：
所有通过线与dxy的节点相连的节点都是属于syp的，
 同理所有通过线与syp的节点相连的节点都是属于dxy的
 从第一个节点属于dxy开始推。
*/


void check(int count,bool f) {//count指第几个节点，f表示该节点是属于谁的，1dxy，0syp
	if (!flag)return;//如果已经不可能划分，则返回；
	have_checked[count] = 1;//count节点已经检查过
	if (f) {
		for (int neighbor : v[count]) {
			if (num[neighbor] == 1) {//如果临顶点也是dxy的，则错误
				flag = 0;
				return;
			}
			else if (num[neighbor] == 0) {//没有占用则是syp的
				count_syp++;
				if (neighbor > last2)last2 = neighbor;
				num[neighbor] = 2;
			}
			
		}
		for (int neighbor : v[count]) {
			if (!have_checked[neighbor]) {//若没有检查过，则检查一遍
				check(neighbor, 0);
			}
		}
		v[count].clear();//清理内存
	}
	else {
		for (int neighbor : v[count]){
			if (num[neighbor] == 2) {//如果临顶点也是syp的，则错误
				flag = 0;
				return;
			}
			else if (num[neighbor] == 0) {//没有占用则是dxy的
				num[neighbor] = 1;
				if (neighbor > last1)last1 = neighbor;
				count_dxy++;
			}

		}
		for (int neighbor : v[count]) {
			if (!have_checked[neighbor])
			check(neighbor, 1);//若没有检查过，则检查一遍
		}
		v[count].clear();//清理内存
	}
	return;
}

void end() {
	if ((count_dxy + count_syp != N)||!flag)
	{
		cout << "No";
		return;
	}
	cout << "Yes" << endl;
	cout << count_dxy <<" "<< count_syp<<endl;
	for (int i = 1; i <= N; i++) {
		if (num[i] == 1)cout << i;
		if (num[i] == 1 && i != last1)cout << " ";
	}cout << endl;
	for (int i = 1; i <= N; i++) {
		if (num[i] == 2)cout << i;
		if (num[i] == 2 && i != last2)cout << " ";
	}


}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	num[1] = 1;
	count_dxy++;
	last1 = 1;
	check(1,1);//第一个节点是dxy的
	end();//判断结果
	return 0;
}