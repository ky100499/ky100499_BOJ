import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

input = open('input.txt', 'r').readline

def printDir(d, prefix):
    for p, subs in sorted(d.items()):
        print(prefix+p)
        printDir(subs, prefix+' ')

dirs = {}

for _ in range(int(input())):
    path = input().rstrip().split('\\')
    if path[0] not in dirs:
        dirs[path[0]] = {}
    p = dirs[path[0]]
    for d in path[1:]:
        if d not in p:
            p[d] = {}
        p = p[d]

printDir(dirs, '')
