import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
S = [1] * (N+1)
zeros = []
for i in range(N):
    ipt = float(input())
    if ipt == 0:
        zeros.append(i+1)
    else:
        S[i+1] = S[i] * ipt

ans = 0
zero = 0
for i in range(1, N+1):
    if i in zeros:
        zero = i
    else:
        ans = max(ans, S[i] / min(S[zero:i]))
print(f'{ans:.3f}')
