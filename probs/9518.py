import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

R, S = map(int, input().split())
B = [list(map(lambda x: int(x=='o'), input().strip())) for _ in range(R)]

sh = [[0]*S for _ in range(R)]
sk_max = 0
for i in range(R):
    for j in range(S):
        sk = 0
        for di, dj in [[-1,-1],[-1,0],[-1,1],[0,1],[1,1],[1,0],[1,-1],[0,-1]]:
            ni, nj = i+di, j+dj
            if 0 <= ni < R and 0 <= nj < S and B[ni][nj]:
                if B[i][j]:
                    sh[i][j] += 1
                else:
                    sk += 1
        sk_max = max(sk_max, sk)
print(sum(map(sum, sh))//2+sk_max)
