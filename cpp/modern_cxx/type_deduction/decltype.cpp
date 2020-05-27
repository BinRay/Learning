//
// Created by lbinr on 2020/5/26.
//

void k_decltype(){

    int x = 0;          // 整型变量

    decltype(x)     x1;      // 推导为int，x1是int
    decltype(x)&    x2 = x;    // 推导为int，x2是int&，引用必须赋值
    decltype(x)*    x3;      // 推导为int，x3是int*
    decltype(&x)    x4;      // 推导为int*，x4是int*
    decltype(&x)*   x5;      // 推导为int*，x5是int**
    decltype(x2)    x6 = x2;  // 推导为int&，x6是int&，引用必须赋值

}
