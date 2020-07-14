/**
 * 1. 判断选择点是否越界或者非原始色。
   2. 染色。
   3. 对上、下、左、右点执行1操作
 */

class Solution {
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if ( image.size() == 0 || image[0].size() == 0 ) return image;
        
        set<vector<int>> marked;
        int original_color = image[sr][sc];
        greedy( image, sr, sc, original_color, newColor, marked );
        return image;
    }
    
    void greedy( vector<vector<int>> &image, int sr, int sc, int original_color, int new_color, set<vector<int>> &marked ){
        if ( sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() ){
            return;
        }
        
        if ( marked.count( { sr, sc } ) ) return;
        marked.insert( { sr, sc } );
        
        if ( image[sr][sc] != original_color ) return;
        
        image[sr][sc] = new_color;
        greedy( image, sr-1, sc, original_color, new_color, marked );
        greedy( image, sr+1, sc, original_color, new_color, marked );
        greedy( image, sr, sc-1, original_color, new_color, marked );
        greedy( image, sr, sc+1, original_color, new_color, marked );
    }
};

