#include <iostream>
#include <string>
#include "complex.h"
using namespace std;
int main() {
	cout << "��ȡ������" << endl;
	//ʵ�ֳ�ȡʵ���鲿��s�������׼�ṹa+bi��0��1����ʡ��
	string s;
	cin >> s;
	chouqv(s);
	//ʵ�ָ�������Ӽ��˳�,��������������ʵ�����鲿����������ʵ�����鲿
	double re1, im1, re2, im2;
	cout << "���������" << endl;
	cin >> re1 >> im1 >> re2 >> im2;
	add(re1, im1, re2, im2);
	subtract(re1, im1, re2, im2);
	multiply(re1, im1, re2, im2);
	devide(re1, im1, re2, im2);
	//ʵ�ֹ��츴�������ձ�׼��ʽ���븴����ʵ���鲿��������츴���ı�׼��ʽ
	double re, im;
	cout << "���츴����" << endl;
	cin >> re >> im;
	construct(re, im);
	return 0;
}