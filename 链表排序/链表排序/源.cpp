#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

//---------------------edit your code here--------------------

Node* sort_list(Node* head) {
    int len = 0;
    Node* u = head;
    while (u->next != NULL) {
        len += 1;
        u = u->next;
    }
    for (int i = 1; i <= len+1; i++) {
        Node* p = head;
        if (p->val < p->next->val) {
                Node* q = p->next;
                p->next = q->next;
                q->next = p;
                head=q;
        }
        Node* q = head;
        while (q->next->next != NULL) {
            if (q->next->val < q->next->next->val) {
                Node* u = q->next;
                Node* t = q->next->next;
                u->next = t->next;
                t->next = u;
                q->next = t;
            }
            else q = q->next;
        }
       
    } return head;
}

//------------------------------------------------------------


Node* example() {
    /*
    n1 -> n2 -> n3 -> n4
    */
    Node* array = (Node*)malloc(4 * sizeof(Node));
    Node* n1, * n2, * n3, * n4;
    n1 = &array[0];
    n2 = &array[1];
    n3 = &array[2];
    n4 = &array[3];
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = nullptr;
    n1->val = 4;
    n2->val = 1;
    n3->val = 5;
    n4->val = 2;
    return n1;
}



Node* test();

int main()
{
    Node* head = test();
    // Uncomment the following to get sample input
    //Node* head = example();

    long int base = (long int)head;
    head = sort_list(head);
    while (head != nullptr) {
        cout << ((long int)head) - base << " " << head->val << endl;
        head = head->next;
    }
    free(head);
    return 0;
}


Node* test() {
    unsigned char* p = (unsigned char*)malloc(0x1000full - 15);
    for (auto i = 0; i < 0x123full - 15; i++) {
        *(p + i) = 0;
    }
    void* ret, * cur = nullptr;
    int x, y;
    cin >> x >> y;
    cur = p + x * ((0x1full + 1) >> 1);
    *(int*)cur = y;
    ret = cur;
    while (!cin.eof()) {
        cin >> x >> y;
        *(unsigned char**)((unsigned char*)cur + (0x4full - 10 >> 3)) = p + x * ((0x1full + 1) >> 1);
        cur = *(unsigned char**)((unsigned char*)cur + (0x3full + 1 >> 3));
        *(int*)cur = y;
    }
    return (Node*)ret;
}