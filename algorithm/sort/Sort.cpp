#include <iostream>
#include <vector>

using namespace std;

class MergeSort{
public:
    void merge_sort( vector<int> & nums ){
        vector<int> temp( nums );
        divide( nums, temp, 0, temp.size() - 1 );
    }

    void divide( vector<int> &nums, vector<int> &temp, int low, int high ){
        if ( low < high ){
            int mid = ( low + high ) / 2;
            divide( nums, temp, low, mid );
            divide( nums, temp, mid + 1, high );
            merge( nums, temp, low, mid, high );
        }
    }

    void merge (vector<int> &nums, vector<int> &temp, int low, int mid, int high ){
        for ( int i = low; i <= high; i++ ){
            temp[i] = nums[i];
        }

        int left = low;
        int right = mid + 1;
        int cur = low;

        while ( left <= mid && right <= high ){
            if ( temp[left] <= temp[right] ){
                nums[cur] = temp[left];
                cur++;
                left++;
            } else {
                nums[cur] = temp[right];
                cur++;
                right++;
            }
        }

        while ( left <= mid ){
            nums[cur] = temp[left];
            cur++;
            left++;
        }
    }
};


int main( int argc, char** argv ){

    vector<int> nums = { 3, 2, 4, 1, 19, -1, 0 ,2 ,77, 54, 108, 99, 22, 88};

    MergeSort m;
    m.merge_sort( nums );

    for ( auto i: nums ){
        cout << i << " ";
    }
    cout << endl;


}