import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

for _ in range(int(input())):
    N, *A = map(int, input().split())
    A.sort()

    s = 0
    for i in range(2, N+1):
        tmp = 10**8
        for j in range(N-i+1):
            a = A[j:j+i]
            tmp = min(tmp, i*a[-1]-sum(a))
        s += tmp
    print(s)
