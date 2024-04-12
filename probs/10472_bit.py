import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

ch = [
    0b110100000,
    0b111010000,
    0b011001000,
    0b100110100,
    0b010111010,
    0b001011001,
    0b000100110,
    0b000010111,
    0b000001011,
]

for _ in range(int(input())):
    b = 0
    for _ in range(3):
        for c in input().strip():
            b = b*2 + int(c=='*')

    visited = [0]*(2**9)

    q = deque([(b, 0)])
    while q:
        b, c = q.popleft()
        if b == 0:
            print(c)
            break

        if visited[b]:
            continue
        visited[b] = 1

        for i in range(9):
            q.append((b^ch[i], c+1))
