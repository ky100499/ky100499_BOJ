import sys
input = sys.stdin.readline

N, M = map(int, input().split())
arr = list(map(int, input().split()))
s = [0] * (N+1)
for i in range(1, N+1):
    s[i] = s[i-1] + arr[i-1]

for _ in range(M):
    i, j = map(int, input().split())
    print(s[j] - s[i-1])
