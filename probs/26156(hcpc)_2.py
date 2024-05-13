import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

DIV = 10**9+7

N = int(input())
S = input().strip()

cnt = [0]*4

for i, c in enumerate(S):
    if c == 'R':
        cnt[0] = (cnt[0] + 2 ** i) % DIV
    elif c == 'O':
        cnt[1] = (cnt[1] + cnt[0]) % DIV
    elif c == 'C':
        cnt[2] = (cnt[2] + cnt[1]) % DIV
    elif c == 'K':
        cnt[3] = (cnt[3] + cnt[2]) % DIV

print(cnt[3])
