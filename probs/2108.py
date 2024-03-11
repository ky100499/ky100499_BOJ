import sys
input = sys.stdin.readline

N = int(input())

arr = []
cnt = dict()
for _ in range(N):
    ipt = int(input())
    arr.append(ipt)
    if cnt.get(ipt) is None:
        cnt[ipt] = 0
    cnt[ipt] += 1
arr.sort()

avg = sum(arr) / N
avg = int(avg + 0.5) if avg > 0 else int(avg - 0.5)

print(avg)
print(arr[N // 2])

cnt = sorted(sorted(list(cnt.items()), key=lambda x: x[0]), key=lambda x: x[1], reverse=True)
if len(cnt) >= 2 and cnt[0][1] == cnt[1][1]:
    print(cnt[1][0])
else:
    print(cnt[0][0])

print(arr[-1] - arr[0])
