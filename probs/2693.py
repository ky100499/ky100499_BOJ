import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

for _ in range(int(input())):
    A = sorted(map(int, input().split()))
    print(A[-3])
