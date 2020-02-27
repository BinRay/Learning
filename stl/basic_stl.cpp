//
// Created by bin on 2020/2/27.
//
#include <iostream>
#include <vector>

#include "basic_stl.h"

using namespace std;

// 迭代器使用
void use_iterator();
// find() 算法使用
void use_find();

int main(int argc, char* argv[]){
//    use_iterator();
    use_find();
}


void use_iterator(){
    // 定义vector
    vector<int> v;

    // 添加元素
    for(int i = 0; i < 5; i++){
        v.push_back(i);
    }

    // 定义迭代器
    vector<int>::iterator iter;             //常量 const_iterator
    for(iter = v.begin(); iter != v.end(); ++iter){ //++前置比后置速度快
        cout << *iter << " ";
        *iter *= 2;
    }
    cout << endl;

    // 定义反向迭代器
    vector<int>::reverse_iterator iter_r;   //常量 const_reverse_iterator
    for(iter_r = v.rbegin(); iter_r != v.rend(); ++iter_r){
        cout << *iter_r << " ";
    }
    cout << endl;

}

void use_find(){
    vector<int> v;
    for(int i = 0; i < 5; i++){
        v.push_back(i);
    }
    vector<int>::const_iterator iter;
//    iter = find(v.begin(), v.end(), 5);
    iter = find(v.begin(), v.end(), 3);
    if(iter != v.end()){
        cout << "exist:" << *iter << endl;
    }else{
        cout << "not exist" << endl;
    }
}

