class UF {
    
private:
    // 树的重量,在合并时依此将小树合并到大树上
    int* size;
    
    // 使用数组表示树结构
    int* parent;
    
    // 连通分量的个数
    int count;
    
public:
    UF( int n ){
        count = n;
        size = new int[n];
        parent = new int[n];
        
        // 初始化各连通分量
        for ( int i = 0; i < n; i++ ){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    ~UF(){
        delete []size;
        delete []parent;
    }
    
    // 将p与q合并
    void u( int p, int q ){
        int root_p = find( p );
        int root_q = find( q );
        
        if ( size[root_p] > size[root_q] ){   // 将q挂到p上
            parent[root_q] = root_p;
            size[root_p] += size[root_q];
        } else {                    // 将p挂到q上
            parent[root_p] = root_q;
            size[root_q] += root_p;
        }
        
        count--;
    }
    
    // 检验是否连通
    bool connected( int p, int q ){
        int root_p = find( p );
        int root_q = find( q );
        
        // 检测根节点是否相同
        return root_p == root_q;
    }
    
    // 查找根节点
    int find( int x ){
        while( parent[x] != x ){
            // 路径压缩
            parent[x] = parent[parent[x]];
            
            // 顺着路径向上
            x = parent[x];
        }
        
        return x;
    }
    
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if ( board.empty() || board[0].empty() ){
            return;
        }
        
        int m = board.size();
        int n = board[0].size();
        
        UF uf( m * n + 1 );
        
        int dummy = m * n;  // 边界的O或与边界O相连的O的公共根节点
        
        // 将首列和末列的O与dummy连通
        for ( int i = 0; i < m; i++ ){
            if ( board[i][0] == 'O' ){
                uf.u( i * n , dummy );    
            }
            if ( board[i][n-1] == 'O' ){
                uf.u( (i + 1) * n - 1, dummy );
            }
        }
        
        // 将首行与末行的O与dummy连通
        for ( int j = 0; j < n; j++ ){
            if ( board[0][j] == 'O' ){
                uf.u( j, dummy );
            }
            
            if ( board[m-1][j] == 'O' ){
                uf.u( (m-1)*n + j, dummy );
            }
        }
        
        // 方向数组，使用这个数组来计算某个点的上下左右邻点
        vector<vector<int>> pos = {{1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        
        // 遍历除边界外的点，将O与其相邻的O连通
        for ( int i = 1; i < m - 1; i++ ){
            for ( int j = 1; j < n - 1; j++ ){
                if ( board[i][j] == 'O' ){
                    for ( int k = 0; k < 4; k++ ){
                        int x = i + pos[k][0];
                        int y = j + pos[k][1];
                        if ( board[x][y] == 'O' ){
                            uf.u( x * n + y, i * n + j );
                        }
                    }
                }
            }
        }
        
        // 将不在dummy下的O替换成X
        for ( int i = 1; i < m - 1; i++ ){
            for ( int j = 1; j < n - 1; j++ ){
                if ( !uf.connected( dummy, i * n + j ) ){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};