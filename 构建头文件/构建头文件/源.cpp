#include <iostream>
#include <string>
#include "complex.h"
using namespace std;
void chouqv(string s) {
	string s_ = s;
	string re, im = "";
	bool flag = 1;
	int l = s_.length();
	for (int i = 0; i < l; i++) {
		if (flag) {
			if (s_[0] == '-' && i == 0) {
				re += '-';
			}
			if (s_[i] != '+' && s_[i] != '-') {
				re += s[i];
			}
		}
		if (s_[i] == '+' || s_[i] == '-') {
			flag = 0; im += s_[i]; continue;
		}
		if (flag == 0) {
			if (s[i] != 'i')
				im += s[i]; else break;
		}
	}cout << "实部：" << re << endl;
	cout << "虚部：" << im << endl; return;
}
void add(double re1, double im1, double re2, double im2) {
	double  re, im;
	re = re1 + re2; im = im1 + im2;
	cout <<"相加实部是"<< re << "  " << im << endl;
	return;
}
void subtract(double re1, double im1, double re2, double im2) {
	double  re, im;
	re = re1 - re2; im = im1 - im2;
	cout << "相减实部是" << re <<" "<<"虚部是"<< im << endl;
	return;
}
void multiply(double re1, double im1, double re2, double im2) {
	double  re, im;
	re = re1 * re2 - im1 * im2; im = re1 * im2 + re2 * im1;
	cout << "相乘实部是" << re << "  "<< "虚部是" << im<<endl;
	return;
}
void devide(double re1, double im1, double re2, double im2) {
	double  re, im;
	re = (re1 * re2 + im1 * im2) / (re2 * re2 + im2 * im2);
	im = (im1 * re2 - re1 * im2) / (re2 * re2 + im2 * im2);
	cout << "相除实部是" << re <<"  "<< "虚部是" << im<<endl;
	return;
}
void construct(double re, double im) {
	if (im > 0)cout << re << "+" << im << "i" << endl;
	else cout << re << im<<"i" << endl;
	return;
}