/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 移出重复节点
// (68ms, 60.44%) (16.9MB, 100%)
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        // 1. 记录法，使用unordered_set记录已出现过的节点
        // 2. 相较于set，存取用时更少，但是空间一般需要更多
        if ( head == NULL || head->next == NULL ){
            return head;
        }
        unordered_set<int> s = { head -> val };
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