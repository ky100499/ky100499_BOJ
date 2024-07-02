import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())
P = list(map(float, input().split()))

ans = M^1
for _ in range(N):
    ans = ans*P[0] + (1-ans)*P[2]
print(f'{ans*1000:.0f}\n{(1-ans)*1000:.0f}')
