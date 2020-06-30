// Example program
#include <iostream>
#include <string>

// 执行用时：52 ms, 在所有 C++ 提交中击败了69.07%的用户
// 内存消耗：71.2 MB, 在所有 C++ 提交中击败了100.00%的用户

//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int tmp = 0;
        
        ListNode* sum = NULL;
        ListNode* cur = NULL;
        ListNode* last = NULL;
        
        while ( l1 || l2) {
            if ( l1 && l2 ){
                tmp = l1 -> val + l2 -> val + carry;
            } else {
                tmp = l1 ? l1 -> val : l2 -> val;
                tmp += carry;
            }
            
            l1 = l1 ? l1 -> next : l1;
            l2 = l2 ? l2 -> next : l2;
            
            carry = tmp >= 10 ? 1 : 0;
            tmp = tmp >= 10 ? tmp - 10 : tmp;
            
            cur = new ListNode(tmp);
            sum = sum ? sum : cur;
            if ( last ){
                last -> next = cur;
                last = cur;
            } else {
                last = cur;
            }
        }
                
        if ( carry > 0 ){
            last -> next = new ListNode(1);
        }
        
        return sum;
    
    }
};
int main()
{
    ListNode a(2);
    ListNode b(4);
    ListNode c(3);
    ListNode d(5);
    ListNode e(6);
    ListNode f(4);
    
    a.next = &b;
    b.next = &c;
    
    d.next = &e;
    e.next = &f;
    
    Solution s;
    s.addTwoNumbers( &a, &d );
    
}
