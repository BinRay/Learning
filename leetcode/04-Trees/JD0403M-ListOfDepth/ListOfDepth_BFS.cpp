/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 执行用时：4 ms, 在所有 C++ 提交中击败了70.14%的用户
// 内存消耗：8.4 MB, 在所有 C++ 提交中击败了100.00%的用户


// 1. 核心思想是BFS
// 2. 使用NULL作为每层的分界符(也可以记录每层的size而避免使用分界符)
// 3. 需要维护好每层链表的头结点与尾节点的位置
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        
        if ( tree == NULL ){
            return vector<ListNode*>();
        }

        // 一定要初始化为NULL
        ListNode* head = NULL;
        ListNode* last = NULL;
        
        vector<ListNode*> v;
        
        queue<TreeNode*> q;
        q.push(tree);
        
        // 以NULL作为每层的分界符
        q.push(NULL);
        
        // 仅有NULL是退出循环
        while ( q.size() > 1 ){
            
            TreeNode* front = q.front();
           
            q.pop();
            if ( front == NULL ){
                q.push( front );
                v.push_back( head );
                head = NULL;
                last = NULL;
            } else {
                ListNode* n = new ListNode( front->val );
                if ( last ){
                    last -> next = n;
                    last = last -> next;
                } else {
                    last = n;
                    head = n;
                }
                if ( front -> left != NULL ){
                    q.push( front -> left );
                }
                if ( front -> right != NULL ){
                    q.push( front -> right );
                }
            }
        }
        
        v.push_back(head);
        return v;
    }
};
