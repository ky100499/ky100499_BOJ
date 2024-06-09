import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())
A = list(map(int, input().split()))
S = [0]*(N+1)
for i, a in enumerate(A):
    S[i+1] = S[i]+a

l, h = max(A), 30000
while l <= h:
    m = (l+h)//2

    cnt, ptr = 1, 0
    n = []
    for i in range(1, N+1):
        if S[i]-S[ptr] > m:
            cnt += 1
            n.append(i-1-ptr)
            ptr = i-1
    n.append(N-ptr)

    if cnt > M:
        l = m+1
    else:
        ans = [m, n]
        h = m-1

over = M - len(ans[1])
i = 0
while over:
    if ans[1][i] > 1:
        ans[1] = ans[1][:i] + [1, ans[1][i]-1] + ans[1][i+1:]
        over -= 1
    i += 1

print(ans[0])
print(*ans[1])
