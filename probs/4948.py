import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

MAX = 123456

primes = [1]*(MAX*2+1)
primes[0] = primes[1] = 0
for i in range(2, MAX*2+1):
    if primes[i]:
        for j in range(i*i, MAX*2+1, i):
            primes[j] = 0

while n:=int(input()):
    cnt = 0
    for i in range(n+1, 2*n+1):
        cnt += primes[i]
    print(cnt)
