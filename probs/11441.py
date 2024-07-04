import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

input()
S = [0]
for a in map(int, input().split()):
    S.append(S[-1]+a)

for _ in range(int(input())):
    i, j = map(int, input().split())
    print(S[j]-S[i-1])
