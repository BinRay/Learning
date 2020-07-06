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
    bool isValidBST(TreeNode* root) {
        
        return check_bst( root, LONG_MIN, LONG_MAX );        
        
    }
    
    // 利用特性：左子树所有节点值小于当前节点值，当前节点值小于所有右子树节点值
    // 吐槽下这道题的测试用例，有点和算法无关了，挺不合理的：
    // 1. [1,1 ]的预期是false，好多资料说的都是可以带上等号的，所以放这个模糊的测试用例真的没必要。
    // 2. int边界：倘若为了解决1的问题把等号去掉，结果给一个C++的int边界测试用例，因为去掉了等号，所以初始的INT_MAX这个哨兵就不好用了。这两个测试用例合在一起确实有点无语了，感觉脱离了这道题的训练目的。
    bool check_bst( TreeNode* root, long min, long max ){
        if ( !root ){
            return true;
        }
        
        if ( !( root -> val < max && root -> val > min )){
            return false;
        }
        
        if ( !check_bst( root -> left , min, root -> val ) ){
            return false;
        }
        
        if ( !check_bst( root -> right , root -> val, max ) ) {
            return false;
        }
        
        return true;
    }
};