//
// Created by breeze on 2020/3/10.
//
#include <iostream>
#include <map>

using namespace std;

// 初始化
void init(map<string, size_t> &m){
	std::map<string, size_t> m1{{"Ann", 25}, {"Bill", 46}}; //c++11, 初始化
	std::map<string, size_t> m2{m1}; //people2 为 people1的副本
	m = m1;
}

// 新增
void insert(map<string, size_t> &m){
	pair<string, size_t> p = make_pair<string, size_t>("breeze", 18);

	if (!m.count("breeze")){
		m.insert(p);
	}
}

// 遍历
void traverse(map<string, size_t> &m){
	for(map<string, size_t>::iterator iter = m.begin(); iter != m.end(); iter++){
		cout << "key:" << iter -> first << " value:" << iter -> second << endl;
	}
}

int main(int agrc, char* argv[]){
	map<string, size_t> m;
	init(m);
	insert(m);
	traverse(m);
}

