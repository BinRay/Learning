
/**
执行用时：36 ms, 在所有 C++ 提交中击败了29.52%的用户
内存消耗：19.9 MB, 在所有 C++ 提交中击败了100.00%的用户

贪心法
1. 从终点逆向移动到起点。
2. 每次递归都向上或向左，越界或有障碍物则返回false，直到起点。
3. 因为使用了栈，所以添加节点时是正向的。
4. 使用set记录已访问的节点，节省重复访问节点的时间。
*/

class Solution {
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        vector<vector<int>> path;
        if ( obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0 ) return path;
        
        set<vector<int> > marked;
        
        check_limited( obstacleGrid, obstacleGrid.size() - 1, obstacleGrid[0].size() - 1, path, marked );
        return path;
        
    }
    
    bool check_limited( const vector<vector<int>> &obstacleGrid, int row_num, int column_num, vector<vector<int>> &path, set<vector<int>> &marked ){
        cout << row_num << ", " << column_num << endl;
        
        // mark the point that has been accessed
        vector<int> point = { row_num, column_num };
        if ( marked.count( point ) > 0 ) return false;
        marked.insert( point );
        
        if ( row_num < 0  || column_num < 0 ) return false;     // out of bounds
        if ( obstacleGrid[row_num][column_num] ) return false;  // off limits    
       
        
        bool is_origin = ( row_num == 0 ) && ( column_num == 0 );
        
        if ( is_origin || check_limited( obstacleGrid, row_num-1, column_num, path, marked ) || check_limited( obstacleGrid, row_num, column_num-1, path, marked ) ){
            path.push_back( point );    
            return true;
        }
            
        return false;
        
        
    }
};