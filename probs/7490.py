def bt(arr, ans):
    # print(arr, ans)
    if arr:
        bt(arr[1:], ans+[' ', arr[0]])
        bt(arr[1:], ans+['+', arr[0]])
        bt(arr[1:], ans+['-', arr[0]])
    else:
        s = 0
        tmp = 0
        plus = True
        for v in ans:
            if v == ' ':
                tmp = 10*tmp
            elif v == '+':
                s += tmp if plus else -tmp
                tmp = 0
                plus = True
            elif v == '-':
                s += tmp if plus else -tmp
                tmp = 0
                plus = False
            else:
                tmp += v
        if s+(tmp if plus else -tmp) == 0:
            print(*ans, sep='')

for _ in range(int(input())):
    N = int(input())
    bt(list(range(2, N+1)), [1])
    print()
