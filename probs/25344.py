import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from functools import reduce

def gcd(a, b):
    while b:
        a, b = b, a%b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

N = int(input())
T = list(map(int, input().split()))
print(reduce(lcm, T, 1))
