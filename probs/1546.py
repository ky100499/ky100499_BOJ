import sys
input = sys.stdin.readline

N = int(input())
scores = list(map(int, input().split()))
print(sum(scores) / max(scores) * 100 / N)
