#include <iostream>
using namespace std;
#define ull unsigned long long 
static const int row = 2;
static const int col = 2;
static const long long Mod = 998244353;
struct Matrix {
	ull arry[col][row];
	Matrix() {
		for (int i = 0; i <col; i++) {
			for (int j = 0; j < row; j++) {
				arry[i][j] = 0;
			}
		}
	}
	Matrix(ull matrix[][col]) {
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				arry[i][j] = matrix[i][j];
			}
		}
	}

};
Matrix MatrixMul(Matrix l, Matrix r) {
	Matrix ret;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < col; k++) {
				ret.arry[i][j] += ((l.arry[i][k] %= Mod) * (r.arry[k][j] %= Mod)) % Mod;
			}
		}
	}
	return ret;
}

Matrix Power(int n, Matrix r) {
	Matrix ret;
	for (int i = 0; i < col; i++) {
		ret.arry[i][i] = 1;
	}
	Matrix one = r;
	for (; n > 0; n >>= 1) {
		if ((n & 1) == 1) {
			ret = MatrixMul(ret, one);
		}
		one= MatrixMul(one, one);
	}

	return ret;
}
ull fb(int n) {
	if (n < 0)return 0;
	if (n == 1 || n == 2)return 1;
	ull sq[][col] = {{1,1},{1,0}};
	Matrix ret = Power(n - 2, sq);
	return{(ret.arry[0][0]+ret.arry[1][0])%Mod};
}

int main() {
	int n; cin >> n;
	cout << fb(n)<<endl;
	return 0;
}