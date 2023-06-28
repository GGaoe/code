#include <iostream>
using namespace std;
struct node {
	int num;
	struct node *next;
};

node* head = NULL;
node* head1 = NULL;
node* list() {
	node* p = new node;
	int a; cin >> a;
	p->num = a;
	node* p1 = new node;
	p1->num = a;
	if (head == NULL) {//插到头部
		head = p;
		p->next = NULL;
	}
	else {
		p->next = head;
		head = p;
	}
	if (head1 == NULL) {
		head1 = p1;
		p1->next = NULL;
	}
	else {
		node* w = head1;//插到尾部
		while (w->next != NULL) {
			w = w->next;
		}w->next = p1;
		p1->next = NULL;
	}
	return 0;
}

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		list();
	}
	for (node* q = head; q!= NULL; q = q->next) {
		cout << q->num;
	    if(q->next!=NULL)cout<<" ";
	}cout << endl;
	bool flag = 1;
	node* o = head;
	node* t = head1;
	for (int i = 1; i <= n; i++) {
		
		if (o->num != t->num)flag = 0;
		o = o->next;
		t = t->next;
	}
	if (flag)cout << "true";
	else cout << "false";
	return 0;
}