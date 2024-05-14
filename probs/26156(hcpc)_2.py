import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

input = open('input.txt', 'r').readline

def power(b, p):
    if p == 0:
        return 1
    if p == 1:
        return b

    x = power(b, p//2) % DIV
    if p % 2:
        return (x * x * b) % DIV
    else:
        return (x * x) % DIV

DIV = 10**9+7

N = int(input())
S = input().strip()

cnt = [0]*4

for i, c in enumerate(S):
    if c == 'R':
        cnt[0] = (cnt[0] + power(2, i)) % DIV
    elif c == 'O':
        cnt[1] = (cnt[1] + cnt[0]) % DIV
    elif c == 'C':
        cnt[2] = (cnt[2] + cnt[1]) % DIV
    elif c == 'K':
        cnt[3] = (cnt[3] + cnt[2]) % DIV

print(cnt[3])
