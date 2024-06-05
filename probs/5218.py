import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

for _ in range(int(input())):
    A, B = input().split()
    ans = []
    for a, b in zip(A, B):
        d = ord(b) - ord(a)
        ans.append(d if d >= 0 else d+26)
    print('Distances:', *ans)
