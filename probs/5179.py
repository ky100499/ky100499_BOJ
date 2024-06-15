import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

for i in range(int(input())):
    M, N, P = map(int, input().split())
    wrong = [[0]*M for _ in range(P+1)]
    point = [0]*(P+1)
    solved = [0]*(P+1)
    for _ in range(N):
        p, m, t, j = map(lambda x: int(x) if x.isdigit() else ord(x) - ord('A'), input().split())

        if wrong[p][m] == -1:
            continue

        if j:
            point[p] += t + wrong[p][m]*20
            wrong[p][m] = -1
            solved[p] += 1
        else:
            wrong[p][m] += 1

    print(f'Data Set {i+1}:')
    for p, s, pt in sorted([(i, solved[i], point[i]) for i in range(1, P+1)], key=lambda x: (-x[1], x[2])):
        print(p, s, pt)
    print()
