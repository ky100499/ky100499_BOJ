import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

base, *var = input().split()
var = list(map(lambda x:x[:-1], var))

for v in var:
    name = ''
    s = deque()
    i = 0
    while i < len(v):
        if v[i].isalpha():
            name += v[i]
        elif v[i] == '[':
            s.append('[]')
            i += 1
        else:
            s.append(v[i])
        i += 1

    print(base, end='')
    while s:
        print(s.pop(), end='')
    print(f' {name};')
