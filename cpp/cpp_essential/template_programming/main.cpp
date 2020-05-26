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
    cout << endl;
    bt.remove( 7 );
    bt.remove( 4 );
//    bt.remove( 6 );

    bt.inorder();
}

void val_string() {
    BinaryTree<string> bt;

    bt.insert( "aaaaa" );
    bt.insert( "bbbbb" );
    bt.insert( "ccccc" );
    bt.insert( "ddddd" );
    bt.insert( "eeeee" );
    bt.insert( "abcde" );
    bt.insert( "bcdea" );
    bt.insert( "bcdee" );

    bt.inorder();
    cout << endl;

    bt.clear();
    bt.inorder();

}

int main(int argc, char** argv ){

    cout << "input which type you would operate:" << endl;

    int type;
    cin >> type;
    switch ( type ){
        case 1:
            val_int();
        case 2:
            val_string();
        default:
            return 0;
    }

    return 0;
}

