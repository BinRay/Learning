//
// Created by lbinr on 2020/5/25.
//

#ifndef TEMPLATE_PROGRAMMING_BINARYTREE_H
#define TEMPLATE_PROGRAMMING_BINARYTREE_H

#include "BTnode.h"
#include <iostream>

using namespace std;

template < typename elemType >
class BinaryTree{

public:
    // ...
    BinaryTree();
    BinaryTree( const BinaryTree& );
    ~BinaryTree();

    //BinaryTree& operator=( const BinaryTree& );
    //void copy();

    bool empty() { return _root == 0; }

    void clear();
    static void clear( BTnode<elemType>* pt );

    void insert( const elemType& val );

    void remove( const elemType& val );

    void inorder( ostream& os = cout ){
        if ( _root ){
            _root -> inorder( os );
        }
    }

//private:
    BTnode<elemType>* _root;

    void remove_root();
};

// 这里写中文是为了强调：模板类的函数定义一定要与声明的上下文中，此处的定义并不会真正分配空间。
template < typename valType >
BinaryTree< valType >::BinaryTree():_root(0) {}

template < typename valType >
BinaryTree< valType >::BinaryTree( const BinaryTree& rhs ) {
    //copy( _root, rhs._root);
}

template < typename valType >
BinaryTree< valType >::~BinaryTree() {
    //clear();
}

template< typename elemType >
void BinaryTree<elemType>::insert(const elemType &val) {
    if ( ! _root ){
        _root = new BTnode<elemType>( val );
    }else{
        _root -> insert_value( val );
    }
}

template<typename elemType>
void BinaryTree<elemType>::remove(const elemType &elem) {
    // we can split this operation to two parts:
    // 1. when val equals to the root's values, we don't need to operate parent node.
    // 2. the othen regular node values.
    if ( elem == _root -> _val ) {
        remove_root();
    } else {
        _root -> remove_value( elem, _root );
    }
}

template<typename elemType>
void BinaryTree<elemType>::remove_root() {
    if ( ! _root )
        return;
    if ( ! _root -> _rchild ) {
        _root = _root -> _lchild;
    } else {
        BTnode<elemType>* tmp = _root;
        _root = _root -> _rchild;
        if ( tmp -> _lchild ){
            BTnode<elemType>::lchild_leaf( tmp -> _lchild, _root );
        }
    }
    delete _root;
}

template<typename elemType>
void BinaryTree<elemType>::clear() {
    if ( _root ) {
        clear( _root );
        _root = 0;
    }
}

template<typename elemType>
void BinaryTree<elemType>::clear(BTnode<elemType> *pt) {
    if ( pt ){
        clear( pt -> _lchild );
        clear( pt -> _rchild );
        delete pt;
    }
}


#endif //TEMPLATE_PROGRAMMING_BINARYTREE_H
