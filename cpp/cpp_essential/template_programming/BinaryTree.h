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
    BinaryTree& operator=( const BinaryTree& );

    //todo: copy
    //void copy();
    bool empty() { return _root == 0; }
    //void clear();

    void insert( const elemType& val );

    void inorder( ostream& os = cout ){
        _root -> inorder( os );
    }

//private:
    BTnode<elemType>* _root;

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

#endif //TEMPLATE_PROGRAMMING_BINARYTREE_H
