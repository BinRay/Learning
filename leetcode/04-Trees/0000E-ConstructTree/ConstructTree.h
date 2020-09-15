//
// Created by lbinr on 2020/9/15.
//

#ifndef CONSTRUCTTREE_CONSTRUCTTREE_H
#define CONSTRUCTTREE_CONSTRUCTTREE_H
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* construct_tree( vector<int> & v ){
    
    vector<int>::iterator it = v.begin();
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode( *it++ );
    q.push( root );

    while ( !q.empty() && it != v.end() ){  // 下一层有空位置，并且有待插入的元素
        int count = q.size();
        for ( int i = 0; i < count; i++ ){
            TreeNode* front = q.front();
            q.pop();

            int val = *it++;
            if ( val != INT_MIN ){
                front -> left = new TreeNode( val );
                q.push( front -> left );
            }
            if ( it == v.end() ) break;

            val = *it++;
            if ( val != INT_MIN ){
                front -> right = new TreeNode( val );
                q.push( front -> right );
            }
            if ( it == v.end() ) break;
        }
    }
    return root;
}
#endif //CONSTRUCTTREE_CONSTRUCTTREE_H
