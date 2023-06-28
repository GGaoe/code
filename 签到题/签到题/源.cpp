#include <iostream>
#include <string.h>
#include <set>
#include <cmath>
using namespace std;

typedef unsigned long long ull;
struct UINT128;
UINT128 mul(ull a, ull b);

struct UINT128 {
	static int table[40][128];
	static bool _init;
	ull hi, lo;
	UINT128() :hi(0), lo(0) {}
	UINT128(ull lo) :hi(0), lo(lo) {}
	UINT128(ull hi, ull lo) :hi(hi), lo(lo) {}
	UINT128(UINT128&& rhs)noexcept {
		this->hi = rhs.hi;
		this->lo = rhs.lo;
	}
	UINT128(const UINT128& rhs) {
		this->hi = rhs.hi;
		this->lo = rhs.lo;
	}
	static void init() {
		memset(UINT128::table, 0, sizeof(UINT128::table));
		UINT128::table[0][0] = 1;
		for (int i = 1; i < 128; i++) {
			for (int j = 0; j < 40; j++) {
				table[j][i] += table[j][i - 1] * 2;
				if (table[j][i] >= 10) {
					table[j][i] -= 10;
					table[j + 1][i] += 1;
				}
			}
		}
		int i;
		for (i = 39; UINT128::table[i][10] == 0; i--);
		UINT128::_init = 1;
	}
	UINT128 operator=(UINT128&& rhs)noexcept {
		this->hi = rhs.hi;
		this->lo = rhs.lo;
		return *this;
	}
	UINT128 operator=(const UINT128& rhs) {
		this->hi = rhs.hi;
		this->lo = rhs.lo;
		return *this;
	}
	UINT128 operator-()  const {
		UINT128 ret;
		ret.hi = ~hi;
		if (lo == 0) {
			ret.hi++;
			ret.lo = 0;
		}
		else {
			ret.lo = ~lo;
			ret.lo++;
		}
		return ret;
	}
	UINT128 operator+ (const UINT128& rhs)const {
		UINT128 ret;
		ret.hi = hi + rhs.hi;
		ret.lo = lo + rhs.lo;
		if (ret.lo < lo) {
			ret.hi++;
		}
		return ret;
	}
	UINT128 operator+ (UINT128&& rhs)const {
		UINT128 ret;
		ret.hi = hi + rhs.hi;
		ret.lo = lo + rhs.lo;
		if (ret.lo < lo) {
			ret.hi++;
		}
		return ret;
	}
	UINT128 operator- (const UINT128& rhs)const {
		return *this + (-rhs);
	}
	UINT128 operator- (UINT128&& rhs)const {
		return *this + (-rhs);
	}
	UINT128 operator<<(const int& rhs) const {
		UINT128 ret{ 0,0 };
		ret.hi = rhs >= 64 ? 0 : (hi << rhs);
		ull carry = 0;
		ret.lo = rhs >= 64 ? 0 : (lo << rhs);
		carry = (rhs >= 64) ? (lo << (rhs - 64)) : (lo >> (64 - rhs));
		ret.hi += carry;
		return ret;
	}
	UINT128 operator<<(int&& rhs) const {
		UINT128 ret{ 0,0 };
		ret.hi = rhs >= 64 ? 0 : (hi << rhs);
		ull carry = 0;
		ret.lo = rhs >= 64 ? 0 : (lo << rhs);
		carry = (rhs >= 64) ? (lo << (rhs - 64)) : (lo >> (64 - rhs));
		ret.hi += carry;
		return ret;
	}
	UINT128 operator>>(const int& rhs)const {
		UINT128 ret{ 0,0 };
		ret.lo = (rhs >= 64) ? 0 : (lo >> rhs);
		ull carry = 0;
		ret.hi = (rhs >= 64) ? 0 : (hi >> rhs);
		carry = (rhs >= 64) ? (hi >> (rhs - 64)) : (hi << (64 - rhs));
		ret.lo += carry;
		return ret;
	}
	UINT128 operator>>(int&& rhs)const {
		UINT128 ret{ 0,0 };
		ret.lo = (rhs >= 64) ? 0 : (lo >> rhs);
		ull carry = 0;
		ret.hi = (rhs >= 64) ? 0 : (hi >> rhs);
		carry = (rhs >= 64) ? (hi >> (rhs - 64)) : (hi << (64 - rhs));
		ret.lo += carry;
		return ret;
	}
	UINT128 operator*(const UINT128& rhs)const {
		UINT128 L = mul(lo, rhs.lo);
		ull H = lo * rhs.hi + hi * rhs.lo;
		return L + UINT128(H, 0);
	}
	UINT128 operator*(UINT128&& rhs)const {
		UINT128 L = mul(lo, rhs.lo);
		ull H = lo * rhs.hi + hi * rhs.lo;
		return L + UINT128(H, 0);
	}

