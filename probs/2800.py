import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

s = deque()
prs = []

f = list(input().rstrip())
for i, c in enumerate(f):
    if c == '(':
        f.append(i)
    elif c == ')':
        prs.append((f.pop(), i))

ans = ['']*(1<<(l:=len(prs)))
for i in range(1<<l):
    for j in range(l):
        if i & (1<<j):
            f[prs[j][0]] = f[prs[j][1]] = ''
    ans[i] = ''.join(f)
    for j in range(l):
        if i & (1<<j):
            f[prs[j][0]] = '('
            f[prs[j][1]] = ')'

print(*sorted(set(ans[1:])), sep='\n')
