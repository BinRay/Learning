/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 执行用时：32 ms, 在所有 C++ 提交中击败了66.01%的用户
// 内存消耗：24.5 MB, 在所有 C++ 提交中击败了100.00%的用户

// 1. 以数组中位数作为树根，并以此划分左右子树。
// 2. 递归对左右数组进行1操作。
// 3. 注意递归终止条件。
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if ( nums.size() == 0 ){
            return NULL;
        }
        
        return build_sub_tree( nums, 0, nums.size()-1 );
        
    }
    
    TreeNode* build_sub_tree( vector<int> &nums, int first, int last ){
        
        if ( first > last ){
            return NULL;
        }
        int mid = ( first + last ) / 2;
        
        TreeNode* root = new TreeNode( nums[mid] );
        root -> left = build_sub_tree( nums, first, mid-1 );
        root -> right = build_sub_tree( nums, mid+1, last);
        
        return root;
    }
};