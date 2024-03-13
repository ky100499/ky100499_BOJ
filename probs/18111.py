import sys
input = sys.stdin.readline

from collections import Counter

N, M, B = map(int, input().split())
h_list = []
for _ in range(N):
    h_list.extend(list(map(int, input().split())))

cnt = Counter(h_list)

goal = min(max(h_list), (sum(h_list) + B) // (N * M))
ans_t, ans_h = 2 * 256 * N * M, 0
while goal >= 0:
    t = 0
    for h in cnt:
        if h > goal:
            t += 2 * cnt[h] * (h - goal)
        else:
            t += cnt[h] * (goal - h)
    if ans_t > t:
        ans_t = t
        ans_h = goal
    else:
        break

    goal -= 1

print(ans_t, ans_h)
