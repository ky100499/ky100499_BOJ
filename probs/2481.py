import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque, defaultdict as dd

INF = int(1e9)

def bit_count(n):
    cnt = 0
    while n:
        cnt += n&1
        n >>= 1
    return cnt

N, K = map(int, input().split())
C = [0]*(N+1)
C_idx = dd(list)
C_set = set()
for i in range(1, N+1):
    ipt = int(input(), 2)
    C[i] = ipt
    C_idx[ipt].append(i)
    C_set.add(ipt)

dist = {c:INF for c in C_set}
dist[C[1]] = 0
prev = {c:-1 for c in C_set}
q = deque([C[1]])
while q:
    c = q.popleft()
    for i in range(K):
        nc = c^(1<<i)
        if nc in C_set and dist[nc] > dist[c]+1:
            dist[nc] = dist[c]+1
            prev[nc] = c
            q.append(nc)

for _ in range(int(input())):
    c = C[int(input())]
    if prev[c] == -1:
        print(-1)
    else:
        ans = []
        while c != -1:
            ans.append(C_idx[c][0])
            c = prev[c]
        print(*ans[::-1])
