import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def dp(arr):
    for i in range(2, n):
        arr[0][i] = max(arr[0][i-2], arr[1][i-2], arr[1][i-1]) + points[0][i]
        arr[1][i] = max(arr[0][i-2], arr[1][i-2], arr[0][i-1]) + points[1][i]
    return max(arr[0][-1], arr[1][-1])

for _ in range(int(input())):
    n = int(input())
    points = [list(map(int, input().split())) for _ in range(2)]
    if n == 1:
        print(max(points[0][0], points[1][0]))
        continue

    ans = 0

    # o x
    # x o
    dp_arr = [[0]*n, [0]*n]
    dp_arr[0][0], dp_arr[1][1] = points[0][0], points[0][0]+points[1][1]
    ans = max(ans, dp(dp_arr))

    # x o
    # o x
    dp_arr = [[0]*n, [0]*n]
    dp_arr[1][0], dp_arr[0][1] = points[1][0], points[1][0]+points[0][1]
    ans = max(ans, dp(dp_arr))

    # o x
    # x x
    dp_arr = [[0]*n, [0]*n]
    dp_arr[0][0] = points[0][0]
    ans = max(ans, dp(dp_arr))

    # x x
    # o x
    dp_arr = [[0]*n, [0]*n]
    dp_arr[1][0] = points[1][0]
    ans = max(ans, dp(dp_arr))

    print(ans)
