for _ in range(int(input())):
    s = input()
    cnt = 0
    for c in s:
        if c == '(':
            cnt += 1
        elif c == ')':
            cnt -= 1
        if cnt < 0:
            break
    if cnt == 0:
        print("YES")
    else:
        print("NO")
