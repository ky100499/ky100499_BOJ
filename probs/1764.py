import sys
input = sys.stdin.readline

N, M = map(int, input().split())

H, S = set(), set()
for _ in range(N):
    H.add(input().strip())
for _ in range(M):
    S.add(input().strip())
inter = sorted(list(H.intersection(S)))
print(len(inter))
print('\n'.join(inter))
