import sys
input = sys.stdin.readline

input = open("input.txt", 'r').readline

def bs(arr, v, l, h):
    if l > h:
        return
    mid = (l+h) // 2
    if arr[mid][0] > v:
        return bs(arr, v, l, mid-1)
    elif arr[mid][0] < v:
        return bs(arr, v, mid+1, h)
    else:
        return arr[mid][1]

N, M = map(int, input().split())
pws = [input().split() for _ in range(N)]
pws.sort()

for _ in range(M):
    addr = input().strip()
    print(bs(pws, addr, 0, N-1))
