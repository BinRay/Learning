/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 1. 中序遍历逆过程：
//      1. 先右后左
//      2. 遍历过程中要记录上一个访问的节点

// 执行用时：52 ms, 在所有 C++ 提交中击败了20.22%的用户
// 内存消耗：23 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* last_node = NULL;
        if ( !dfs( root, p, last_node ) ){
            return NULL;
        } else {
            return last_node;
        }
    }
    
    bool dfs ( TreeNode* cur, TreeNode* &p, TreeNode* &last_node ){
        if ( cur == NULL ){
            return false;
        }
        
        if ( dfs( cur -> right, p, last_node )){
            return true;
        }
        if ( cur == p ){
            return true; 
        }
        last_node = cur;
        
        if ( dfs( cur -> left, p, last_node ) ){
            return true;
        }
        return false;
    }
};