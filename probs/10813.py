N, M = map(int, input().split())
ans = list(range(N+1))
for _ in range(M):
    i, j = map(int, input().split())
    ans[i], ans[j] = ans[j], ans[i]
print(*ans[1:])
