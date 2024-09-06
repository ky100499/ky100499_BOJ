import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def bt(l):
    if len(l) == M:
        print(*l)
    else:
        for a in A:
            bt(l+[a])

N, M = map(int, input().split())
A = sorted(set(map(int, input().split())))
bt([])
