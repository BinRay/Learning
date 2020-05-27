//
// Created by lbinr on 2020/5/26.
//

#include <map>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int k_auto(){


    auto  i = 0;          // 自动推导为int类型
    auto  str = "hello";  // 自动推导为const char [6]类型

    std::map<int, std::string> m = {{1,"a"}, {2,"b"}};  // 自动推导不出来
    auto  iter = m.begin();  // 自动推导为map内部的迭代器类型
    auto  f = bind1st(std::less<int>(), 2);  // 自动推导出类型，具体是啥不知道


    auto        x = 10L;    // auto推导为long，x是long
    auto&       x1 = x;      // auto推导为long，x1是long&
    auto*       x2 = &x;    // auto推导为long，x2是long*
    const auto& x3 = x;        // auto推导为long，x3是const long&
    auto        x4 = &x3;    // auto推导为const long*，x4是const long*

}

void k_auto_app() {

    vector<int> v = {2,3,5,7,11};  // vector顺序容器

    for(const auto& i : v) {      // 常引用方式访问元素，避免拷贝代价
        cout << i << ",";          // 常引用不会改变元素的值
    }

    for(auto& i : v) {          // 引用方式访问元素
        i++;                      // 可以改变元素的值
        cout << i << ",";
    }
}