import sys
input = sys.stdin.readline

N, M = map(int, [input(), input()])
S = input().strip()
Pn = []
i = 0
while i < M:
    if S[i] == 'I':
        j = 0
        while i+j+2 < M:
            if S[i+j+1:i+j+3] == 'OI':
                j += 2
            else:
                break
        Pn.append((j+1) // 2)
        i = i + j
    i += 1

print(sum(map(lambda x: x-N+1 if x >= N else 0, Pn)))
