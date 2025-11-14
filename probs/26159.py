import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

input = open('input.txt', 'r').readline

from heapq import heappop, heappush, heapify

MOD = int(1e9)+7

def dfs(u, p):
    for v in G[u]:
        if v != p:
            dfs(v, u)
            C[u] += C[v]
            heappush(B, -C[v] * (N - C[v]))

N = int(input())
G = [[] for _ in range(N+1)]
for _ in range(N-1):
    u, v = map(int, input().split())
    G[u].append(v)
    G[v].append(u)
A = list(map(int, input().split()))
heapify(A)

B, C = [], [1]*(N+1)
dfs(1, 0)

ans = 0
while A:
    ans -= heappop(A) * heappop(B)
    ans %= MOD
print(ans)
