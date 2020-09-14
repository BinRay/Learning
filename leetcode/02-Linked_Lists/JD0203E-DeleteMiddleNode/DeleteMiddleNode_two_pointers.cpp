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
    void deleteNode(ListNode* node) {
        // 1. 双指针，前一指针的移动速度是后一指针的2倍
        // 2. 本以为是正中间的节点……原来是中间某个节点，本解法是正中间的解法
        
        ListNode* p = node;
        ListNode* q = node -> next;
        
        ListNode* last_node = node;
        
        while ( 1 ){
            
            if ( q -> next != NULL ){
                last_node = p;
                p = p -> next;
                q = q -> next;
            } else {
                break;
            }
            
            if ( q -> next != NULL ){
                q = q -> next;
            } else {
                break;
            }
        }
        
        last_node -> next = p -> next;
        
    }
};