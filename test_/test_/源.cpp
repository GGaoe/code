#include <iostream>
using namespace std;

struct Node{
	int content;
	struct Node *next;
};//定义节点 

Node *head = NULL;

Node *CreateList() {
	Node *head = NULL;

	Node* p = new Node;
	int a; cin >> a;
	p->content = a;
	
	//插入链表头部
	int n; cin >> n;
	while(n!=-1){
		if (head == NULL) {//表头指针为空
			head = p;
			p->next = NULL;
		}
		else {//新节点插在表头
			p->next = head;//新节点的下一个节点为原先第一个节点
			head = p;//表头指针指向新节点
		}
	}

	//插入链表尾部
	Node* w = head;
	while (w->next != NULL) {
		w = w->next;
		w->next = p;
		w->next = NULL;

	}

	//插入第i个节点后面
	Node* q = head;
	int j = 1;
	int i; cin >> i;
	while (j < i && q->next != NULL) {
		q = q->next;
		j++;
	}
	if (j == i) {
		p->next = q->next;
		q->next = p;
	}
	else cout << NULL;
	//依次插入节点，从而建立链表
	return head;
}

void OutputList(Node* head) {
	for (Node* p = head; p != NULL; p->next) {
		cout << p->content;
	}
}

void DeleteList(Node* head) {
	while (head) {
		Node* current = head;
		head = head->next;
		//delete current;
		free(current);
	}
}

void sort(Node* h) {
	if (h == NULL || h->next == NULL)return;
	for (Node* p1 = h; p1->next != NULL; p1 = p1->next) {
		Node* p_min = p1;
		for (Node* p2 = p1->next; p2 != NULL; p2 = p2->next) {
			if (p2->content < p_min->content)p_min = p2;
			if (p_min != p1) {
				int temp = p1->content;
				p1->content = p_min->content;
				p_min->content = temp;
			}
		}
	}
}
int main() {
	Node *head = CreateList();
	//针对链表的具体操作
	OutputList(head);
	DeleteList(head);
	return 0;
}