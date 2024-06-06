import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
f = list(map(int, input().split()))

ans = 0
i, j = 0, 0
cnt = [0]*10
k = 0
while j < N:
    if cnt[f[j]] == 0:
        k += 1
    cnt[f[j]] += 1

    if k < 3:
        ans = max(ans, j-i+1)
    else:
        cnt[f[i]] -= 1
        if cnt[f[i]] == 0:
            k -= 1
        i += 1
    j += 1

print(ans)
