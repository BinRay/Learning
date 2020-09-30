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
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if ( !root ) {
            root = new TreeNode( val );
            return root;
        }

        // 深度递归找到插入位置
        dfs( root, val, NULL, 0 );

        return root;
    }

    void dfs( TreeNode* node, int val, TreeNode* parent, int pos ){
        // 该节点是NULL，插入
        if ( !node ){
            if ( pos == 0 ){                            // 插入左边
                parent -> left = new TreeNode( val );
            } else {                                    // 插入右边
                parent -> right = new TreeNode( val );
            }
            return;
        }

        if ( val < node -> val ){
            dfs ( node -> left, val, node, 0 );
        } else {
            dfs ( node -> right, val, node, 1 );
        }

    }

};
