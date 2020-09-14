#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // 1. 新建两个链表(实际只多建了两个哨兵，实际还是操作指针)
        // 2. 与x比较，分别插入before和after
        // 3. 将before和after连接
        // 附：另一种解法，遍历过程中将小于x的值插入头位置。
        ListNode* before = new ListNode(0);
        ListNode* after = new ListNode(0);

        ListNode* before_cur = before;
        ListNode* after_cur = after;

        for ( ListNode* p = head; p != NULL; p = p -> next ){
            if ( p -> val < x ){
                before_cur -> next = p;
                before_cur = p;
            } else {
                after_cur -> next = p;
                after_cur = p;
            }
        }

        before_cur -> next = after -> next;
        after_cur -> next = NULL;   // 注意：一定要把最后一个节点next置为空，否则测试遍历会有问题。

        head = before -> next;

        delete before;
        delete after;

        return head;
    }
};

int main( int argc, char** argv ){
    ListNode a(3);
    ListNode b(5);
    ListNode c(8);
    ListNode d(5);
    ListNode e(10);
    ListNode f(2);
    ListNode g(1);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;

    Solution s;
    ListNode* l = s.partition( &a, 5 );

    while ( l != NULL ){
        cout << l -> val << " ";
        l = l -> next;
    }


}