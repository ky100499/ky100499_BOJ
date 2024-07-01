import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def count(n):
    cnt = 0
    while n:
        cnt += n & 1
        n >>= 1
    return cnt

def bt(b, c, n):
    if n < K:
        for i in range(26):
            if c & (1<<i) and b & (1<<i) == 0:
                c ^= (1<<i)
                bt(b | (1<<i), c, n+1)
    if n == K or c == 0:
        global ans
        cnt = 0
        for w in words:
            if w & b == w:
                cnt += 1
        ans = max(ans, cnt)


N, K = map(int, input().split())
words = []
for _ in range(N):
    b = 0
    for c in input().rstrip():
        b |= 1 << (ord(c) - ord('a'))
    if count(b) <= K:
        words.append(b)

b = 0
for c in 'antatica':
    b |= 1 << (ord(c) - ord('a'))

c = 0
for w in words:
    c |= w

ans = 0
bt(b, c ^ b, count(b))
print(ans)
