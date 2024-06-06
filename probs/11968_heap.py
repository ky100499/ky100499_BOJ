import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappop, heapify

N = int(input())

E = []
for _ in range(N):
    E.append(-int(input()))
B = list(filter(lambda x: x not in E, range(-2*N, 0)))

heapify(B)
heapify(E)

cnt = 0
while E:
    if E[0] > B[0]:
        cnt += 1
        heappop(B)
    heappop(E)
print(cnt)
