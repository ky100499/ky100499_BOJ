import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

S = input().rstrip()
l = len(S)

if len(set(S)) == 1:
    print(-1)
elif S == S[::-1]:
    print(l-1)
else:
    print(l)
