import sys
input = sys.stdin.readline

N, M = map(int, input().split())
dogam = {}
for i in range(N):
    ipt = input().strip()
    dogam[str(i+1)] = ipt
    dogam[ipt] = str(i+1)

for _ in range(M):
    ipt = input().strip()
    print(dogam[ipt])
