/**
 * 解题思路
题意旋转的意思是把最后一个数移到数组最前端，旋转几次就是移动几个数。
得到的数列有一个特性：如果以中间的数分割数组，则至少有一半是按升序排列的。
判断target是否在升序排列中，是则继续对半查找。否，则在另一半中查找。
注意因为是要target的第一个出现的位置，所以即使中间数与target相同，也要看下first和mid-1的值。

*/

class Solution {
public:
    int search(vector<int>& arr, int target) {

        return search( arr, 0, arr.size() - 1, target );

    }

    int search( vector<int> &arr, int first, int last, int target ){
        if ( first > last ) return -1;

        int mid = ( first + last ) / 2;
        if ( arr[first] == target ){
            return first;
        }
        if ( arr[mid] == target ){
            // 处理重复值情况，返回第一个target索引
            while ( arr[mid-1] == target ){
                mid--;
            }
            return mid;
        } else {
            if ( arr[first] < arr[mid] ){
                if ( target < arr[mid] && target >= arr[first] ){
                    return search( arr, first, mid - 1,  target );
                } else {
                    return search( arr, mid + 1, last, target );
                }
            } else if ( arr[mid] < arr[last] ){
                if ( target > arr[mid] && target <= arr[last] ){
                    return search( arr, mid + 1, last ,target );
                } else {
                    return search( arr, first, mid - 1, target );
                }
            } else {                // 两边都是相等的情况，区分不出哪个是升序
                int ans1 = search( arr, first, mid - 1, target );
                int ans2 = search( arr, mid + 1, last ,target );

                return ans1 == -1 ? ans2 : ans1;
            }
        }
    }
};
