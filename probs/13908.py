import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())
A = input().split()

cnt = 0
for i in range(10**N):
    x = str(i)
    while len(x) < N:
        x = '0'+x
    for a in A:
        if a not in x:
            break
    else:
        cnt += 1
print(cnt)
