#include <iostream>
#include <string>
#include <stack>
#include <climits>

using namespace std;

// 1. 两个栈实现，一个栈用于pop，另一个栈用于在push时临时储存较小的数据。
// 2. 记录当前状态，pop状态时可以直接弹出栈。
// 3. 重点在于push操作，一个重要的判断条件是：当val值介于tmp栈顶元素与pop栈顶元素之间时，即是合理入栈时机，否则移动栈。
// 4. 注意保护，当栈为空时，pop()和top()操作会报执行错误。

// 执行用时：28 ms, 在所有 C++ 提交中击败了92.47%的用户
// 内存消耗：12.1 MB, 在所有 C++ 提交中击败了100.00%的用户
class SortedStack {
public:
    SortedStack() {
        m_type = "pop";
    }

    void push(int val) {
        if ( s_tmp.empty() && s_pop.empty() ){
            s_pop.push( val );
            return;
        }

        int top_tmp = s_tmp.empty() ? INT_MIN : s_tmp.top();
        int top_pop = s_pop.empty() ? INT_MAX : s_pop.top();

        while ( !(val >= top_tmp && val <= top_pop) ){
            if ( val < top_tmp ){
                shift( s_tmp, s_pop );
            } else {
                shift( s_pop, s_tmp );
            }
            top_tmp = s_tmp.empty() ? INT_MIN : s_tmp.top();
            top_pop = s_pop.empty() ? INT_MAX : s_pop.top();
        }

        s_pop.push( val );
        m_type = "push";
    }

    void pop() {
        if ( isEmpty() ){
            return;
        }
        if ( m_type != "pop" ){
            shift_pop();
        }
        s_pop.pop();
    }

    int peek() {
        if ( m_type != "pop" ){
            shift_pop();
        }
        return s_pop.empty() ? -1 : s_pop.top();
    }

    bool isEmpty() {
        return s_pop.empty() && s_tmp.empty();
    }

private:
    void shift_pop(){
        while ( !s_tmp.empty() ){
            int top = s_tmp.top();
            s_tmp.pop();
            s_pop.push( top );
        }
        m_type = "pop";
    }

    void shift( stack<int> &from, stack<int> &to ){
        int top = from.top();
        from.pop();
        to.push( top );
    }

    string m_type;

    stack<int> s_pop;
    stack<int> s_tmp;
};

int main( int argc, char** argv ){
    SortedStack s;
    s.pop();
    s.pop();
    s.push(1);
    s.pop();
    s.isEmpty();
}

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */