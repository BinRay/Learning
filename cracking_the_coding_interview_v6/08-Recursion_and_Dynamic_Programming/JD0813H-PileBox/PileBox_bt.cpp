#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 回溯法，大数据时超时
class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        // 暴力，大约n!

        sort( box.begin(), box.end(), width_bigger );

        int max_height = 0;
        for( int i = 0; i < box.size(); i++ ){
            max_height = max( max_height, box[i][2] + pileBox( box, i, i+1 ) );
        }

        return max_height;

    }

    int pileBox( vector<vector<int>> &box, int bottom,  int index ){
        if ( index == box.size() ) return 0;

        int max_height = 0;
        for ( int i = index; i < box.size(); i++ ){
            if ( box[i][0] < box[bottom][0] && box[i][1] < box[bottom][1] && box[i][2] < box[bottom][2]){
                max_height = max( max_height, box[i][2] + pileBox( box, i, i+1 ) );
            }
        }
        return max_height;
    }

    // 降序
    static bool width_bigger( const vector<int> &b1, const vector<int> &b2 ){
        return b1[0] > b2[0];
    }
};

int main(){
    Solution s;
    vector<int> a{ 1, 1, 1 };
    vector<int> b{ 2, 2, 2 };
    vector<int> c{ 3, 3, 3 };

    vector<vector<int>> v = { a, b, c };

    cout << s.pileBox( v ) << endl;
}