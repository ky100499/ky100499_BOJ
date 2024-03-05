import sys
input = sys.stdin.readline

a, b = map(int, input().split())
squares = [i ** 2 for i in range(2, int(b ** 0.5) + 1)]
check = [True for _ in range(a, b+1)]

cnt = b - a + 1
for square in squares:
    i = int(a / square)
    if square * i < a:
        i += 1
    while square * i <= b:
        if check[square * i - a]:
            check[square * i - a] = False
            cnt -= 1
        i += 1

print(cnt)
