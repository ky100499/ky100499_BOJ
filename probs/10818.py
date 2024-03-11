import sys
input = sys.stdin.readline

input()
ipt = list(sorted(map(int, input().split())))
print(ipt[0], ipt[-1])
