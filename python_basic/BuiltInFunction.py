

# enumerate(iterable, start=0): a generator
# 'enumerate()' is equivalent to 'myEnumerate()' below
list1 = ['a', 'b', 'c', 'd']
def myEnumerate(sequence, start=0):
    n = start
    for elem in sequence:
        yield n, elem
        n += 1
enumerate_generator = myEnumerate(list1)    # return an object
# print(next(enumerate_generator))
# print(enumerate_generator.__next__())
# print('----')
# print(enumerate(list1).__next__())
for i, j in enumerate(list1):
    print(i, j)

# print(__builtins__.dict)


# eval(expression[, globals[, locals]])
a2 = 3
b2 = 3
c2 = eval('a2+b2')
# print(c2)

# exec(object[, globals[, locals]])
a3 = 4
b3 = 5
# exec('print(a3+b3)')