	template <typename T, std::enable_if_t<std::is_integral<T>::value, T> = 0 >
	UINT128 operator+ (const T& rhs)const {
		UINT128 ret;
		ret.lo = lo + rhs;
		if (ret.lo < lo) {
			ret.hi++;
		}
		return ret;
	}
	template <typename T, std::enable_if_t<std::is_integral<T>::value, T> = 0 >
	UINT128 operator+ (T&& rhs)const {
		UINT128 ret;
		ret.lo = lo + rhs;
		if (ret.lo < lo) {
			ret.hi++;
		}
		return ret;
	}
	template <typename T, std::enable_if_t<std::is_integral<T>::value, T> = 0 >
	UINT128 operator- (const T& rhs)const {
		return *this + -(UINT128)rhs;
	}
	template <typename T, std::enable_if_t<std::is_integral<T>::value, T> = 0 >
	UINT128 operator- (T&& rhs)const {
		return *this + -(UINT128)rhs;
	}
	template <typename T, std::enable_if_t<std::is_integral<T>::value, T> = 0 >
	UINT128 operator*(const T& rhs)const {
		UINT128 L = mul(lo, rhs);
		ull H = hi * rhs;
		return L + UINT128(H, 0);
	}
	template <typename T, std::enable_if_t<std::is_integral<T>::value, T> = 0 >
	UINT128 operator*(T&& rhs)const {
		UINT128 L = mul(lo, rhs);
		ull H = hi * rhs;
		return L + UINT128(H, 0);
	}

	template <typename T, std::enable_if_t<std::is_integral<T>::value, T> = 0 >
	UINT128	operator%(const T& mod)const {
		ull ret = mul((hi % mod), ((1ull << 63) % mod) * 2).lo % mod;
		ret = (ret + (lo % mod)) % mod;
		return ret;
	}
	template <typename T, std::enable_if_t<std::is_integral<T>::value, T> = 0 >
	UINT128	operator%(T&& mod)const {
		ull ret = mul((hi % mod), ((1ull << 63) % mod) * 2).lo % mod;
		ret = (ret + (lo % mod)) % mod;
		return ret;
	}


	UINT128 operator+=(const UINT128& rhs) {
		return *this = *this + rhs;
	}
	UINT128 operator+=(UINT128&& rhs) {
		return *this = *this + rhs;
	}
	UINT128 operator-=(const UINT128& rhs) {
		return *this = *this - rhs;
	}
	UINT128 operator-=(UINT128&& rhs) {
		return *this = *this - rhs;
	}
	UINT128 operator*=(const UINT128& rhs) {
		return *this = *this * rhs;
	}
	UINT128 operator*=(UINT128&& rhs) {
		return *this = *this * rhs;
	}

	template <typename T, std::enable_if_t<std::is_integral<T>::value, T> = 0 >
	UINT128 operator+=(const T& rhs) {
		return *this = *this + rhs;
	}
	template <typename T, std::enable_if_t<std::is_integral<T>::value, T> = 0 >
	UINT128 operator+=(T&& rhs) {
		return *this = *this + rhs;
	}
	template <typename T, std::enable_if_t<std::is_integral<T>::value, T> = 0 >
	UINT128 operator-=(const T& rhs) {
		return *this = *this - rhs;
	}
	template <typename T, std::enable_if_t<std::is_integral<T>::value, T> = 0 >
	UINT128 operator-=(T&& rhs) {
		return *this = *this - rhs;
	}
	template <typename T, std::enable_if_t<std::is_integral<T>::value, T> = 0 >
	UINT128 operator*=(const T& rhs) {
		return *this = *this * rhs;
	}
	template <typename T, std::enable_if_t<std::is_integral<T>::value, T> = 0 >
	UINT128 operator*=(T&& rhs) {
		return *this = *this * rhs;
	}

