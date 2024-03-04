import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    a, b = map(int, input().split())
    a %= 10
    b %= 4
    ans = 1
    if a == 0:
        print(10)
    elif b == 0:
        print(a ** 4 % 10)
    else:
        for _ in range(b):
            ans = (ans * a) % 10
        print(ans)
