import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

S = input().strip()
l = len(S)
dp = [[0] * l for _ in range(26)]
for i, c in enumerate(S):
    if i > 0:
        for j in range(26):
            dp[j][i] = dp[j][i-1]
    dp[ord(c) - ord('a')][i] += 1

for _ in range(int(input())):
    a, l, r = input().split()
    l, r = int(l), int(r)

    idx = ord(a) - ord('a')
    if l == 0:
        print(dp[idx][r])
    else:
        print(dp[idx][r] - dp[idx][l-1])
