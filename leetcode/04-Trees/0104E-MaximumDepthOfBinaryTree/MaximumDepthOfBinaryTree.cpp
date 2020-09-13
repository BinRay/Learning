/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 执行用时：8 ms, 在所有 C++ 提交中击败了91.94%的用户
// 内存消耗：17 MB, 在所有 C++ 提交中击败了61.58%的用户

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if ( !root ){
            return 0;
        }
        
        int left_depth = maxDepth( root -> left );
        int right_depth = maxDepth( root -> right );
        
        return max( left_depth, right_depth ) + 1;
    }
};