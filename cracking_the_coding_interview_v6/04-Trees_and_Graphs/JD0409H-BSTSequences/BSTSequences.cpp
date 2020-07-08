/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 执行用时：104 ms, 在所有 C++ 提交中击败了19.13%的用户
// 内存消耗：52.7 MB, 在所有 C++ 提交中击败了100.00%的用户

// 特性：在同一棵子树下，在数组中父节点一定比子节点的位置靠前，但左右子节点位置无关。

// 递归：当前节点的序列集合是通过以下方式生成的：
    // 1. 取当前节点值作为prefix。
    // 2. 分别求出左、右子树的序列集合。
    // 3. 对于集合中的每一个排列，将prefix插入到头部组成新的排列。
    // 4. 3中生成的每个排列组成新的集合返回。
class Solution {
public:
    
    // 展开：将左子树与右子树编织，然后将当前节点插入所有编织后的头部。
    vector<vector<int>> BSTSequences(TreeNode* root) {
        
        if ( !root ){
            vector<int> sequence;
            vector<vector<int>> sequences = { sequence };
            return sequences;
        }
        
        vector<vector<int>> sequences;
        vector<int> prefix;
        prefix.push_back( root -> val );
        
        vector<vector<int>> left_sequences = BSTSequences( root -> left );
        vector<vector<int>> right_sequences = BSTSequences( root -> right );
        
        for ( auto left: left_sequences ){
            for ( auto right: right_sequences ){
                weave( left, right, prefix, sequences );
            }
        }
        
        return sequences;
    }
    
    
    
    
    // 编织：每次递归都会向最终的列表中插入1个（当left或right为空时多个）元素
    void weave( vector<int> left, vector<int> right, vector<int> prefix, vector<vector<int>> &v ){
        if ( left.empty() && right.empty() ){
            v.push_back( prefix );
        } else if ( left.empty() ){
            prefix.insert( prefix.end(), right.begin(), right.end() );
            right.clear();
            weave( left, right, prefix, v );
        } else if ( right.empty() ){
            prefix.insert( prefix.end(), left.begin(), left.end() );
            left.clear();
            weave( left, right, prefix, v );
        } else {
            
            // 先选取左序列的第一个节点
            prefix.push_back( left[0] );
            weave( vector<int>( left.begin()+1, left.end() ), right, prefix, v);
            
            // 再选取右序列的第一个节点
            prefix.pop_back();
            prefix.push_back( right[0] );
            weave( left, vector<int>( right.begin()+1, right.end() ), prefix, v);
            
        }
    }
};