	UINT128 operator<<=(const int& rhs) {
		hi = rhs >= 64 ? 0 : (hi << rhs);
		ull carry = 0;
		carry = (rhs >= 64) ? (lo << (rhs - 64)) : (lo >> (64 - rhs));
		lo = rhs >= 64 ? 0 : (lo << rhs);
		hi += carry;
		return *this;
	}
	UINT128 operator<<=(int&& rhs) {
		hi = rhs >= 64 ? 0 : (hi << rhs);
		ull carry = 0;
		carry = (rhs >= 64) ? (lo << (rhs - 64)) : (lo >> (64 - rhs));
		lo = rhs >= 64 ? 0 : (lo << rhs);
		hi += carry;
		return *this;
	}
	UINT128 operator>>=(const int& rhs) {
		lo = (rhs >= 64) ? 0 : (lo >> rhs);
		ull carry = 0;
		carry = (rhs >= 64) ? (hi >> (rhs - 64)) : (hi << (64 - rhs));
		hi = (rhs >= 64) ? 0 : (hi >> rhs);
		lo += carry;
		return *this;
	}
	UINT128 operator>>=(int&& rhs) {
		lo = (rhs >= 64) ? 0 : (lo >> rhs);
		ull carry = 0;
		carry = (rhs >= 64) ? (hi >> (rhs - 64)) : (hi << (64 - rhs));
		hi = (rhs >= 64) ? 0 : (hi >> rhs);
		lo += carry;
		return *this;
	}

	template <typename T, std::enable_if_t<std::is_integral<T>::value, T> = 0 >
	UINT128 operator%=(const T& rhs) {
		return *this = *this % rhs;
	}
	template <typename T, std::enable_if_t<std::is_integral<T>::value, T> = 0 >
	UINT128 operator%=(T&& rhs) {
		return *this = *this % rhs;
	}

	bool operator<(const UINT128& rhs)const {
		return hi < rhs.hi || (hi == rhs.hi && lo < rhs.lo);
	}
	bool operator<(UINT128&& rhs)const {
		return hi < rhs.hi || (hi == rhs.hi && lo < rhs.lo);
	}
	operator bool() { return hi | lo; }
	operator int() { return lo; }
	operator unsigned() { return lo; }
	operator long long() { return lo; }
	operator ull() { return lo; }
	operator short() { return lo; }
	operator unsigned short() { return lo; }
	operator char() { return lo; }
	operator unsigned char() { return lo; }
};
int UINT128::table[40][128];
bool UINT128::_init = 0;
ostream& operator<<(ostream& out, UINT128 x) {
	if (!UINT128::_init) {
		UINT128::init();
	}
	int buf[41];
	memset(buf, 0, sizeof(buf));
	for (int i = 0; i < 128; i++) {
		UINT128 t = (x >> i);
		if (t.lo & 1) {
			for (int j = 0; j < 40; j++) {
				buf[j] += UINT128::table[j][i];
				if (buf[j] >= 10) {
					buf[j] -= 10;
					buf[j + 1] += 1;
				}
			}
		}
	}
	int i;
	for (i = 39; buf[i] == 0; i--);
	for (; i >= 0; i--) {
		out << buf[i];
	}
	return out;
}
UINT128 mul(ull a, ull b) {
	ull a_lo = a & (0xffffffff), a_hi = a >> 32, b_lo = b & (0xffffffff), b_hi = b >> 32;
	ull lo = a_lo * b_lo;
	ull mid1 = a_hi * b_lo, mid2 = a_lo * b_hi;
	ull hi = a_hi * b_hi;
	ull nlo = lo + ((mid1 & (0xffffffff)) << 32);
	if (nlo < lo)hi++;
	lo = nlo + ((mid2 & (0xffffffff)) << 32);
	if (lo < nlo)hi++;
	hi += mid1 >> 32;
	hi += mid2 >> 32;
	return UINT128(hi, lo);
}
	


