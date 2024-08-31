import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
H = list(map(int, input().split()))

S = 2*N + 2*sum(H) + H[0] + H[-1]
for i in range(N-1):
    S += abs(H[i]-H[i+1])
print(S)
