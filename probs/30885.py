import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

class Node:
    def __init__(self, n, i, p=None):
        self.n = n
        self.i = i
        self.prev = p
        self.next = None

    def __str__(self):
        return f'{self.n}\n{self.i}'

N = int(input())
L = cur = Node(0, 0)
for i, n in enumerate(map(int, input().split()), 1):
    tmp = Node(n, i, cur)
    cur.next = tmp
    cur = tmp
cur.next = L
L.prev = cur

while L.next.next is not L:
    cur = L.next
    while cur is not L:
        n = cur.n
        if cur.prev is not None and cur.prev is not L and cur.prev.n <= n:
            cur.n += cur.prev.n
            cur.prev = cur.prev.prev
            cur.prev.next = cur
        if cur.next is not None and cur.next is not L and cur.next.n <= n:
            cur.n += cur.next.n
            cur.next = cur.next.next
            cur.next.prev = cur
        cur = cur.next

print(L.next)
