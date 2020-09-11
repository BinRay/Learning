/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 交叉点是在遍历两个链表时，第一个出现两次的点，所以利用set记录（空间O(n)）
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        while ( headA || headB ){
            if ( headA ) {
                if ( s.count( headA ) > 0 ) {
                    return headA;
                }
                s.insert( headA );
                headA = headA -> next;
            } 
            
            if ( headB ) {
                if ( s.count ( headB ) > 0 ) {
                    return headB;
                }
                s.insert( headB );
                headB = headB -> next;
            } 
                
        }
        return NULL;
    }
};