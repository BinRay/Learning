#include <stack>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> my_stack;
        for ( string::iterator it=s.begin(); it != s.end(); ++it ){
            if ( *it == '{' || *it == '[' || *it == '(' ){
                my_stack.push(*it);
            } else if ( *it == ')' ) {
                if ( !my_stack.empty() && my_stack.top() == '(' ){
                    my_stack.pop();
                } else {
                    return false;
                }
            } else if ( *it == ']' ){
                if ( !my_stack.empty() && my_stack.top() == '[' ){
                    my_stack.pop();
                } else {
                    return false;
                }
            } else if ( *it == '}' ){
                if ( !my_stack.empty() && my_stack.top() == '{' ){
                    my_stack.pop();
                } else {
                    return false;
                }
            }
        }
        if (my_stack.empty()) {
            return true;
        }
        return false;
    }
};

int main( int argc, char** argv ){
    string st = "[aa(f)]{}";
    Solution s;
    cout << s.isValid(st) << endl;
}