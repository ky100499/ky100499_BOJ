import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

s = deque()
ans = ''

for c in input().strip():
    if c.isalpha():
        ans += c
    elif c == '(':
        s.append(c)
    elif c in '*/':
        while s and s[-1] in '*/':
            ans += s.pop()
        s.append(c)
    elif c in '+-':
        while s and s[-1] != '(':
            ans += s.pop()
        s.append(c)
    elif c == ')':
        while s and s[-1] != '(':
            ans += s.pop()
        s.pop()

while s:
    ans += s.pop()

print(ans)
