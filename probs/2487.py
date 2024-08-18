import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from functools import reduce

def gcd(a, b):
    if a < b:
        a, b = b, a
    while b:
        a, b = b, a%b
    return a

def lcm(a, b):
    return a*b//gcd(a, b)

N = int(input())
A = list(map(lambda x: int(x)-1, input().split()))
C = [0]*N

for i in range(N):
    if C[i]:
        continue

    C[i] = 1
    a, b = i, i
    while True:
        b = A[a]
        if C[b]:
            break
        else:
            C[b] = C[a]+1
            a = b
    while a != b:
        C[b] = C[a]
        b = A[b]

print(reduce(lcm, set(C), 1))
