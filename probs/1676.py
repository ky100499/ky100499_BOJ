N = int(input())
ans, i = 0, 1
while 5 ** i <= N:
    ans += N // (5 ** i)
    i += 1
print(ans)
