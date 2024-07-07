import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

for _ in range(int(input())):
    N = int(input())
    G = [0] + list(map(int, input().split()))
    V = [0]*(N+1)

    for i in range(1, N+1):
        cur = i
        while V[cur] != -1:
            if V[cur] == 0:
                V[cur] = i
            elif V[cur] == i:
                V[cur] = -1

            cur = G[cur]

    print(N - V.count(-1))

