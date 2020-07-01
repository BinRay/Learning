#include <string>
#include <vector>
#include <list>
#include <stack>
#include <iostream>
using namespace std;

// 执行用时：136 ms, 在所有 C++ 提交中击败了26.89%的用户
// 内存消耗：28 MB, 在所有 C++ 提交中击败了100.00%的用户

// 1. 使用类似邻接表 list<stack<int> > 的结构存储数据。
// 2. 注意在一个栈满时新建一个stack插入到list末尾，一个栈空时要删除。
// 3. 注意capcity为0时的情况，本题判题时有这样的测试用例。
// 4. 由于使用list链表数据结构，所以存取耗时较多，可以替换为vector。

class StackOfPlates {
public:
    StackOfPlates(int cap) {
        m_cap = cap;
    }

    void push(int val) {

        if ( m_l.empty() || m_l.back().size() >= m_cap ){
            stack<int> new_s;
            new_s.push( val );
            m_l.push_back( new_s );
        } else {
            m_l.back().push( val );
        }
    }

    int pop() {
        int value;
        if ( m_l.empty() ){
            return -1;
        } else {
            value = m_l.back().top();
            m_l.back().pop();
            if ( m_l.back().empty() ){
                m_l.pop_back();
            }
        }
        return value;
    }

    int popAt(int index) {
        if ( m_l.empty() || index >= m_l.size()){
            return -1;
        }
        auto it = m_l.begin();
        while ( index > 0 ){
            index--;
            it++;
        }
        int value = it -> top();
        it -> pop();

        if ( it -> empty() ){
            m_l.erase( it );
        }
        return value;
    }

//private:

    list<stack<int> > m_l;
    int m_cap;

};



int main( int argc, char** argv ){
    StackOfPlates st(6);
    vector<string> c1 = {"pop", "pop", "popAt", "popAt", "pop", "push", "push", "push", "push", "popAt", "push", "push", "popAt", "pop", "popAt", "push", "popAt", "pop", "push", "pop", "pop", "pop", "popAt", "push", "pop", "popAt", "pop", "push", "popAt", "popAt", "push", "popAt", "popAt", "push", "pop", "popAt", "popAt", "popAt", "pop", "popAt", "popAt", "push", "popAt", "push", "push", "pop", "popAt", "popAt", "push", "popAt", "push", "pop", "pop", "push", "push", "push", "popAt", "popAt", "pop", "popAt", "pop", "pop", "push", "push"};
    vector<int> c2 = {0, 0, 1, 3, 0, 40, 10, 44, 44, 1, 24, 42, 4, 0, 0, 42, 5, 0, 29, 0, 0, 0, 0, 56, 0, 4, 0, 34, 1, 4, 52, 4, 6, 63, 0, 6, 6, 1, 0, 6, 2, 47, 1, 45, 52, 0, 6, 6, 20, 4, 17, 0, 0, 43, 6, 30, 2, 3, 0, 3, 0, 0, 51, 46};
    for ( int i = 0; i < c1.size(); i++ ){
        if ( c1[i] == "pop" ){
            cout << i << "," << "pop" << "," << st.pop() << ",";
            cout << st.m_l.size() << endl;
        } else if ( c1[i] == "popAt"){
            cout << i << "," << "popAt" << c2[i] << "," << st.popAt(c2[i]) << ",";
            cout << st.m_l.size() << endl;
        } else if ( c1[i] == "push"){
            st.push(c2[i]);
            cout << i << "," << "push" << "," << c2[i] << ",";
            cout << st.m_l.size() << endl;
        }
    }
}

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */