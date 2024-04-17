import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
K = int(input())

if N < K:
    print(0)
else:
    sensors = sorted(map(int, input().split()))
    length = sensors[-1] - sensors[0]

    diff = []
    for i in range(N-1):
        diff.append(sensors[i+1]-sensors[i])
    diff.sort(reverse=True)

    for i in range(K-1):
        length -= diff[i]
    print(length)
