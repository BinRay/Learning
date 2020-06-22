/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 二叉树层序遍历
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if ( root == NULL ){
            return v;
        }
        
        vector<TreeNode*> v1;
        v1.push_back( root );
        
        vector<int> v_val1;
        v_val1.push_back( root->val );
        v.push_back( v_val1 );
        
        
        while ( !v1.empty() ){
            vector<TreeNode*> v2;
            vector<int> v_val2;
            
            for ( vector<TreeNode*>::iterator it = v1.begin(); it != v1.end(); it++ ){
                if ( (*it)->left != NULL ){
                    v2.push_back((*it)->left);
                    v_val2.push_back((*it)->left->val);
                }
                if ( (*it)->right != NULL ){
                    v2.push_back((*it)->right);
                    v_val2.push_back((*it)->right->val);
                }
            }
            
            if ( !v_val2.empty() ){
                v.push_back( v_val2 );    
            }
            
            v1.swap(v2);
        }
        return v;
    }
};