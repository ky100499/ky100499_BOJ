import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

S = set()
for _ in range(int(input())):
    ipt = input().split()
    if ipt[0] == 'add':
        x = int(ipt[1])
        S.add(x)
    elif ipt[0] == 'remove':
        x = int(ipt[1])
        S.discard(x)
    elif ipt[0] == 'check':
        x = int(ipt[1])
        print(1 if x in S else 0)
    elif ipt[0] == 'toggle':
        x = int(ipt[1])
        S.discard(x) if x in S else S.add(x)
    elif ipt[0] == 'all':
        S = set(range(1, 21))
    elif ipt[0] == 'empty':
        S = set()
