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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        // 利用栈模拟递归
        // 使用map记录该节点的子节点的访问情况
        
        unordered_map<TreeNode*, int> m;
        stack<TreeNode*> s;
        
        vector<int> ans;
        if ( !root ) return ans;
        
        s.push( root );
        
        while ( !s.empty() ){
            TreeNode* top_node = s.top();
            if ( m[top_node] == 0 ){ 
                
                // 压入右子节点，先压的后输出
                m[top_node] = 1;
                if ( top_node -> right ){
                    s.push( top_node -> right );
                }
                // 压入右子节点
                if ( top_node -> left ){
                    s.push( top_node -> left );    
                }
                
            } else {    // 左右子节点都已经处理过
                ans.emplace_back( top_node -> val );
                s.pop();    // 将最上面的节点弹出
            }
        }
        
        return ans;
        
    }
};