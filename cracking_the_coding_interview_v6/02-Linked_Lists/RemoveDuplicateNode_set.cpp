/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 移出重复节点
// (92ms, 30.42%) (17.1MB, 100%)
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        // 1. 记录法，使用set记录已出现过的节点
        if ( head == NULL || head->next == NULL ){
            return head;
        }
        set<int> s = { head -> val };
        ListNode *last_node = head;
        for ( ListNode *c = head -> next; c != NULL; c = c -> next ){
            if ( s.count(c->val) > 0 ){
                last_node -> next = c -> next;
            } else {
                s.insert( c -> val );
                last_node = c;
            }
        }   
        return head;
    }
};