class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        m_q_use -> push( x );
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        shift ( m_q_use, m_q_back );
        int top = m_q_use -> front();
        m_q_use -> pop();
        switch_queue();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        shift ( m_q_use, m_q_back );
        int top = m_q_use -> front();
        m_q_use -> pop();
        m_q_back -> push(top);
        switch_queue();
        return top;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return m_q1.empty() && m_q2.empty();
    }
    
private:
    queue<int> m_q1;
    queue<int> m_q2;
    queue<int> * m_q_use = &m_q1;
    queue<int> * m_q_back = &m_q2;
    
    void shift( queue<int> * from, queue<int> * to ){
        
        while ( from -> size() > 1 ){
            int front = from -> front();
            from -> pop();
            to -> push( front );
        }
    }
    
    void switch_queue(){
        if ( m_q_use == &m_q1 ){
            m_q_use = &m_q2;
            m_q_back = &m_q1;
        } else {
            m_q_use = &m_q1;
            m_q_back = &m_q2;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */