/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        // 1. 递归:重点在于找到前一节点与后一节点倒数索引的关系——相差1
        
        int target;
        is_kth( head, target, k );
        return target;
        
    }
    
    int is_kth( ListNode* node, int& target, int k ){
        if ( node == NULL ){
            return 0;
        }
        
        int index = is_kth ( node -> next, target, k ) + 1;
        if ( index == k ){
            target = node->val ;
        }
        
        return index;
    }
    
    
};