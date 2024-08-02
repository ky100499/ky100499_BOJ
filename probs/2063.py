import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

for _ in range(int(input())):
    N = int(input())
    A = sorted(map(float, input().split()))
    for i in range(1, N):
        if A[i] <= sum(A[:i]):
            print('YES')
            break
    else:
        print('NO')
