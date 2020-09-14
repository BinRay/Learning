/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 返回到数第k个节点
// ( 0ms, 100% ) ( 10.4MB, 100% )
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        // 1. 双指针，k就是两个前后指针之间的距离
        // 2. 两个指针以相同速度移动，直到前一直指针到达链表末尾
        
        ListNode *p = head;
        ListNode *q = head;
        for ( int i = 0; i < k; i ++ ){
            q = q -> next;
        }
        
        while ( q != NULL ){
            p = p -> next;
            q = q -> next;
        }
        
        return p->val;
    }
    
};