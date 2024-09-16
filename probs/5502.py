import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
S = input().rstrip()
l = len(S)

LCS = [[0]*(l+1) for _ in range(l+1)]
for i in range(1, l+1):
    for j in range(1, l+1):
        if S[i-1] == S[-j]:
            LCS[i][j] = LCS[i-1][j-1]+1
        else:
            LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1])
print(l - LCS[-1][-1])
