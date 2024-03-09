import sys
input = sys.stdin.readline

N, M = map(int, input().split())

q = list(range(1, N+1))
output = list(map(int, input().split()))

start = 0
cnt = 0
for i in range(M):
    first = q[start]
    mid = q[(start + N // 2) % N]
    idx = q.index(output[i])

    if output[i] == first:
        pass
    elif output[i] == mid:
        cnt += N // 2
    elif first < mid:
        if output[i] < first:
            cnt += start - idx
        elif mid < output[i]:
            cnt += N - idx + start
        else:
            cnt += idx - start
    else:
        if output[i] > first:
            cnt += idx - start
        elif mid > output[i]:
            cnt += N - start + idx
        else:
            cnt += start - idx
    start = idx

    q.pop(start)
    N -= 1
    if N != 0:
        start %= N

print(cnt)
