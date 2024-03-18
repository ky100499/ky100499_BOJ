import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def diff(a, b):
    return sum([a[i]^b[i] for i in range(4)])

for _ in range(int(input())):
    N = int(input())
    mbti = list(map(lambda x: list(map(lambda s: 1 if s in 'ISTP' else 0, x)), input().split()))

    if N > 33:
        print(0)
        continue

    ans = 99
    for i in range(N-2):
        for j in range(i+1, N-1):
            for k in range(j+1, N):
                ans = min(ans, diff(mbti[i], mbti[j]) + diff(mbti[j], mbti[k]) + diff(mbti[k], mbti[i]))
    print(ans)
