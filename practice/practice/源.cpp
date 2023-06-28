#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
};
Node* head = NULL;
Node* Setlist() {
	Node* a1 = new Node;
	int a2; cin >> a2;
	a1->val = a2;
	if (head == NULL) {
		head = a1;
		a1->next = NULL;
	}
	else {
		Node* y = head;
		while (y->next != NULL) {
			y = y->next;
		}
		y->next = a1;
		a1->next = NULL;
	}
	return head;
}

Node* sort(int len) {
	for (int i = 1; i <= len + 1; i++) {
		Node* p = head;
		if (p->next->val > p->val) {
			Node* q = p->next;
			p->next = q	->next;
			q->next = p;
			head = q;
		}
		Node* w = head;
			while (w->next->next != NULL) {
				//cout << 1;
				if (w->next->val < w->next->next->val) {
					Node* q = w->next;
					Node* t = w->next->next;
					q->next = t->next;
					t->next = q;
					w->next = t;
				}
				else { w = w->next; }
			}

	}

	return head;
}

Node* free() {
	Node* p = head;
	while (p->next != NULL) {
		Node* q = p;
		if (p->next != NULL) {
			p = p->next;
		}
		delete q;
	}

	return head;

}
int main() {
	int len; cin >> len;
	for (int i = 1; i <= len; i++) {
		Setlist();
	}
	sort(len);
	Node* p = head;
	while (p != NULL) {
		cout << p->val << endl;
		p = p->next;
	}
	return 0;
}