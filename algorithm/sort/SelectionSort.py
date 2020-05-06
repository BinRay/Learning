
def selectionSort(arr):
    for i in range(len(arr)-1):
        smallest = arr[i]
        for j in range(i+1, len(arr)):
            if arr[i] > arr[j]:
                temp = arr[i]
                arr[i] = arr[j]
                arr[j] = temp
    return arr


arr = [3, 4, 5, 2, 1, 0, -1, -5, 10, 8, 3, 4]

print(selectionSort(arr))
