/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 1. 深度递归时，除了计算高度外，还可以返回平衡性信息，本解以-1表示

// 执行用时：20 ms, 在所有 C++ 提交中击败了79.68%的用户
// 内存消耗：21.8 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
public:
    bool isBalanced(TreeNode* root) {
            
        return check_height(root) == -1 ? false : true;
        
    }
    
    // 如果非平衡，返回-1
    int check_height( TreeNode* node ){
        if ( node == NULL ){
            return 0;
        }
        
        int left_height = check_height( node -> left );
        int right_height = check_height( node -> right );
        
        if ( left_height == -1 || right_height == -1 ){
            return -1;
        }
        
        if ( abs( left_height - right_height ) > 1 ){
            return -1;
        }
        
        return max( left_height, right_height ) + 1;
    }
};