import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

def bt(x):
    if not x:
        return
    else:
        bt(x-1)
        print(x)
        bt(x-1)

N = int(input())
print((1<<N)-1)
bt(N)
print(N)
