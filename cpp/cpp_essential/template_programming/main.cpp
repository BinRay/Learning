//
// Created by lbinr on 2020/5/25.
//

#include "BinaryTree.h"
#include <string>

using namespace std;

void val_int(){
    BinaryTree<int> bt;

    bt.insert( 5 );
    bt.insert( 6 );
    bt.insert( 7 );
    bt.insert( 4 );

    bt.inorder();
}

int main( int argc, char** argv ){

    val_int();

}

