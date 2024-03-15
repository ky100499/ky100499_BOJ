import sys
input = sys.stdin.readline

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

N = int(input())
heap = []
for _ in range(N):
    ipt = int(input())
    if ipt == 0:
        print(pop(heap))
    else:
        push(heap, ipt)
