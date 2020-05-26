//
// Created by lbinr on 2020/5/25.
//

#ifndef TEMPLATE_PROGRAMMING_BTNODE_H
#define TEMPLATE_PROGRAMMING_BTNODE_H

#include <iostream>

using namespace std;

template <typename Type>
class BinaryTree;   // forward declareation

template < typename valType >
class BTnode {

    friend class BinaryTree<valType>;   // so that BinaryTree can access BTnode's member data directly.

public:
    // ...
    BTnode( const valType& val );

    // print values of the tree in 'inorder'
    void inorder( ostream& os = cout ) const;

    void insert_value( const valType& val);

    void display_val ( ostream& os ) const;


private:

    void remove_value( const valType &val, BTnode<valType>*& prev );
    void static lchild_leaf( BTnode<valType>* leaf, BTnode<valType>* subtree );

    valType     _val;
    int         _cnt;
    BTnode*     _lchild;
    BTnode*     _rchild;
};

template<typename valType>
BTnode<valType>::BTnode( const valType &val ) : _val( val ) {
    _cnt = 1;
    _lchild = _rchild = 0;
}

template<typename valType>
void BTnode<valType>::insert_value( const valType &val ) {

    if ( val == _val ){
        _cnt++;
        return;
    }

    if ( val < _val ){
        if ( ! _lchild ){
            _lchild = new BTnode<valType>( val );
        } else{
            _lchild -> insert_value( val );
        }
    }else{
        if ( ! _rchild ){
            _rchild = new BTnode( val );
        }else{
            _rchild -> insert_value( val );
        }
    }

}

template<typename elemType>
void BTnode<elemType>::inorder( ostream &os ) const {

    if ( _lchild )
        _lchild -> inorder( os );

    display_val ( os );

    if ( _rchild )
        _rchild -> inorder( os );
}

template<typename elemType>
void BTnode<elemType>::display_val( ostream &os ) const {
    os << _val << " ";
}

template<typename valType>
void BTnode<valType>::lchild_leaf(BTnode<valType> *leaf, BTnode<valType> *subtree) {
    while ( subtree -> _lchild ) {
        subtree = subtree -> _lchild;
    }
    subtree -> _lchild = leaf;
}

template<typename valType>
void BTnode<valType>::remove_value(const valType &val, BTnode<valType>*& prev) {
    // prev refers to the lchild or rchild of the parent node. we can change its value directly via refenence.
    if ( val < _val ){
        if ( ! _lchild ){
            return; // not in this binary tree
        } else {
            _lchild -> remove_value( val, _lchild );
        }
    } else if ( val > _val ) {
        if ( ! _rchild ) {
            return; // not in this binary tree
        } else {
            _rchild -> remove_value( val, _rchild );
        }
    } else {    // equivalent
        if ( _rchild ){
            prev = _rchild;
            if ( _lchild ){
                lchild_leaf( _lchild, _rchild);
            }
        } else {
            prev = _lchild;
        }
        delete this;
    }
}

#endif //TEMPLATE_PROGRAMMING_BTNODE_H
