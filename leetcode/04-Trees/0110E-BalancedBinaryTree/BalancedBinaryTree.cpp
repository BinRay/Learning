/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return height( root ) < 0 ? false : true;
    }
    
    // 返回值代表子树的高度，正常是正值，这里使用-1代表子树是不平衡的状态。
    int height( TreeNode* root ){
        if ( !root ){
            return 0;
        }
        
        int left_height = height( root -> left );
        if ( left_height == -1 ){
            return -1;
        }
        
        int right_height = height( root -> right );
        if ( right_height == -1 ){
            return -1;
        }
        
        if ( abs( left_height - right_height ) > 1 ){
            return -1;
        }
        
        return max( left_height, right_height ) + 1;
    }
};