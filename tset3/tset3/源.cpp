#include <iostream>
#include <vector>
using namespace std;
int N, M; // N �Ƕ�����,MΪ����
vector<int> v[100001];//������ź�ÿ���ڵ������ӵĽڵ�
int num[100001];//��ʶÿ���ڵ�����˭��0������1 dxy��2 syp��
int have_checked[100001];//���һ�����Ƿ����
bool flag = 1;//��ʾ�Ƿ��ܹ����л���,�������ì�ܣ����ܻ�����Ϊ0��
int count_dxy, count_syp;//dxy��syp�ĵ�ĸ���
int last1, last2;
/*����˼·��
����ͨ������dxy�Ľڵ������Ľڵ㶼������syp�ģ�
 ͬ������ͨ������syp�Ľڵ������Ľڵ㶼������dxy��
 �ӵ�һ���ڵ�����dxy��ʼ�ơ�
*/


void check(int count,bool f) {//countָ�ڼ����ڵ㣬f��ʾ�ýڵ�������˭�ģ�1dxy��0syp
	if (!flag)return;//����Ѿ������ܻ��֣��򷵻أ�
	have_checked[count] = 1;//count�ڵ��Ѿ�����
	if (f) {
		for (int neighbor : v[count]) {
			if (num[neighbor] == 1) {//����ٶ���Ҳ��dxy�ģ������
				flag = 0;
				return;
			}
			else if (num[neighbor] == 0) {//û��ռ������syp��
				count_syp++;
				if (neighbor > last2)last2 = neighbor;
				num[neighbor] = 2;
			}
			
		}
		for (int neighbor : v[count]) {
			if (!have_checked[neighbor]) {//��û�м���������һ��
				check(neighbor, 0);
			}
		}
		v[count].clear();//�����ڴ�
	}
	else {
		for (int neighbor : v[count]){
			if (num[neighbor] == 2) {//����ٶ���Ҳ��syp�ģ������
				flag = 0;
				return;
			}
			else if (num[neighbor] == 0) {//û��ռ������dxy��
				num[neighbor] = 1;
				if (neighbor > last1)last1 = neighbor;
				count_dxy++;
			}

		}
		for (int neighbor : v[count]) {
			if (!have_checked[neighbor])
			check(neighbor, 1);//��û�м���������һ��
		}
		v[count].clear();//�����ڴ�
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
	check(1,1);//��һ���ڵ���dxy��
	end();//�жϽ��
	return 0;
}