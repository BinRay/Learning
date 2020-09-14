/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 外层递归：遍历树种每个节点。
// 内层递归：对于1中任意一个节点，以此为起点，深度搜索计算路径之和是否为sum，根据比较结果自增count。
// 将所有节点的count值相加即得最终结果。

class Solution {
public:
    // 双递归
    int pathSum(TreeNode* root, int sum) {
        
        int count = 0;
        if ( !root ) return count;
        dfs( root, 0, sum, count );
        return count + pathSum( root->left, sum ) + pathSum( root->right, sum );
        
    }
    
    // 深度优先
    void dfs ( TreeNode* cur, int path_sum,  int sum, int &count ){
        if( !cur ){
            return;
        }
        
        path_sum += cur->val;
        if( path_sum == sum ){
            count++;
        }
        
        dfs( cur->left, path_sum, sum, count );
        dfs( cur->right, path_sum, sum, count );
    }
};