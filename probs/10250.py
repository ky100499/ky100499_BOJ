import sys
input = sys.stdin.readline

for _ in range(int(input())):
    H, W, N = map(int, input().split())
    print(f'{(N-1)%H+1}{(N-1)//H+1:02}')
