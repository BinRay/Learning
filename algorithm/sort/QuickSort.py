def quickSort( arr ):
    # 基线条件
    if len(arr) < 2:
        return arr
    # 递归条件
    else:
        pivot = arr[0]
        less = [ i for i in arr[1:] if i <= pivot ]
        greater = [ i for i in arr[1:] if i > pivot ]
        return quickSort(less) + pivot + quickSort(greater)

arr = [3, 4, 5, 2, 1, 0, -1, -5, 10, 8, 3, 4]
print(quickSort(arr))