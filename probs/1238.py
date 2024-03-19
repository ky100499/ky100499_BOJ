import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M, X = map(int, input().split())

T = [[] for _ in range(N+1)]
for _ in range(M):
    s, e, t = map(int, input().split())
    T[s].append((e, t))

time_go = [100000000] * (N+1)
for i in range(1, N+1):
    if i == X:
        continue

    while i != X:
        nxt = None
        for e, t in T[i]:
            time_go[e] = min(time_go[e], time_go[i]+t)
            if nxt is None or time_go[nxt] > time_go[e]:
                nxt = e
        i = nxt
print(time_go)
