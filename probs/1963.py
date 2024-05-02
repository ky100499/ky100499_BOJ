import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

isPrime = [1]*10000
isPrime[0], isPrime[1] = 0, 0
for i in range(2, 10000):
    if isPrime[i]:
        j = i*i
        while j < 10000:
            isPrime[j] = 0
            j += i

for i in range(int(input())):
    s, t = map(int, input().split())
    q = deque([(s, 0)])
    visited = [0]*10000
    while q:
        s, c = q.popleft()

        if s == t:
            print(c)
            break

        if visited[s]:
            continue
        visited[s] = 1

        for i in range(4):
            n = 10**i
            base = s//(10*n)*(10*n)+s%n
            for j in range(10):
                tmp = base + j*n
                if tmp > 999 and not visited[tmp] and isPrime[tmp]:
                    q.append((tmp, c+1))
    else:
        print('Impossible')
