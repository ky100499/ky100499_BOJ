import sys
input = sys.stdin.readline

def binarySearch(x, arr, low, high):
    mid = (low + high) // 2
    if low > high:
        return -1
    elif arr[mid] < x:
        return binarySearch(x, arr, mid+1, high)
    elif arr[mid] > x:
        return binarySearch(x, arr, low, mid-1)
    else:
        return mid

N = int(input())
A = list(sorted(map(int, input().split())))
M = int(input())

for i in map(int, input().split()):
    print(1 if binarySearch(i, A, 0, N-1) >= 0 else 0)
