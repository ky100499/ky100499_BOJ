import sys
input = sys.stdin.readline

def round(n):
    return int(n + 0.5)

n = int(input())
ipt = []
for _ in range(n):
    ipt.append(int(input()))
ipt.sort()

ignore = round(n * 0.15)
print(0 if n == 0 else round(sum(ipt[ignore:n-ignore]) / (n - 2 * ignore)))
