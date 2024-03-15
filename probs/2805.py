import sys
input = sys.stdin.readline

N, M = map(int, input().split())
heights = list(map(int, input().split()))

low, high = 0, max(heights)
ans = 0
while low <= high:
    h = (low + high) // 2
    s = 0
    for height in heights:
        s += height - h if height > h else 0
    if s < M:
        high = h-1
    else:
        ans = h
        low = h+1
print(ans)
