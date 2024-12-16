import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

class Trie:
    def __init__(self, name):
        self.name = name
        self.children = []
root = Trie('root')

def printTrie(depth, node):
    if depth:
        print('--'*(depth-1) + node.name)

    for nxt in sorted(node.children, key=lambda x: x.name):
        printTrie(depth+1, nxt)

N = int(input())
for _ in range(N):
    K, *info = input().split()
    node = root
    for food in info:
        for child in node.children:
            if child.name == food:
                node = child
                break
        else:
            child = Trie(food)
            node.children.append(child)
            node = child

printTrie(0, root)
