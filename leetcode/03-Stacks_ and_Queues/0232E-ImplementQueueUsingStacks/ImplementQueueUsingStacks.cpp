// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：7.1 MB, 在所有 C++ 提交中击败了8.54%的用户

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if ( m_status != "push" ){
            shift( &m_pop_stack, &m_push_stack, "push" );
        }
        m_push_stack.push( x );
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if ( m_status != "pop" ){
            shift( &m_push_stack, &m_pop_stack, "pop" );
        }
        int top = m_pop_stack.top();
        m_pop_stack.pop();
        return top;

    }
    
    /** Get the front element. */
    int peek() {
        if ( m_status != "pop" ){
            shift( &m_push_stack, &m_pop_stack, "pop" );
        }
        return m_pop_stack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return m_pop_stack.empty() && m_push_stack.empty();
    }

private:
    stack<int> m_pop_stack;
    stack<int> m_push_stack;
    string m_status = "push";
    
    void shift( stack<int> * from, stack<int> * to, string status ){
        while ( !(from -> empty()) ){
            int top = from -> top();
            from -> pop();
            to -> push( top );
        }
        
        m_status = status;
    } 
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */