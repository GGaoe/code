#include <iostream>
using namespace std;
struct node {
	int num;
	struct node* next;
};
int n1,n2;
node* head = NULL;
node* head1 = NULL;
node* head2 = NULL;
node* createlist() {
	 cin >> n1;
	for (int i = 1; i <= n1; i++) {
		node* p = new node;
		int a; cin >> a;
		p->num = a;
		if (head == NULL) {
			head = p; p->next = NULL;
		}
		else {
			node* w = head;
			while (w->next != NULL) {
				w = w->next;
			}w->next = p;
			p->next = NULL;
		}
	}
	 cin >> n2;
	 for (int i = 1; i <= n2; i++) {
		 node* p1 = new node;
		 int a; cin >> a;
		 p1->num = a;
		 if (head1 == NULL) {
			 head1 = p1; p1->next = NULL;
		 }
		 else {
			 node* w = head1;//²åµ½Î²²¿
			 while (w->next != NULL) {
				 w = w->next;
			 }w->next = p1;
			 p1->next = NULL;
		 }
	 }return 0;
}

node* union1() {
	node* w = head;
	node* q = head1;
	node* y = head2;
	if (w->num >= q->num) {
		node* p = new node;
		p->num = q->num;
		head2 = p; p->next = NULL;
		q = q->next;
		y = p;
	}
	else {
		node* p = new node;
		p->num = w->num;
		head2 = p; p->next = NULL;
		w = w->next;
		y = p;
	}

	for (int i = 2; i <= n1 + n2; i++) {
		if (w != NULL && q != NULL) {
			if (w->num >= q->num) {
				node* p = new node;
				p->num = q->num;
				q = q->next;
				y->next = p;
				p->next = NULL;
				y = p;
			}
			else {
				node* p = new node;
				p->num = w->num;
				w = w->next;
				y->next = p;
				p->next = NULL;
				y = p;
			}
		}
		else {
			if (w == NULL) {
				node* p = new node;
				p->num = q->num;
				q =q->next;
				y->next = p;
				p->next = NULL;
				y = p;
			}
			else if (q == NULL) {
				node* p = new node;
				p->num = w->num;
				w = w->next;
				y->next = p;
				p->next = NULL;
				y = p;
			}
		}
	}return 0;
}

int main() {
	createlist();
	union1();
	node* p = head2;
	for (int i = 1; i <= n1 + n2; i++) {
		cout << p->num;
		if (i != n1 + n2) {
			cout << " ";
		}
		p = p->next;
	}cout << endl;
	int c; cin >> c;
	node* q = head2;
	for (int i = 1; i <= n1 + n2 - c; i++) {
		q = q->next;
	}cout << q->num;
	return 0;
}