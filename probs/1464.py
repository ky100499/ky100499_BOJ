import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

s = ''
for c in input().rstrip():
    if s and c > s[0]:
        s += c
    else:
        s = c+s

print(s)
