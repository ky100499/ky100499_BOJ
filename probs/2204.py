import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

while True:
    N = int(input())
    if not N:
        break

    ans = 'z'*20
    for _ in range(N):
        ipt = input().rstrip()
        for i in range(min(len(ans), len(ipt))):
            if ord(ans[i]) | 32 < ord(ipt[i]) | 32:
                break
            elif ord(ans[i]) | 32 > ord(ipt[i]) | 32:
                ans = ipt
                break
        else:
            if len(ans) > len(ipt):
                ans = ipt
    print(ans)
