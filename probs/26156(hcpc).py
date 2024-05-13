import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

DIV = 10**9+7

N = int(input())
S = input().strip()

dp = [0]*5

for c in S[::-1]:
    # '?'XX...ROCK or ' 'XX...ROCK
    dp[4] *= 2
    # '?'ROCK
    dp[4] += dp[3]

    if c == 'K':
        dp[0] += 1
    elif c == 'C':
        dp[1] += dp[0]
    elif c == 'O':
        dp[2] += dp[1]
    elif c == 'R':
        dp[3] += dp[2]

    dp = list(map(lambda x: x%DIV, dp))

print((dp[4]+dp[3]) % DIV)
