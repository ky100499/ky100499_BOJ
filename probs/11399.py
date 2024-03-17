N = int(input())
P = list(sorted(map(int, input().split())))
s = 0
for i, p in enumerate(P):
    s += (N-i) * p
print(s)
