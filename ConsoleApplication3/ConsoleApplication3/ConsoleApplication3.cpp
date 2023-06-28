#include <stdio.h>

int main() {
	int i = 0;
	int j =++i+ ++i+ ++i;
	printf("j=%d\n", j);
	return 0;
}