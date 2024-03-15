import sys
input = sys.stdin.readline

def binarySearch(arr, v):
    low, high = 0, len(arr) - 1
    while True:
        if low > high:
            return -1

        mid = (low + high) // 2
        if arr[mid][:len(v)] < v:
            low = mid+1
        elif arr[mid][:len(v)] > v:
            high = mid-1
        else:
            return mid

N, M = map(int, input().split())
S = []
for _ in range(N):
    S.append(input().strip())
S.sort()

cnt = 0
for _ in range(M):
    ipt = input().strip()
    if binarySearch(S, ipt) >= 0:
        cnt += 1
print(cnt)
