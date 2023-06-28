#include <iostream>
#include <string>
#include "complex.h"
using namespace std;
int main() {
	cout << "抽取操作：" << endl;
	//实现抽取实部虚部，s需输入标准结构a+bi，0、1不能省略
	string s;
	cin >> s;
	chouqv(s);
	//实现复数运算加减乘除,输入两个复数的实部和虚部，输出结果的实部和虚部
	double re1, im1, re2, im2;
	cout << "运算操作：" << endl;
	cin >> re1 >> im1 >> re2 >> im2;
	add(re1, im1, re2, im2);
	subtract(re1, im1, re2, im2);
	multiply(re1, im1, re2, im2);
	devide(re1, im1, re2, im2);
	//实现构造复数，按照标准格式输入复数的实部虚部，输出构造复数的标准形式
	double re, im;
	cout << "构造复数：" << endl;
	cin >> re >> im;
	construct(re, im);
	return 0;
}