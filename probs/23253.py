import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())

for _ in range(M):
    k = int(input())
    A = list(map(int, input().split()))
    for i in range(k-1):
        if A[i] < A[i+1]:
            break
    else:
        continue
    print('No')
    break
else:
    print('Yes')
