import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

input = open('input.txt', 'r').readline

def push(k):
    node = root
    while True:
        if k < node:
            if children[node][0] is None:
                children[node][0] = k
                children[k] = [None, None]
                break
            else:
                node = children[node][0]
        else:
            if children[node][1] is None:
                children[node][1] = k
                children[k] = [None, None]
                break
            else:
                node = children[node][1]

def postord(node):
    if node is None:
        return
    postord(children[node][0])
    postord(children[node][1])
    print(node)

try:
    root = int(input())
except ValueError:
    exit(0)
children = {root: [None, None]}
while True:
    try:
        ipt = int(input())
        push(ipt)
    except (ValueError, EOFError):
        break
postord(root)
