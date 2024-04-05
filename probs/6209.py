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

for _ in range(m):
    i = diff.index(min(diff))
    if i == 0:
        diff = [diff[0]+diff[1]] + diff[2:]
    elif i == len(diff)-1:
        diff = diff[:-2] + [diff[-2]+diff[-1]]
    elif diff[i-1] < diff[i+1]:
        diff = diff[:i-1] + [diff[i-1]+diff[i]] + diff[i+1:]ㄷㅌ
    else:
        diff = diff[:i] + [diff[i]+diff[i+1]] + diff[i+2:]

print(min(diff))
