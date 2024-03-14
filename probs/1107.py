def abs(n):
    return n if n > 0 else -n

N = int(input())
M = int(input())
if M:
    qt = input().split()

    i = 0
    ans = 0
    while True:
        if len(str(N-i)) + i > abs(100-N):
            ans = abs(100-N)
            break

        if i <= N:
            for dgt in qt:
                if dgt in str(N-i):
                    break
            else:
                ans = len(str(N-i)) + i
                break
        for dgt in qt:
            if dgt in str(N+i):
                break
        else:
            ans = len(str(N+i)) + i
            break
        i += 1

    print(ans)

else:
    print(min(len(str(N)), abs(100-N)))
