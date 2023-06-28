#include <iostream>
using namespace std;
void swap(int **a,int **b) {
	int* t;
	t = *a; *a = *b; *b = t; 
	return;
}


int main() {
	int a = 0; int b = 1;
	int* q = &a;
	int* t = &b;
	swap(&q, &t);
	cout << *q << *t << endl;
	return 0;
}