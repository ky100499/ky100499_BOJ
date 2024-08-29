import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def lastBitIndex(n):
    i = 0
    while n >= 1<<i:
        if n&(1<<i):
            return i
        i += 1
    return -1

N, M = map(int, input().split())
G = [input().rstrip() for _ in range(N)]
MAX = 1<<N

S = ['']*MAX
S[0] = '.'*M
for i in range(1, MAX):
    l = lastBitIndex(i)
    s1, s2 = G[l], S[i^(1<<l)]
    if s1 and s2:
        s = ''
        for j in range(M):
            if s1[j] == '.':
                s += s2[j]
            elif s2[j] == '.':
                s += s1[j]
            elif s1[j] == s2[j]:
                s += s1[j]
            else:
                s = ''
                break
        S[i] = s

ans = [N]*MAX
for i in range(1, MAX):
    if not S[i]:
        bits = []
        j = 0
        while i >= 1<<j:
            if i&(1<<j):
                bits.append(j)
            j += 1

        k = 0
        for _ in range((1<<len(bits)-1)-1):
            for bt in bits:
                k ^= 1<<bt
                if k & (1<<bt):
                    break
            ans[i] = min(ans[i], ans[k]+ans[i^k])
    else:
        ans[i] = 1
print(ans[-1])
