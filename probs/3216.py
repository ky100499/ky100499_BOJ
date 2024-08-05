import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

D, V, ans = 0, 0, 0
for _ in range(int(input())):
    d, v = map(int, input().split())
    V += v
    if D < V:
        ans += V-D
    D = max(D, V)
    D += d
print(ans)
