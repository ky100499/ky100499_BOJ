import sys
input = sys.stdin.readline

N, M = map(int, input().split())
cards = list(map(int, input().split()))

s_max = 0
for i in range(N-2):
    for j in range(i+1, N-1):
        for k in range(j+1, N):
            s = sum([cards[i], cards[j], cards[k]])
            if s_max < s and s <= M:
                s_max = s
print(s_max)
