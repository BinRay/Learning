// 1. node除了存储val之外，还要存储左子树的节点数（包括自身和重复值）
// 2. 插入节点时，如果在当前节点cur的左子树中，则需对left_size加1。
// 3. 计算秩时，如果在右节点，则需加上cur的left_size。
// 4. 插入与查询时间复杂度均为O(logN)

// 执行用时：44 ms, 在所有 C++ 提交中击败了96.49%的用户
// 内存消耗：13.9 MB, 在所有 C++ 提交中击败了100.00%的用户
class BSTNode {
    
public:
    
    BSTNode* left = NULL;
    BSTNode* right = NULL;
    int val = 0;
    int left_size = 1;

    BSTNode( int v ):val(v){}
    
};

class BST {
private:
    BSTNode* root;

public:
    BST(){
        root = NULL;
    }
    void insert( int x ){
        
        if ( !root ){
            root = new BSTNode( x );
            return;
        }
        
        BSTNode* cur = root;
        BSTNode* last = root;
        while ( 1 ){
            last = cur;
            if ( x < cur -> val ){
                cur -> left_size ++;
                cur = cur -> left;
                if ( !cur ){
                    cur = new BSTNode( x );
                    last -> left = cur;
                    return;
                }
            } else if ( x > cur -> val ){
                cur = cur -> right;
                if ( !cur ){
                    cur = new BSTNode( x );
                    last -> right = cur;
                    return;
                }
            } else {
                cur -> left_size ++;
                return;
            }
        }
        
        
    }
    
    int get_rank( int x ){
        int rank = 0;
        BSTNode *cur = root;
        
        while ( cur ){
            if ( x < (cur -> val) ){
                cur = cur -> left;
            } else if ( x > cur -> val ){
                rank += cur -> left_size;
                cur = cur -> right;
            } else {
                rank += cur -> left_size;
                return rank;
            }
        }
        return rank;
    }
};

class StreamRank {
public:
    StreamRank() {

    }
    
    void track(int x) {
        
        bst.insert( x );
        
    }
    
    int getRankOfNumber(int x) {
        
        return bst.get_rank( x );
        
    }
    
private:
   BST bst;
    
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */

作者：knightliu
链接：https://leetcode-cn.com/problems/rank-from-stream-lcci/solution/xi-bao-ti-jie-ri-ji-er-cha-sou-suo-shu-by-knightli/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。