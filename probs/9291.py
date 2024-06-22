import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

T = int(input())

for t in range(T):
    B = [list(map(int, input().split())) for _ in range(9)]

    ans = 1
    for i in range(9):
        row, col, sqr = set(), set(), set()
        for j in range(9):
            row.add(B[i][j])
            col.add(B[j][i])
            sqr.add(B[i//3*3+j//3][i%3*3+j%3])
        if len(row) != 9 or len(col) != 9 or len(sqr) != 9:
            ans = 0
            break

    print(f'Case {t+1}: {"" if ans else "IN"}CORRECT')

    if t != T-1:
        input()
