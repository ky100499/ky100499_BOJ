input = open('input.txt', 'r').readline

from collections import deque

N, M = map(int, input().split())
moves = [[], []]
for _ in range(N+M):
    x, y = map(int, input().split())
    moves[0].append(x)
    moves[1].append(y)

cnt = [10000] * 101
cnt[1] = 0
q = deque([1])
while q:
    i = q.popleft()
    if i in moves[0]:
        ni = moves[1][moves[0].index(i)]
        if cnt[i] < cnt[ni]:
            cnt[ni] = cnt[i]
            q.append(ni)
    else:
        for d in range(1, 7):
            ni = i + d
            if ni <= 100 and cnt[i]+1 < cnt[ni]:
                cnt[ni] = cnt[i] + 1
                q.append(ni)
print(cnt[100])
