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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        // 回溯
        vector<vector<int>> ans;
        vector<int> track;
        
        if ( !root ) return ans;
        
        bt( root, ans, track, 0, sum );
        
        return ans;
        
    }
    
    void bt( TreeNode* node, vector<vector<int>> & ans, vector<int> & track, int path_sum, const int sum ){
            track.emplace_back( node -> val );
            path_sum += node-> val;
            
            if ( node -> left || node -> right ){
                if ( node -> left ){
                    bt ( node -> left, ans, track, path_sum, sum );
                }
                
                if ( node -> right ){
                    bt ( node -> right, ans, track, path_sum, sum );
                }
            } else {    // 叶子节点
                if ( path_sum == sum ){
                    ans.emplace_back( track );
                }
            }
            
            track.pop_back();
            
        }
    
};