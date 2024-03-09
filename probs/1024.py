N, L = map(int, input().split())

for l in range(L, 101):
    if l * (l - 1) // 2 > N:
        print(-1)
        break
    elif l % 2 and N % l == 0:
        mid = N // l
        print(' '.join(map(str, range(mid - l // 2, mid + l // 2 + 1))))
        break
    elif l % 2 == 0 and (N + l // 2) % l == 0:
        mid = (N + l // 2) // l
        print(' '.join(map(str, range(mid - l // 2, mid + l // 2))))
        break
else:
    print(-1)
