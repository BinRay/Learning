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
    vector<double> averageOfLevels(TreeNode* root) {
        if ( !root ){
            return {};
        }
        
        queue<TreeNode*> q;
        q.push( root );
        vector<double> ans;
        
        while ( !q.empty() ){
            int count = q.size();
            double sum = 0;
            for ( int i = 0; i < count; i++ ){
                TreeNode* front_node = q.front();
                q.pop();
                if ( front_node -> left ){
                    q.push( front_node -> left );
                }
                if ( front_node -> right ){
                    q.push( front_node -> right );
                }
                
                sum += front_node -> val;
            }
            double avg = sum / count;
            ans.push_back( avg );
        }
        
        return ans;
        
    }
};