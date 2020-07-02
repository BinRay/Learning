// 执行用时：840 ms, 在所有 C++ 提交中击败了9.41%的用户
// 内存消耗：91.2 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        // 构建邻接表
        vector<vector<int> > adjacency_graph;
        for ( int i = 0; i < n; i++ ){
            vector<int> v;
            adjacency_graph.push_back( v );
        }
        for ( auto edge: graph ){
            adjacency_graph[edge[0]].push_back(edge[1]);
        }

        // BFS
        queue<int> q;
        set<int> visited;

        q.push ( start );
        visited.insert( start );

        while ( !q.empty() ){
            int cur = q.front();
            q.pop();

            if ( cur == target ){
                return true;
            }

            for ( auto cur_neighbor : adjacency_graph[cur] ){
                if ( visited.count(cur_neighbor) == 0 ){
                    q.push( cur_neighbor );
                    visited.insert( cur_neighbor );
                }
            }
        }

        return false;
    }
};
