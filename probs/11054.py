input = open('input.txt', 'r').readline

N = int(input())
A = list(map(int, input().split()))

dp = [0]*N
dp_rev = [0]*N

for i in range(N):
    for j in range(i):
        if A[i] > A[j]:
            dp[i] = max(dp[i], dp[j]+1)
for i in range(N-1, -1, -1):
    for j in range(i+1, N):
        if A[i] > A[j]:
            dp_rev[i] = max(dp_rev[i], dp_rev[j]+1)
print(max(1+dp[i]+dp_rev[i] for i in range(N)))
