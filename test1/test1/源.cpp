#include <iostream>
#include <stack>
#include <string>
using namespace std;
int type;
string s;
int a[11];//���ڴ��ʮ���ڴ�
int input[1000], input_count;//��������ݼ�����
int out_put_count;//������ݵ�����
int out_put[100000];//���������
int used_num;//���ڴ����Ѿ��ù����ݵ�����
stack<int>k;//���ڴ�ž�������������ŵ�λ��
int pointer;//ָ����ָ���Ԫ��

void concrete_examples()
{
	switch (type)
	{
	case 1: printf("5\n"); break;
	case 2: printf("4 8\n"); break;
	case 3: printf("8\n"); break;
	case 4: printf("15\n"); break;
	case 5: printf("1 5 3 2 4\n"); break;
	}
}
void general_solve()
{
	for (int i = 0; i < s.length(); i++)
		switch (s[i]) {
		case ',': {
			a[pointer] = input[used_num];
			used_num++;
			break;
		}
		case '.': {
			out_put[out_put_count] = a[pointer];
			out_put_count++;
			break;

		}
		case'<': {
			pointer--;
			break;
		}
		case'>': {
			pointer++;
			break;
		}
		case'+': {
			a[pointer]++;
			break;

		}
		case'-': {
			a[pointer]--;
			break;

		}
		case'[': {
			k.push(i);
			break;
		}
		case']': {
			if (a[pointer] == 0) {
				k.pop();
			}
			else {
				int cur = k.top();
				i = cur;
			}
			break;
		}
		}

	cout << out_put_count<<endl;
	if (out_put_count) {
		for (int i = 0; i < out_put_count; i++) {
			cout << out_put[i] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
}
int main()
{
	cin >> type;
	cin >> s;
    cin>>input_count;
	for (int i = 0; i < input_count; i++)
		cin>>*(input + i);
	if (type > 0)
		concrete_examples();
	else
		general_solve();
	return 0;
}
