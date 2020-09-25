/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
#include <iostream>
#include "ConstructTree.h"

using namespace std;

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;    // 众数结果集
        int max_count = 0; // 存储众数的频率
        int prev;           // 记录前驱节点
        int prev_count;     // 记录前驱基点的个数
        
        // 中序遍历
        dfs( root, ans, max_count, prev, prev_count );
        
        return ans;
    }
    
    void dfs( TreeNode* node, vector<int> & ans, int & max_count, int & prev, int & prev_count ){
        if ( !node ){
            return;
        }
        
        dfs( node -> left, ans, max_count, prev, prev_count );
        
        // 不为空表示不是第一个元素，存在前驱元素prev
        if ( !ans.empty() ){
            int cur = node -> val;
            if ( cur == prev ){
                prev_count++;
                if ( prev_count == max_count ){
                    ans.emplace_back( cur );
                } else if( prev_count > max_count ) {
                    max_count = prev_count;
                    if ( ( ans.back() != prev ) || ( ans.size() != 1 ) ){
                        ans.clear();
                        ans.emplace_back( cur );
                    }
                }
            } else {
                prev_count = 1;
                prev = cur;
                
                if ( prev_count == max_count ){
                    ans.emplace_back( cur );
                }
            }
        } else {
            prev = node -> val;
            prev_count = 1;
            max_count = 1;
            ans.emplace_back( prev );
        }
        
        dfs( node -> right, ans, max_count, prev, prev_count );
    }
};

int main( int argc, char* argv[] ){
    vector<int> v = { 1, 1, 2, INT_MIN, INT_MIN,INT_MIN,2,INT_MIN,3,INT_MIN,3 };
    Solution s;
    TreeNode* root = construct_tree( v );
    s.findMode( root );
}