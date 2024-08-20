import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
A = sorted([int(input()) for _ in range(N)], reverse=True)

for i in range(N-2):
    if A[i] < A[i+1]+A[i+2]:
        print(A[i]+A[i+1]+A[i+2])
        break
else:
    print(-1)
