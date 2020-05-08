

# enumerate() generator
# 'enumerate()' is equivalent to 'myEnumerate()' below
list1 = ['a', 'b', 'c', 'd']
def myEnumerate(sequence, start=0):
    n = start
    for elem in sequence:
        yield n, elem
        n += 1
enumerate_generator = myEnumerate(list1)    # return an object
print(next(enumerate_generator))
print(enumerate_generator.__next__())
print('----')
print(enumerate(list1).__next__())
for i, j in enumerate(list1):
    print(i, j)
