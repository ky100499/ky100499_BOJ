import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

A, B = (input().strip() for _ in range(2))

dp = [[0]*(len(A)+1) for _ in range(len(B)+1)]
for i, b in enumerate(B):
    for j, a in enumerate(A):
        if a == b:
            dp[i+1][j+1] = dp[i][j]+1
        else:
            dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1])

i, j = len(B), len(A)
print(ans := dp[i][j])
if ans:
    ans = []
    while dp[i][j]:
        if dp[i][j] == dp[i-1][j]:
            i -= 1
        elif dp[i][j] == dp[i][j-1]:
            j -= 1
        else:
            ans.append(B[i-1])
            i -= 1
            j -= 1
    print(''.join(reversed(ans)))
