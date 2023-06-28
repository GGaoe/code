#include <cstdio>
#include <cmath>
using namespace std;
int main() {
	int c, v;
	scanf_s("%d%d", &c, &v);
	int a = ceil(1.0 * c / v) + 10;//到学校所用时间
	printf("%d\n", a);
	int b = 32 * 60 - a;//从昨天到当天共剩余时间
	printf("%d\n", b);
	int e = (b / 60) % 24;//小时
	printf("%d\n", e);
	int d = b %60;//分钟
	printf("%d\n", d);
	printf("%02d:%02d\n", e, d);
	return 0;
}