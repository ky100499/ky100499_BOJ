import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

MOD = int(1e9)+7

def c(n, r):
    res = 1
    for i in range(1, r+1):
        res = res * (n-r+i) // i
    return res % MOD

N = int(input())
print(c(2*N, N), N*N)
