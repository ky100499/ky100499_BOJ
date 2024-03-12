N = int(input())

ans = 0
for i in range(1, 1_000_000):
    if i + sum(map(int, str(i))) == N:
        ans = i
        break
    elif i > N:
        break
print(ans)
