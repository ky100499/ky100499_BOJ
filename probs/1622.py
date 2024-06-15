while True:
    try:
        a, b = input(), input()
    except:
        break

    i, j = 0, 0
    a, b = map(sorted, [a, b])
    ans = ''
    while i < len(a) and j < len(b):
        if a[i] > b[j]:
            j += 1
        elif a[i] < b[j]:
            i += 1
        else:
            ans += a[i]
            i, j = i+1, j+1
    print(ans)
