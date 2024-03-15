import sys
input = sys.stdin.readline

for _ in range(int(input())):
    p = map(lambda x: x, input().strip())
    n = int(input())
    if n:
        X = list(map(int, input().strip()[1:-1].split(',')))
    else:
        input()
        X = []

    idx = 0
    for f in p:
        if f == 'R':
            idx = -1 if idx == 0 else 0
        elif f == 'D':
            if X:
                X.pop(idx)
            else:
                print('error')
                break
    else:
        print(f'[{",".join(map(str, X if idx == 0 else X[::-1]))}]')

