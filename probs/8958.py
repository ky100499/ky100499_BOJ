import sys
input = sys.stdin.readline

for _ in range(int(input())):
    ipt = input().strip().split('X')
    if ipt:
        print(sum(map(lambda x: (len(x) ** 2 + len(x)) // 2, ipt)))
    else:
        print(0)
