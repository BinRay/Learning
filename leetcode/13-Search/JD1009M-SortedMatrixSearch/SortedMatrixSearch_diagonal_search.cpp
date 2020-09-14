#include <vector>
#include <iostream>

using namespace std;

// 注：这是错误的解法
// 目的是先确定目标值的范围，但是实际上无法以右下角的点确定。
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 在对角线上二分搜索，确定目标元素所处的行或者列
        // 利用右下元素一定是矩阵最大值的特性

        int M = matrix.size() - 1;
        int N = matrix.empty() ? -1 : matrix[0].size() - 1;

        if ( M == -1 || N == -1  || target < matrix[0][0] || target > matrix[M][N]) return false;
        int top = 0;
        int bottom = M;
        int left = 0;
        int right = N;

        int target_row = 0;
        int target_column = 0;

        while ( true ){

            int mid_row = ( top + bottom ) / 2;
            int mid_column = ( left + right ) / 2;

            if ( matrix[mid_row][mid_column] == target ) return true;

            if ( matrix[mid_row][mid_column] < target ){
                target_row = mid_row + 1 > M ? M : mid_row + 1;
                target_column = mid_column + 1 > N ? N : mid_column + 1;

                if ( matrix[target_row][target_column] >= target ) {
                    break;
                } else {
                    top = target_row;
                    left = target_column;
                }
            } else {
                target_row = mid_row - 1 < 0 ? 0 : mid_row - 1;
                target_column = mid_column - 1 < 0 ? 0 : mid_column - 1;

                if ( matrix[target_row][target_column] < target ){
                    target_row = mid_row;
                    target_column = mid_column;
                    break;
                } else {
                    bottom = mid_row;
                    right = mid_column;
                }

            }
        }

        cout << target_row << " " << target_column << endl;
        // 在target_row 上 二分搜索
        int first = 0;
        int last = target_column;
        int mid = 0 ;
        while ( first <= last ){
            mid = ( first + last ) / 2;
            if ( matrix[target_row][mid] < target ){
                first = mid + 1;
            } else if ( matrix[target_row][mid] > target ){
                last = mid - 1;
            } else {
                return true;
            }
        }



        // 在target_column上执行二分搜索
        first = 0;
        last = target_row;
        mid = 0;
        while ( first <= last ){
            mid = ( first + last ) / 2;
            if ( matrix[mid][target_column] < target ){
                first = mid + 1;
            } else if ( matrix[mid][target_column] > target ){
                last = mid - 1;
            } else {
                return true;
            }
        }

        return false;

    }

};

int main( int argc, char** argv ){
    vector<vector<int>> v = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    int target = 15;
    Solution s;
    s.searchMatrix(v, target);
}