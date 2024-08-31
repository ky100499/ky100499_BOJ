import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

M = tuple(map(int, input().split()))
T = tuple(map(int, input().split()))
P = tuple(map(int, input().split()))

B, W = min(M[0], T[1], P[0]), min(M[1], T[0], P[1])
print(2*B if B==W else 2*min(B, W)+1)
