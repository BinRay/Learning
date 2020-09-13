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
    bool isSymmetric(TreeNode* root) {
        if (!root){
            return true;
        }
        return isEqual( root -> left, root -> right);
    }
    
    // 这个函数叫isMirror更合理
    // 条件顺序，先判断两个条件都是NULL，在判断其中一个是NULL，写起来更加简洁
    bool isEqual( TreeNode* sub_tree1, TreeNode* sub_tree2 ){
        // 有且仅有一棵树为空时，返回false
        if ( ( sub_tree1 || sub_tree2 ) && !( sub_tree1 && sub_tree2 ) ){
            return false;
        }
        
        // 都为空时，返回true
        if ( !sub_tree1 && !sub_tree2 ){
            return true;
        }
        
        // 两边都不为空
        return ( sub_tree1 -> val == sub_tree2 -> val ) ? (isEqual( sub_tree1->left, sub_tree2->right ) && isEqual( sub_tree1->right, sub_tree2->left )) : false;
        
    }
};