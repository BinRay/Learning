/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 队列中使用分界符分离每层
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if ( root == NULL ){
            return v;
        }
        
        queue<TreeNode*> q;
        TreeNode* dummy = new TreeNode(-99);
        q.push(root);
        q.push(dummy);
        
        vector<int> cur_v;
        TreeNode* cur_ptr;
        
        while ( !q.empty() ){
            cur_ptr = q.front();
            q.pop();
            if ( cur_ptr == dummy ){
                v.push_back( cur_v );
                if ( q.empty() ){
                    break;
                } else {
                    q.push( dummy );
                    vector<int> v_temp;
                    cur_v.swap( v_temp );
                    continue;
                }
            }
            
            if ( cur_ptr -> left != NULL ){
                q.push( cur_ptr -> left );
            }
            if ( cur_ptr -> right != NULL ){
                q.push( cur_ptr -> right );
            }
            
            cur_v.push_back( cur_ptr -> val );
        }
        
        return v;
    }
};