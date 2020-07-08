/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 1. 判断t1与t2是否相同。
// 2. 递归判断t1各个子节点与t2是否完全相同。
// 另一种解法：中序遍历输出、判断t2是否为t1子串。
class Solution {
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        
        if ( !t1 && !t2 ){
            return true;
        } else if ( !t1 ){
            return false;
        } 
        
        return is_identical( t1, t2 ) ? true : ( checkSubTree( t1 -> left, t2 ) || checkSubTree( t1 -> right, t2 ) ); 
    }
    
    // 判断两棵子树是否完全相同
    bool is_identical ( TreeNode *t1, TreeNode* t2 ){
        if ( !t1 && !t2 ){
            return true;
        } else if ( !t1 || !t2 ){
            return false;
        } 
        
        return ( t1 -> val == t2 -> val ) && is_identical( t1 -> left, t2 -> left ) && is_identical( t1 -> right, t2 -> right );
    }
};