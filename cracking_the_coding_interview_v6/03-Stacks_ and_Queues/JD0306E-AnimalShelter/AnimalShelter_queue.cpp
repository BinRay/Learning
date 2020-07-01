// 1. 使用双队列实现，一个存猫，一个存狗
// 2. 在出any时，比较猫和狗的序号
// 3. 本实现使用tuple，如果改用vector应该能快点，可能空间会用的更多。

// 执行用时：312 ms, 在所有 C++ 提交中击败了75.86%的用户
// 内存消耗：112.5 MB, 在所有 C++ 提交中击败了100.00%的用户

class AnimalShelf {
public:
    AnimalShelf() {

    }
    
    void enqueue(vector<int> animal) {
        tuple<int, int> t;
        get<0>(t) = animal[0];
        get<1>(t) = animal[1];
        if ( animal[1] == 0 ){
            q_cat.push( t );
        } else {
            q_dog.push( t );
        }
    }
    
    vector<int> dequeueAny() {
        if ( q_cat.empty() && q_dog.empty() ){
            return { -1, -1 };
        } else if ( q_cat.empty() || q_dog.empty() ){
            queue <tuple<int, int> > &q = q_cat.empty() ? q_dog : q_cat;
            vector<int> v = { get<0>(q.front()), get<1>(q.front()) };
            q.pop();
            return v;
        } else {
            queue <tuple<int, int> > &q = get<0>(q_cat.front()) < get<0>(q_dog.front()) ? q_cat : q_dog ;
            vector<int> v = { get<0>(q.front()), get<1>(q.front()) };
            q.pop();
            return v;
        }
    }
    
    vector<int> dequeueDog() {
        if ( q_dog.empty() ){
            return { -1, -1 };
        } else {
            vector<int> v = { get<0>(q_dog.front()), get<1>(q_dog.front()) };
            q_dog.pop();
            return v;
        }
    }
    
    vector<int> dequeueCat() {
        if ( q_cat.empty() ){
            return { -1, -1 };
        } else {
            vector<int> v = { get<0>(q_cat.front()), get<1>(q_cat.front()) };
            q_cat.pop();
            return v;
        }
    }

private:
    queue <tuple<int, int> > q_cat;
    queue <tuple<int, int> > q_dog;
    
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */