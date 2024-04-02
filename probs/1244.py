import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
switch = [0] + list(map(int, input().split()))
for _ in range(int(input())):
    s, n = map(int, input().split())
    if s == 1:
        i = n
        while i <= N:
            switch[i] ^= 1
            i += n
    else:
        switch[n] ^= 1
        l, h = n-1, n+1
        while 0 < l <= N and 0 < h <= N and switch[l] == switch[h]:
            switch[l] ^= 1
            switch[h] ^= 1
            l -= 1
            h += 1
for i, s in enumerate(switch[1:]):
    print(s, end=('\n' if (i+1) % 20 == 0 else ' '))
