import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def initDNA(s, l):
    if l == M:
        chk = 0
        for i, g in enumerate(G):
            for j in range(M):
                if g[j] != '.' and s[j] != g[j]:
                    break
            else:
                chk |= 1<<i
        if chk == MAX-1:
            print(1)
            exit(0)
        elif chk:
            DNA.append(chk)
    else:
        initDNA(s+'a', l+1)
        initDNA(s+'t', l+1)
        initDNA(s+'g', l+1)
        initDNA(s+'c', l+1)

def bit_count(n):
    c = 0
    while n:
        c += n&1
        n >>= 1
    return c

INF = int(1e6)

N, M = map(int, input().split())
G = [input().rstrip() for _ in range(N)]
MAX = 1<<N

DNA = []
initDNA('', 0)
DNA.sort(key=bit_count, reverse=True)
DNA_f = []
for d in DNA:
    for fd in DNA_f:
        if fd|d == fd:
            break
    else:
        DNA_f.append(d)
print(*map(bin, DNA_f), sep='\n')
print(len(DNA_f))
