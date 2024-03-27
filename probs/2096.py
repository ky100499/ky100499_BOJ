import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())

maxdp = [[0]*3 for _ in range(2)]
mindp = [[0]*3 for _ in range(2)]
b = list(map(int, input().split()))
maxdp[0] = b[:]
mindp[0] = b[:]
for i in range(1, N):
    b = list(map(int, input().split()))
    maxdp[i%2][0] = max(
        b[0]+maxdp[(i+1)%2][0],
        b[0]+maxdp[(i+1)%2][1]
    )
    maxdp[i%2][1] = max(
        b[1]+maxdp[(i+1)%2][0],
        b[1]+maxdp[(i+1)%2][1],
        b[1]+maxdp[(i+1)%2][2],
    )
    maxdp[i%2][2] = max(
        b[2]+maxdp[(i+1)%2][1],
        b[2]+maxdp[(i+1)%2][2]
    )

    mindp[i%2][0] = min(
        b[0]+mindp[(i+1)%2][0],
        b[0]+mindp[(i+1)%2][1]
    )
    mindp[i%2][1] = min(
        b[1]+mindp[(i+1)%2][0],
        b[1]+mindp[(i+1)%2][1],
        b[1]+mindp[(i+1)%2][2],
    )
    mindp[i%2][2] = min(
        b[2]+mindp[(i+1)%2][1],
        b[2]+mindp[(i+1)%2][2]
    )

print(
    max(maxdp[(N+1)%2]),
    min(mindp[(N+1)%2])
)
