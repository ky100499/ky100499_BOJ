import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

for _ in range(int(input())):
    N, *A = map(int, input().split())
    A.sort()

    s = [0]*(N+1)
    for i in range(N):
        s[i+1] = s[i]+A[i]

    ans = 0
    for i in range(2, N+1):
        tmp = 10**8
        for j in range(i, N+1):
            tmp = min(tmp, A[j-1]*i - (s[j]-s[j-i]))
        ans += tmp
    print(ans)
