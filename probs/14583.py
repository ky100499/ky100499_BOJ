import sys
from math import sqrt
input = sys.stdin.readline

input = open('input.txt', 'r').readline

W, H = map(float, input().split())

x = (W * sqrt(W*W+H*H) - W*W) / H
s, c = x / sqrt(W*W+x*x), W / sqrt(W*W+x*x)

print(f'{sqrt(W*W+x*x)/2:.2f} {x*c + (sqrt(W*W+H*H)-W)*s:.2f}')
