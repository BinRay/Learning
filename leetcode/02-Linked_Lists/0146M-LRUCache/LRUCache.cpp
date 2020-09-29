#include <unordered_map>

using namespace std;

// Doubly-linked List
struct Node {

    int key;
    int val;

    struct Node* prev;
    struct Node* next;

    Node( int k, int v ){
        key = k;
        val = v;

        prev = NULL;
        next = NULL;
    }

};

class DoubleList {
private:

    // 两个哨兵
    struct Node* head;
    struct Node* tail;

public:
    int size;

    DoubleList(){
        head = new Node( 0, 0 );
        tail = new Node( 0, 0 );

        head -> next = tail;
        tail -> prev = head;

        size = 0;
    }

    // 删除某节点
    bool remove_node( Node* n ){
        if ( !n ) return false;

        n -> prev -> next = n -> next;
        n -> next -> prev = n -> prev;

        size--;
        return true;
    }

    // 删除最老节点，本实现是从头删除
    Node* remove_first(){
        if ( size == 0 ){
            return NULL;
        } else {
            Node * first = head -> next;
            remove_node( first );
            return first;
        }
    }

    // 从内存中释放节点的内存空间
    bool delete_node( Node* n ){
        if ( !n ) return false;
        delete n;
        return true;
    }

    // 增加一个新节点，在tail的前面
    bool add_last( Node* n ){
        n -> prev = tail -> prev;
        n -> next = tail;

        tail -> prev = n;
        n -> prev -> next = n;

        size++;
        return true;

    }



};

class LRUCache {
private:
    unordered_map<int, Node*> map;
    DoubleList cache;

    int cap;    // 最大容量

    // 提供一层抽象，用于同时操作map和cache

    // 将某个key提升为最近使用的，节点已存在
    void make_recently( int key ){
        Node* n = map[key];
        cache.remove_node( n );
        cache.add_last( n );
    }

    // 添加最近使用的一个新key
    void add_recently( int key, int val ){
        Node* n = new Node( key, val );
        cache.add_last( n );
        map[key] = n;
    }

    // 删除某个节点
    void delelte_key( int key ){
        Node* n = map[key];
        cache.remove_node( n );
        cache.delete_node( n );   // 释放内存
        map.erase( key );
    }

    // 删除最老的key
    void remove_oldest(){
        Node* n = cache.remove_first();
        map.erase( n -> key );
        cache.delete_node( n );
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if ( !map.count(key) ) return -1;

        return map[key] -> val;
    }

    void put(int key, int value) {
        if ( map.count( key ) ){
            map[key] -> val = value;
            make_recently( key );
        } else {
            if ( cache.size >= cap ){
                remove_oldest();
            }
            add_recently( key, value );
        }
    }
};

int main( int argc, char* argv[] ){
    LRUCache lru(2);
    lru.put( 1, 1 );
    lru.put( 2, 2 );
    lru.get( 1 );
    lru.put( 3, 3 );
    lru.get( 2 );
    lru.put( 4, 4 );
    lru.get( 1 );
    lru.get( 3 );
    lru.get( 4 );

}




/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */