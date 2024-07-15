import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def bt(mts, t, cnt):
    global ans
    ans = max(ans, cnt)

    for i, (s, e, n) in enumerate(mts):
        if t <= s:
            bt(mts[i+1:], e, cnt+n)

N = int(input())
M = [list(map(int, input().split())) for _ in range(N)]
M.sort()

ans = 0
bt(M, 0, 0)
print(ans)
