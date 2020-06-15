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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = l1;
        ListNode* last1 = l1;

        int carry_over = 0;
        while ( (l1 != NULL || l2 != NULL) || carry_over != 0 ){
                int temp1 = ( l1 == NULL ? 0 : l1 -> val );
                int temp2 = ( l2 == NULL ? 0 : l2 -> val );
                int temp = temp1 + temp2 + carry_over;
                carry_over = 0;
                if ( temp >= 10 ){
                    temp = temp - 10;
                    carry_over = 1;
                }
                if ( l1 == NULL ){
                    l1 = new ListNode( temp );
                    last1 -> next = l1;
                } else {
                    l1 -> val = temp;
                }
            l1 ? last1 = l1, l1 = l1 -> next : l1;
            l2 ? l2 = l2 -> next: l2;
        }
        return sum;
    }
};