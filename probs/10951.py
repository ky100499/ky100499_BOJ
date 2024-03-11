import sys
input = sys.stdin.readline

while True:
    try:
        ipt = input().split()
        if len(ipt) != 2: break
        print(sum(map(int, ipt)))
    except EOFError:
        break
