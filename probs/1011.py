import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    x, y = map(int, input().split())
    d = y - x

    n = int(d ** 0.5)
    if n ** 2 == d:
        print(2 * n - 1)
    elif d - n ** 2 <= n:
        print(2 * n)
    else:
        print(2 * n + 1)
