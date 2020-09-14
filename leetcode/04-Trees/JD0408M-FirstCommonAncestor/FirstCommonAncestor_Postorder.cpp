/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
条件1：p或q在左子树中
条件2：p或q在右子树中
条件3：当前节点为p或q

1. 以上条件只需满足其中两个即可。
2. 第一次满足时是首个公共祖先。
3. 先序、中序、后序对本题来说不重要，但是这个解法是一定会遍历一遍，所以时间复杂度有点高。
4. 前提条件是各节点值不相同。
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* ancestor = NULL;
        postorder_dfs( root, p, q, ancestor );
        return ancestor;
        
    }
    
    bool postorder_dfs( TreeNode* &cur, TreeNode* &p, TreeNode* &q, TreeNode* &ancestor ){
        
        if ( cur == NULL ){
            return false;
        }
        
        
        bool check_left = postorder_dfs( cur -> left, p, q, ancestor );
        bool check_right = postorder_dfs( cur -> right, p, q, ancestor );
        bool check_cur = ( cur == p || cur == q );
        
        if ( !ancestor ){
            // 3个条件有2个满足，则代表当前节点为公共祖先（前提所有节点值不相同）
            if (( check_left + check_right + check_cur ) >= 2 )  {
                ancestor = cur;
                return true;
            }
        }
        
        return check_cur || check_left || check_right;
       
    }
};