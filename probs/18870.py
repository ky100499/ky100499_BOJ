import sys
input = sys.stdin.readline

N = int(input())
X = list(map(int, input().split()))
x_sorted = sorted(X)

cnt = 0
comp = {}
for i, x in enumerate(x_sorted):
    if i == 0:
        comp[x] = cnt
    elif x_sorted[i-1] < x:
        cnt += 1
        comp[x] = cnt

print(' '.join(map(lambda x: str(comp[x]), X)))
