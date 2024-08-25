import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

S = input().rstrip()
l = len(S)

c, p = 1, 1
for i in range(l//2+1):
    if S[i] != S[0]:
        c = 0
    if S[i] != S[-i-1]:
        c = 0
        p = 0
        break

if p and c:
    print(-1)
elif p:
    print(l-1)
else:
    print(l)
