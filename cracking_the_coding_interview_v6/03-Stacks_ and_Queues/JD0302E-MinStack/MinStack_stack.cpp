// 执行用时：52 ms, 在所有 C++ 提交中击败了42.45%的用户
// 内存消耗：15.3 MB, 在所有 C++ 提交中击败了100.00%的用户
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        m_v.push_back(x);
        
        if ( m_s.size() > 0 ){
            if ( x <= m_s.top() ){
                m_s.push( x );
            }
        } else {
            m_s.push( x );
        }
        
    }
    
    void pop() {
        
        int top = m_v.back();
        m_v.pop_back();
        
        if ( top == m_s.top() ){
            m_s.pop();
        }
        
    }
    
    int top() {
        return m_v.back();
    }
    
    int getMin() {
        return m_s.top();    
    }
    
private:
    
    // 1. 借助另一个栈来存储最小值
    // 2. 在出入栈时判断操作的元素比当前最小值小或者相等时，对这个储存最小值的栈操作
    // 3. 之所以有“相等”，是因为最小值在序列中可能不只有一个
    vector<int> m_v;
    stack<int> m_s;
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */