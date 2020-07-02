class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        // 构建邻接表
        vector<unordered_set<int> > adjacency_graph( n, unordered_set<int>() );
        for ( auto edge: graph ){
            adjacency_graph[edge[0]].insert(edge[1]);
        }

        // 访问状态集合
        unordered_set<int> visited;

        // DFS
        return dfs( adjacency_graph, start, target, visited );
    }

    bool dfs( vector<unordered_set<int> > &adjacency_graph, int cur, int target, unordered_set<int> &visited ){

        if ( cur == target ){
            return true;
        }

        visited.insert( cur );
        for ( auto neighbor: adjacency_graph[cur] ){
            if ( visited.count(neighbor) == 0 ){
                if ( dfs( adjacency_graph, neighbor, target, visited) == true ){
                    return true;
                }
            }
        }

        return false;
    }

};