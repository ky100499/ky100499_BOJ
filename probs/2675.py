import sys
input = sys.stdin.readline

for _ in range(int(input())):
    ipt = input().split()
    ipt[0] = int(ipt[0])
    for c in ipt[1]:
        print(c * ipt[0], end='')
    print()
