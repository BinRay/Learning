//
// Created by lbinr on 2020/5/19.
//

#include <iostream>
#include "Triangular.h"

using namespace std;

// if an element is in the triangular series.
void is_elem(){
    char ch;
    bool more = true;

    while ( more ){
        cout << "enter value: ";
        int ival;
        cin >> ival;

        bool if_elem = Triangular::is_elem( ival );
        cout << ival << " "
             << ( if_elem  ? "is" : "is not" )
             << " an element in the Triangular series"
             << endl;
        cout << " continue? (y/n)" << endl;
        cin >> ch;
        if ( ch == 'n'  || ch == 'N' ){
            more = false;
        }
    }
}

void display(){
    int length, beg_pos;

    cout << "input length:";
    cin >> length;

    cout << "input beg_pos:";
    cin >> beg_pos;

    Triangular tri(length, beg_pos);
    cout << tri << endl;
}

void traverse_by_iter(){
    Triangular tri (20, 1);
    Triangular::iterator it = tri.begin();
    Triangular::iterator end_it = tri.end();
    cout << "travel begins: " << endl;
    while ( it != end_it ){
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

int main( int argc, char** argv ){
    Triangular tri ( 8, 1);
//    Triangular::display( 6, 3, cout );
    cout << tri << endl;

    cout << "select function:" << endl
         << "1. display the series" << endl
         << "2. check a element if in the series" << endl
         << "3. traverse by iteratror" << endl;

    int opt;
    cin >> opt;
    switch (opt) {
        case 1:
            display();
            break;
        case 2:
            is_elem();
            break;
        case 3:
            traverse_by_iter();
            break;
        default:
            break;
    }

}
