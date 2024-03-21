A, B = map(int, input().split())

cnt = 1
while B > 0:
    if A == B:
        print(cnt)
        break
    elif A > B:
        print(-1)
        break

    if B % 2 == 0:
        B //= 2
        cnt += 1
    elif B % 10 == 1:
        B //= 10
        cnt += 1
    else:
        print(-1)
        break
