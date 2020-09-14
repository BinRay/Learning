#include <string>
#include <cmath>
#include <vector>

using namespace std;

/**
 *  1. 算法的核心思想就是从第0行开始，对于每一列，逐一填充Q，如果遇到冲突的情况（同行、同列、同对角线），则撤销这次放置，将Q移到下一列。
    2. 当某一行所有列全部不满足时，返回上一行；满足则继续向下一行操作。当所有行都操作完，则代表一个解。
    3. 在验证Q是否冲突，以下代码采用攻击范围的思想，即放置Q的同时，也绘制它的攻击范围，用于下一次放置Q判断用。
*/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;
        string row( n, '0' );
        vector<string> chessboard( n, row );

        place_in( ans, 0, chessboard, n );

        return ans;

    }

    void place_in( vector<vector<string>> &ans, int row, vector<string> &chessboard, const int SIZE ){
        if ( row == SIZE ){
            ans.push_back( chessboard );
        } else {
            for ( int column = 0; column < SIZE; column++ ){
                if ( chessboard[row][column] != '.' ){          //检查是否在攻击范围内
                    vector<string> new_chessboard = draw_attack_range( chessboard, row, column, SIZE );
                    place_in( ans, row + 1, new_chessboard, SIZE );
                }
            }
        }
    }

    vector<string> draw_attack_range( vector<string> &chessboard, int row, int column, const int SIZE  ){
        vector<string> new_chessboard =  chessboard;
        // 因为大部分是时不可取的，所以进入这个二层循环是少数情况
        // 该点可取，绘制这个女王攻击范围
        for ( int i = row; i < SIZE; i++ ){             // 因为从上往下填充Q，所以row以上所有的点一定都已经填充好了. 和 Q，因此从row开始即可。
            for ( int j = 0; j < SIZE; j++ ){
                if ( i == row || j == column || abs( row - i ) == abs( column - j) ){
                    new_chessboard[i][j] = '.';         // 标记此点处在攻击范围内
                }
            }
        }

        // 绘制女王节点
        new_chessboard[row][column] = 'Q';

        return new_chessboard;
    }
};

int main( int argc, char** argv ){
    Solution s;
    s.solveNQueens( 4 );
}