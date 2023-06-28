#include <iostream>
using namespace std;
#define ull unsigned long long
static const int maxx = 20;
int  k, c;
ull m;
ull q[30];
#define Mod 998244353
struct Matrix {
	ull arry[maxx][maxx];
	Matrix() {
		for (int i = 0; i < maxx; i++) {
			for (int j = 0; j < maxx; j++) {
				arry[i][j] = 0;
			}
		}
	}
};

Matrix MatrixMul(Matrix left, Matrix right) {
	Matrix ret;
	for (int i = 0; i <m+k+2; i++) {
		for (int j = 0; j < m+k+2; j++) {
			for (int y = 0; y < m+k+2; y++) {
				//cout << left.arry[i][y];
				ret.arry[i][j] =( ret.arry[i][j]+(left.arry[i][y] %= Mod) * (right.arry[y][j] %= Mod))%Mod;
			}
		}
	}
	return ret;
}

Matrix Power(ull n, Matrix r) {
	Matrix ret;
	for (int i = 0; i < m+k+2; i++) {
		ret.arry[i][i] = 1;
	}
	Matrix one = r;
	for (; n > 0; n >>= 1) {
		if ((n & 1) == 1) {
			ret = MatrixMul(ret, one);
		}
		one = MatrixMul(one, one);
	}
	/*
	for (int i = 0; i < m + k + 2; i++) {
		for (int j = 0; j < m + k + 2; j++) {
			cout << ret.arry[i][j] << " ";
		}cout << endl;
	}cout << endl;
	*/

	return ret;
}

ull compute(ull n,Matrix r) {
	ull sum = 0;
	Matrix u;
	u = Power(n - m, r);
	/*for (int i = 0; i < m + k + 2; i++) {
		for (int j = 0; j < m + k + 2; j++) {
			cout << u.arry[i][j] << " ";
		}cout << endl;
	}cout << endl << endl;*/
	for (int i = 0; i < m; i++) {
		sum += q[m - 1 - i] * (u.arry[i][0]%Mod)%Mod;
		sum %= Mod;
	}
	ull a = m+1;
	for (int i = m; i < m + k; i++) {
		sum += a * u.arry[i][0] % Mod;
		sum %= Mod;
		//a = a * a;  Oops! A fucking stupid dault.
		a = a * (m+1);
		a %= Mod;
	}
	ull num1 = 1;
	for (int i = 0; i < m; i++) {
		num1 *= c; num1 %= Mod;
	}
	sum += num1 * u.arry[m + k][0] % Mod;
	sum %= Mod;
	
	sum += u.arry[m + k + 1][0] % Mod;
	sum %= Mod;
	
	return sum;
}

int main() {
	cin >> m >> k >> c;

	Matrix matrix;
	for (int i = 0; i < m; i++) {
		cin>>matrix.arry[i][0];
	}//ai
	for (int i = 0; i < m; i++) {
		cin >> q[i];
	}//fi
	cin >> matrix.arry[m+k+1][0];//b0在最后
	for (int i = m; i < m + k; i++) {
		cin >> matrix.arry[i][0];
	}//b1~bk
	matrix.arry[m + k][0] = c;//c
	for (int i = 0; i < m-1; i++) {
		matrix.arry[i][i + 1] = 1;
	}//第二到m-1列
	for (int i = m; i <= m + k + 1; i++) {
		matrix.arry[m + k + 1][i] = 1;
	}//最后一行
	matrix.arry[m + k][m + k] = c;//角落c
	matrix.arry[m + k+1][m + k] = 0;
	if (k == 1) {
		matrix.arry[m][m ] = 1;
	}
	else if (k == 2) {
		matrix.arry[m][m] = 1;
		matrix.arry[m][m+1] = 2;
		matrix.arry[m+1][m+1] = 1;
	}
	else if (k == 3) {
		matrix.arry[m][m] = 1;
		matrix.arry[m][m+1] = 2;
		matrix.arry[m+1][m+1] = 1;
		matrix.arry[m][m+2] = 3;
		matrix.arry[m+1 ][m+2] = 3;
		matrix.arry[m+2][m+2] = 1;
	}
	
	int b; cin >> b;
	//测试
	/*for (int i = 0; i < m + k + 2; i++) {
		for (int j = 0; j < m + k + 2; j++) {
			cout << matrix.arry[i][j] << " ";
		}cout << endl;
	}*/

	for (int i = 0; i < b; i++) {
		ull num2; cin >> num2;
		if (num2 <= m) {
			cout << q[num2];
		}
		else { cout << compute(num2, matrix); }
		if (i != b - 1) {
			cout << " ";
		}
	}
	//测试
	/*for (int i = 0; i < m + k + 2; i++) {
		for (int j = 0; j < m + k + 2; j++) {
			cout << matrix.arry[i][j] << " ";
		}cout << endl;
	}*/
	return 0;
}