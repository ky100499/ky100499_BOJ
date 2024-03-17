import sys
input = sys.stdin.readline

import heapq

heap = []
for _ in range(int(input())):
    x = int(input())
    if x == 0:
        print(-heapq.heappop(heap) if heap else 0)
    else:
        heapq.heappush(heap, -x)
