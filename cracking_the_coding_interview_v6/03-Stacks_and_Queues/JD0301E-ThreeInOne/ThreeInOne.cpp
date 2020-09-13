class TripleInOne {
public:
    TripleInOne(int stackSize) {
        v.resize( stackSize * 3 );
        m_max = stackSize;
        m_index0 = 0;
        m_index1 = 0;
        m_index2 = 0;
    }
    
    void push(int stackNum, int value) {
        switch ( stackNum ){
            case 0:
                if (m_index0 < m_max ){
                    v[m_index0 * 3] = value;
                    m_index0++;
                }
                break;
            case 1:
                if (m_index1 < m_max ){
                    v[m_index1 * 3 + 1] = value;
                    m_index1++;
                }
                break;
            case 2:
                if (m_index2 < m_max ){
                    v[m_index2 * 3 + 2] = value;
                    m_index2++;
                }
                break;
            default:
                break;
        }
    }
    
    int pop(int stackNum) {
        switch ( stackNum ){
            case 0:
                if (m_index0 > 0 ){
                    return v[--m_index0 * 3];
                }
                break;
            case 1:
                if (m_index1 > 0 ){
                   return v[--m_index1 * 3 + 1];
                }
                break;
            case 2:
                if (m_index2 > 0 ){
                   return v[--m_index2 * 3 + 2];
                }
                break;
            default:
                break;
        }
        return -1;
    }
    
    int peek(int stackNum) {
         switch ( stackNum ){
            case 0:
                if (m_index0 > 0 ){
                    return v[ (m_index0-1) * 3];
                }
                break;
            case 1:
                if (m_index1 > 0 ){
                   return v[ (m_index1-1) * 3 + 1];
                }
                break;
            case 2:
                if (m_index2 > 0 ){
                   return v[ (m_index2-1) * 3 + 2];
                }
                break;
            default:
                break;
        }
        return -1;
    }
    
    bool isEmpty(int stackNum) {
        switch ( stackNum ){
            case 0:
                if (m_index0 > 0 ){
                    return false;
                }
                break;
            case 1:
                if (m_index1 > 0 ){
                   return false;
                }
                break;
            case 2:
                if (m_index2 > 0 ){
                   return false;
                }
                break;
            default:
                break;
        }
        return true;
    }
    
private:
    vector<int> v;
    int m_index0;
    int m_index1;
    int m_index2;
    int m_max;
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */