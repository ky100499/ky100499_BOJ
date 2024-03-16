import sys
input = sys.stdin.readline

from collections import defaultdict as dd

def push(h, v):
    h.append(v)
    i = len(h) - 1
    while i > 0 and h[(i-1)//2] > h[i]:
        h[(i-1)//2], h[i] = h[i], h[(i-1)//2]
        i = (i-1) // 2

def pop(h):
    if len(h) == 0: return 0
    elif len(h) == 1: return h.pop()
    ret = h[0]
    h[0] = h.pop()
    i, child = 0, 1
    while child < len(h):
        if child + 1 < len(h) and h[child] > h[child+1]:
            child += 1
        if h[i] > h[child]:
            h[i], h[child] = h[child], h[i]
            i, child = child, child * 2 + 1
        else:
            break
    return ret

for _ in range(int(input())):
    minh, maxh = [], []
    length = 0
    cnt = dd(int)
    for _ in range(int(input())):
        op, n = input().split()
        n = int(n)

        if op == 'D' and length:
            if n == 1:
                x = 0
                while maxh:
                    x = -pop(maxh)
                    if cnt[x] != 0:
                        cnt[x] -= 1
                        break
                if maxh:
                    length -= 1
                else:
                    length = 0
                    minh = []
            else:
                x = 0
                while minh:
                    x = pop(minh)
                    if cnt[x] != 0:
                        cnt[x] -= 1
                        break
                if minh:
                    length -= 1
                else:
                    length = 0
                    maxh = []
        elif op == 'I':
            push(minh, n)
            push(maxh, -n)
            cnt[n] += 1
            length += 1

    if length:
        minv, maxv = 0, 0
        while True:
            minv = pop(minh)
            if cnt[minv] != 0:
                break
        while True:
            maxv = -pop(maxh)
            if cnt[maxv] != 0:
                break
        print(f'{maxv} {minv}')
    else:
        print('EMPTY')
