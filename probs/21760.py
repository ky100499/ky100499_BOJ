import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

for _ in range(int(input())):
    N, M, K, D = map(int, input().split())
    x = N*M*(K*(M-1)+(N-1)*M) // 2
    if D < x:
        print(-1)
    else:
        print(D//x*x)
