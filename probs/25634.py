import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
init = 0

for i in range(N):
    if B[i] == 1:
        init += A[i]

ans, s = -10000, 0
for i in range(N):
    s += -A[i] if B[i] else A[i]
    ans = max(ans, s)
    s = max(s, 0)
print(init + ans)
