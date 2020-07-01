// 1. 两个栈分别用于pop和push
// 2. 使用一个m_type状态来维持当前的状态，这样连续入队列和出队列时不必来回倒数据
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        m_type = "push";
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if ( m_type == "pop" ){
            shift( "push" );
        }
        s_push.push( x );
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if ( m_type == "push" ){
            shift( "pop" );
        }
        int top = s_pop.top();
        s_pop.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        if ( m_type == "push" ){
            shift( "pop" );
        }
        int top = s_pop.top();
        return top;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s_pop.empty() && s_push.empty();
    }
    
private:
    void shift( string type ){
        if ( type == "pop" ){
            while ( !s_push.empty() ){
                int top = s_push.top();
                s_push.pop();
                s_pop.push( top );
            }
        } else if ( type == "push" ) {
            while ( !s_pop.empty() ){
                int top = s_pop.top();
                s_pop.pop();
                s_push.push( top );
                
            }
        } 
        
        m_type = type;
        
    }

    string m_type;
    stack<int> s_pop;
    stack<int> s_push;
    
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */