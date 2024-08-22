import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

while True:
    N = int(input())

    if not N:
        break

    M = [list(map(int, input().split())) for _ in range(N)]
    for i, j in [(i, j) for i in range(N-1) for j in range(N-1)]:
        if M[i][j]+M[i+1][j+1] != M[i][j+1]+M[i+1][j]:
            print('not homogeneous')
            break
    else:
        print('homogeneous')
