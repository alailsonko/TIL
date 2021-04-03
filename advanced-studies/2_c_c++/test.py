
def arrayManipulation(n, queries):
    arr = [0]*n
    for i in queries:
        for j in range(i[0], i[1] + 1):
            arr[j - 1] += i[2]
            print(arr[j - 1])
    return (arr)


myArray = [
    [1, 2, 3],
    [1, 2, 8],
    [4, 8, 6],
    [1, 2, 8],
    [1, 2, 7],
    [1, 2, 3],
    [3, 4, 4353],
    [1, 2, 3],
    [1, 2, 3],
]

arrayManipulation(8, myArray)
