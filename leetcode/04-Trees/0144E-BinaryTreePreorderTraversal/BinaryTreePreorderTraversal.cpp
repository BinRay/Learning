/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <map>
#include <iostream>
#include <stack>
#include "../0000E-ConstructTree/ConstructTree.h"

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // 使用栈来储存节点
        // 使用map来存储是否处理过节点，值1是处理左节点，值2代表处理过右节点，可以从栈中删除本节点。
        
        stack<TreeNode*> s;
        vector<int> ans;
        
        if ( !root ) return ans;
        
        ans.push_back( root -> val );
        s.push( root );
        
        map<TreeNode*, int> m;
        
        while ( !s.empty() ){
            TreeNode* top = s.top();
            if ( m.count(top) && m[top] == 2 ){ // 已经处理过左右子树，可以删除
                s.pop();
            } else if ( m.count(top) && m[top] == 1) { // 已经处理过左子树，该处理右子树
                if ( top -> right ){
                    ans.push_back( top -> right -> val );
                    s.push( top -> right );
                }
                m[top] = 2;
            } else if ( ( m.count(top) == 0) || m[top] == 0 ){  // 未处理左右子树，先处理左子树
                if ( top -> left ){
                    ans.push_back( top -> left -> val );
                    s.push( top -> left );
                }
                m[top] = 1;
            }
        }
        return ans;
    }
};

int main( int argc, char* argv[] ){
    
    Solution s;
    vector<int> v =  { 1, INT_MIN,2 ,3 };
    TreeNode* root = construct_tree( v );
    s.preorderTraversal( root );

}