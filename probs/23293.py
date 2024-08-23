import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import defaultdict as dd

T, N = map(int, input().split())
cheat, ban = [], set()
P = [[],]
for i in range(1, N+1):
    P.append([1, dd(int)])   # pos, items

for _ in range(T):
    n, p, c, *args = input().split()
    n, p, *args = map(int, [n, p, *args])

    if c == 'M':
        P[p][0] = args[0]
    elif c == 'F':
        P[p][1][args[0]] += 1
        if args[0] != P[p][0]:
            cheat.append(n)
    elif c == 'C':
        if P[p][1][args[0]] * P[p][1][args[1]]:
            P[p][1][args[0]] -= 1
            P[p][1][args[1]] -= 1
        else:
            if P[p][1][args[0]]:
                P[p][1][args[0]] -= 1
            if P[p][1][args[1]]:
                P[p][1][args[1]] -= 1
            cheat.append(n)
    elif c == 'A':
        if P[p][0] != P[args[0]][0]:
            cheat.append(n)
            ban.add(p)

if cheat:
    print(len(cheat))
    print(*cheat)
else:
    print(0)

if ban:
    print(len(ban))
    print(*sorted(ban))
else:
    print(0)
