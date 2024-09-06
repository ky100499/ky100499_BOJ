import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def bt(res, p):
    global ans

    if p >= ans:
        return

    if not res:
        ans = min(ans, p)
    else:
        for i, n in enumerate(res):
            for a, d in S[n]:
                C[a] -= d
            bt(res[:i]+res[i+1:], p+max(1, C[n]))
            for a, d in S[n]:
                C[a] += d

N = int(input())
C = [0]+list(map(int, input().split()))
S = [[] for _ in range(N+1)]
for i in range(1, N+1):
    for _ in range(int(input())):
        S[i].append(tuple(map(int, input().split())))

ans = int(1e9)
bt(list(range(1, N+1)), 0)
print(ans)
