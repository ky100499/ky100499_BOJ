import sys
input = sys.stdin.readline

import heapq

heap_pos, heap_neg = [], []
for _ in range(int(input())):
    x = int(input())
    if x > 0:
        heapq.heappush(heap_pos, x)
    elif x < 0:
        heapq.heappush(heap_neg, -x)
    else:
        if len(heap_pos) == len(heap_neg) == 0:
            print(0)
        elif len(heap_pos) == 0:
            print(-heapq.heappop(heap_neg))
        elif len(heap_neg) == 0:
            print(heapq.heappop(heap_pos))
        else:
            if heap_pos[0] < heap_neg[0]:
                print(heapq.heappop(heap_pos))
            else:
                print(-heapq.heappop(heap_neg))
