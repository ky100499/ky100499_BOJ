import sys
input = sys.stdin.readline

while True:
    x = sum(map(int, input().split()))
    if x==0:
        break
    print(x)
