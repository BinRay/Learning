// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if ( x < 0 ){
            return false;
        }

        vector<int> v;
        do{
            v.push_back( x % 10 );
            x /= 10;
        } while( x != 0);

        return isPalindromeVector( v );
    }

    bool isPalindromeVector( vector<int>& v ){
        if ( v.size() == 1){
            return true;
        }
        vector<int>::iterator it = v.begin();
        vector<int>::iterator rit = v.end();
        rit--;

        while ( it <= rit ) {
            if ( *it != *rit ){
                return false;
            }
            it++;
            rit--;
        }

        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isPalindrome( 121 ) << "h" << endl;
}
