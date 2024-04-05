import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

d, n, m = map(int, input().split())

ipt = [0, d]
for _ in range(n):
    ipt.append(int(input()))
ipt.sort()

diff = []
for i in range(n+1):
    diff.append(ipt[i+1] - ipt[i])
print(diff)
