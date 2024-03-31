cnt = 0
for _ in range(int(input())):
    w = input()
    check = [0]*26
    while w:
        idx = ord(w[0]) - ord('a')
        if check[idx]:
            break
        check[idx] = 1
        i = 1
        while i < len(w) and w[0] == w[i]:
            i += 1
        w = w[i:]
    else:
        cnt += 1
print(cnt)
