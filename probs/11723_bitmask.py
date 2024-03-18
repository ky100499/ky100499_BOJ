import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

S = [0] * 21
for _ in range(int(input())):
    ipt = input().split()
    if ipt[0] == 'add':
        x = int(ipt[1])
        S[x] = 1
    elif ipt[0] == 'remove':
        x = int(ipt[1])
        S[x] = 0
    elif ipt[0] == 'check':
        x = int(ipt[1])
        print(S[x])
    elif ipt[0] == 'toggle':
        x = int(ipt[1])
        S[x] ^= 1
    elif ipt[0] == 'all':
        S = [1] * 21
    elif ipt[0] == 'empty':
        S = [0] * 21
