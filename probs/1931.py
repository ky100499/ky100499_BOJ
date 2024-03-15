import sys
input = sys.stdin.readline

N = int(input())
meetings = []
for _ in range(N):
    meetings.append(tuple(map(int, input().split())))
meetings.sort(key=lambda x: x[0])
meetings.sort(key=lambda x: x[1])

fin, cnt = 0, 0
for meeting in meetings:
    if meeting[0] >= fin:
        fin = meeting[1]
        cnt += 1
print(cnt)
