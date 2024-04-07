import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def rmStone(arr, d):
    cnt, st = 0, 0
    for s in arr:
        if s - st >= d:
            st = s
        else:
            cnt += 1
    return cnt

d, n, m = map(int, input().split())

ipt = [d]
for _ in range(n):
    ipt.append(int(input()))
ipt.sort()

l, h = 0, d
while l <= h:
    mid = (l+h) // 2
    if rmStone(ipt, mid) > m:
        h = mid-1
    else:
        ans = mid
        l = mid+1

print(ans)
