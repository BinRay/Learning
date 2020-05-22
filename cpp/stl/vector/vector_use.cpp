//
// Created by breeze on 2020/3/9.
//

#include <iostream>
#include <vector>

using namespace std;

void add(vector<int> &v){
	for (int i = 0; i < 5; i++){
		v.push_back(i);
	}
}

void test_capacity(){
	vector<int> v;
	add(v);

	vector<int>::iterator iter = v.begin() + 3;
	vector<int>::iterator iter2 = iter;
	iter = v.end();
	cout << iter - iter2 << endl;
	cout << iter - v.begin() << endl;

	// 验证vector扩容
	for (int j = 0; j< 20 ; j++){
		add(v);
		cout << "capacity:" << v.capacity() << endl;
		v.erase(iter);
		cout << iter - v.begin() << "|" << *iter << endl;

	}
}

int main(int argc, char* argv[]){
	test_capacity();
}

