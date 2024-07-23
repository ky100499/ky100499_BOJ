import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())
A = set(list(map(int, input().split()))[:M])
F = set(map(int, input().split()))

print(len(A-F))
