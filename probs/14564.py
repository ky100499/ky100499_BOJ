import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N, M, A = map(int, input().split())

q = deque([i+1 for i in range(N)])
q.rotate(1-A)

while True:
    a = int(input())
    if a == M//2+1:
        print(0)
        break

    q.rotate(M//2+1-a)
    print(q[0])
