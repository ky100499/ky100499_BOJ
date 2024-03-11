import sys
input = sys.stdin.readline

while True:
    ans = sum(map(int, input().split()))
    if ans == 0: break
    print(ans)
