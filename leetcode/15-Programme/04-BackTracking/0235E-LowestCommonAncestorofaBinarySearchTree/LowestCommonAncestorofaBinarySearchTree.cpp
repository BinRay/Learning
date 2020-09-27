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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 回溯算法
        vector<TreeNode*> track;
        vector<vector<TreeNode*>> tracks;   // p和q的路径
        
        bt( root, p, q, tracks, track );
        
        
        // 找分叉点
        TreeNode* ans;
        
        int len = tracks[0].size() > tracks[1].size() ? tracks[1].size() : tracks[0].size();
        
        for ( int i = 0; i < len ; i++ ){
            if ( tracks[0][i] != tracks[1][i] ){
                break;
            } else {
                ans = tracks[0][i];
            }
        }
        
        return ans;
        
    }
    
    // 返回 true 表示已经找到了两个子节点
    void bt ( TreeNode* node, TreeNode* p, TreeNode* q, vector<vector<TreeNode*>> & tracks, vector<TreeNode*> & track ){
        
        if ( tracks.size() == 2 ) return;
        if ( !node ) return;
        
        track.emplace_back( node );
        
        if ( node == p ){
            tracks.emplace_back( track );
        }
        
        if ( node == q ){
            tracks.emplace_back( track );;
        }
        
        bt ( node -> left, p, q, tracks, track );
        bt ( node -> right, p, q, tracks, track );
        
        track.pop_back();
        
    }
};