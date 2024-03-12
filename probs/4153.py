import sys
input = sys.stdin.readline

while True:
    lens = list(sorted(map(int, input().split())))
    if sum(lens) == 0:
        break
    elif lens[0] ** 2 + lens[1] ** 2 == lens[2] ** 2:
        print('right')
    else:
        print('wrong')
