import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

R, C = map(int, input().split())
O = [[] for _ in range(C)]

for _ in range(R):
    S = input().rstrip()
    for i in range(1, 10):
        if str(i) in S:
            O[S.index(str(i))].append(i)
            break

ans = [0]*10
rank = 1
for i in reversed(range(C)):
    if O[i]:
        for o in O[i]:
            ans[o] = rank
        rank += 1
print(*ans[1:], sep='\n')
