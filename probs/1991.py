import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def preord(node):
    if node is None:
        return
    print(node, end='')
    preord(nodes[node][0])
    preord(nodes[node][1])

def inord(node):
    if node is None:
        return
    inord(nodes[node][0])
    print(node, end='')
    inord(nodes[node][1])

def postord(node):
    if node is None:
        return
    postord(nodes[node][0])
    postord(nodes[node][1])
    print(node, end='')

N = int(input())
nodes = {chr(n + ord('A')): [] for n in range(N)}
for _ in range(N):
    p, c1, c2 = input().split()
    nodes[p].append(None if c1 == '.' else c1)
    nodes[p].append(None if c2 == '.' else c2)

preord('A')
print()
inord('A')
print()
postord('A')
print()
