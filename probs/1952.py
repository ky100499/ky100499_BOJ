def snail(m, n):
    if m == n == 1:
        return 0
    elif n == 1:
        return 1
    elif m == 1:
        return 0
    elif m == n == 2:
        return 2
    elif n == 2:
        return 3
    elif m == 2:
        return 2
    else:
        return snail(m-2, n-2) + 4

print(snail(*map(int, input().split())))
