# 空函数def emptyFunc():    pass# 返回较大数def larger(num1, num2):    """    这里是函数的说明文档，这个函数用于返回两数之间的较大者    :param num1:  int    :param num2:  int    :return: int    """    return num1 if num1 > num2 else num2# print(larger(5, 6))# 值传递演示: 交换数据a3 = 5b3 = 6def swap(a, b):    a, b = b, a    return a, b# print(swap(a3, b3))# print(a3, b3)# 关键字参数传递，可以不必严格遵照形参顺序# print(swap(b=b3, a=a3))# 默认参数应用def defaultParam(a, b="default b"):    return a, b# print(defaultParam("outside a"))# 可变参数：形参前添加一个 '*'，args被解析为一个元组def variableArgs(*args, b):    print(args)# variableArgs("outside param1", "outside param2", b="param b")# 可变参数：形参前添加两个'*'，kwargs被解析为一个字典def variableKwargs(a, **kwargs):    print(kwargs)# variableKwargs("outside a", b="outside b", c="outside c")# 逆向参数收集，同样适用与字典def reverseVariableKwargs(a, b, *args):    print(a)    print(args)data = [    "this is the first line",    "this is the second line",    "this is the third line",    "this is the forth line"]# reverseVariableKwargs(*data)# 嵌套函数def outDef():    name = "global function local name"    def inDef():        # 引用上一级函数的name        name = "local function local name"        # print(name)        def inInDef():            # 引用上一级函数的变量            nonlocal name            print(name)        inInDef()    inDef()# outDef()# 函数赋值(相同原理可作为另一个函数参数或返回值)def aFunc():    print("this is defined in aFunc")bFunc = aFunc# bFunc()# 闭包函数: 外部函数做一些嵌套函数的初始化工作，并将内部函数返回，主流程调用可以得到初始化后的内部函数，是的调用更加简单易读。def nthPower(exp):    def exponent(base):        return base ** exp    return exponentsquare = nthPower(2)cube = nthPower(3)# print(square(2))# print(cube(2))# lambda表达式（匿名函数）: 只有一行表达式的函数，精简函数定义，如变量一般用完即弃lambdafunc = lambda a, b: a + bprint(lambdafunc(1, 2))