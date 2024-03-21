from itertools import combinations as c

N, M = map(int, input().split())
arr = list(range(1, N+1))
for l in c(arr, M):
    print(' '.join(map(str, l)))
