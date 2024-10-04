import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
pts = [tuple(map(float, input().split())) for _ in range(N)]
A = int(input())

mx, my = min(map(lambda x: x[0], pts)), min(map(lambda x: x[1], pts))
for i in range(N):
    pts[i] = (pts[i][0]-mx, pts[i][1]-my)

org = pts[0]
S = 0
for i in range(1, N-1):
    v1, v2 = (pts[i][0]-org[0], pts[i][1]-org[1]), (pts[i+1][0]-org[0], pts[i+1][1]-org[1])
    S += 0.5 * (v1[0]*v2[1] - v1[1]*v2[0])
rat = (A/S)**0.5

print(*map(lambda x: f'{x[0]*rat} {x[1]*rat}', pts), sep='\n')
