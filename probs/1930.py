import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

orders = [
    [0, 1, 2, 3],
    [0, 2, 3, 1],
    [0, 3, 1, 2],
    [1, 0, 3, 2],
    [1, 3, 2, 0],
    [1, 2, 0, 3],
    [2, 0, 1, 3],
    [2, 1, 3, 0],
    [2, 3, 0, 1],
    [3, 0, 2, 1],
    [3, 2, 1, 0],
    [3, 1, 0, 2],
]

def check(A, B):
    for order in orders:
        same = True
        for i in range(4):
            if A[i] != B[order[i]]:
                same = False
                break
        if same:
            return 1
    return 0

for _ in range(int(input())):
    ipt = list(map(int, input().split()))
    print(check(ipt[:4], ipt[4:]))