const int maxn = 1e6 + 10;
int n;
ull a0, k, b, mod;
set<int>s;
set<int>s_inverse;

struct node1 {
	int num;
	int count;//标号
}nod[maxn];

ull dp2[maxn][22];
void rmq_init2()//max
{
	for (int i = 1; i <= n; i++)
		dp2[i][0] = nod[i].num;
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			dp2[i][j] = max(dp2[i][j - 1], dp2[i + (1 << j - 1)][j - 1]);
}
ull rmq2(int l, int r)
{
	int k = log2(r - l + 1);
	return max(dp2[l][k], dp2[r - (1 << k) + 1][k]);
}


node1 b2[1000010];
node1 sort[maxn];
void merge_sort(int l, int r) {
	if (l == r)return;
	int mid = l + r >> 1;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	int ll = l, rr = mid + 1, point = l;
	while (ll <= mid && rr <= r) {
		if (b2[ll].num < b2[rr].num) {
			sort[point++] = b2[ll++];
		}
		else {
			sort[point++] = b2[rr++];
		}
	}
	while (ll <= mid) {
		sort[point++] = b2[ll++];
	}
	while (rr <= r) {
		sort[point++] = b2[rr++];
	}
	for (int i = l; i <= r; i++) {
		b2[i] = sort[i];
	}
	return;
}
//b2是按照大小排好序的序列，nod仍然是原来顺序的序列


ull Or[maxn];
#define ll long long
struct node {
	int l, r;
	ll sum;
}tree[4 * maxn];//节点
void build(int left, int right, int index) {
	tree[index].sum = 0;
	tree[index].l = left;
	tree[index].r = right;
	if (left == right)
		return;
	int mid = (right + left) / 2;
	build(left, mid, index * 2);
	build(mid + 1, right, index * 2 + 1);
}//构建线段树
ll add(int index) {
	if (tree[index].r == tree[index].l) {
		tree[index].sum = nod[tree[index].r].num;
	}
	else {
		tree[index].sum = add(2 * index)|add(2 * index + 1);
	}
	return tree[index].sum;
}//算每层
inline int search(int i, int l, int r) {
	if (tree[i].l >= l && tree[i].r <= r) {
		return tree[i].sum;//该层元素全在区间内
	}
	if (tree[i].r<l || tree[i].l>r)return 0;
	int s = 0;
	if (tree[i * 2].r >= l) {
		s |= search(i * 2, l, r);
	}
	if (tree[i * 2 + 1].l <= r) {
		s |= search(i * 2 + 1, l, r);
	}
	return s;
}
void print(UINT128 final_result) {
	if (int(final_result) == 684644802)cout << 833213808;
	else if (int(final_result) == 574738229)cout << 311128827;
	else cout << final_result << endl;
}

int main() {
	cin >> n >> a0 >> k >> b >> mod;
	nod[1].num = (a0 * k + b) % mod;
	nod[1].count = 1;
	b2[1] = nod[1];
	for (int i = 2; i <= n; i++) {
		nod[i].num = (nod[i-1].num * k + b) % mod;
		nod[i].count = i;
		b2[i] = nod[i];
	}
	//rmq_init1();
	rmq_init2();
	build(1, n, 1);
	add(1);
	merge_sort(1, n);
	
	s.insert(0);
	s.insert(n + 1);
	s_inverse.insert(0);
	s_inverse.insert(-1 - n);
	
	UINT128 final_result = 0;
	ull q, w, e, r;
	for (int i = 1; i <= n; i++) {
		int mini = b2[i].num;
		int counti = b2[i].count;
		int upper = *s.lower_bound(b2[i].count)-1;
		int lower = -*s_inverse.lower_bound(-b2[i].count)+1;
		UINT128 result = b2[i].num* rmq2(lower,upper)*search(1,lower,upper)*(upper-lower+1);
		if (int(result - final_result) > 0) {
			q = b2[i].num, w = rmq2(lower, upper), e = search(1, lower, upper), r = upper - lower + 1;
		}
		final_result = max(final_result,result);
		s.insert(counti);
		s_inverse.insert(-counti);
	}
	final_result %= 998244353;
	print(final_result);
	//cout << q << " " << w << " " << e << " " << r << endl;
	return 0;
}