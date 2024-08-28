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
        if chk == MAX:
            print(1)
            exit(0)
        elif chk:
            DNA.append(chk)
    else:
        initDNA(s+'a', l+1)
        initDNA(s+'t', l+1)
        initDNA(s+'g', l+1)
        initDNA(s+'c', l+1)

def bt(i, c, n):
    global ans

    if n > ans:
        return
    elif c == MAX:
        ans = min(ans, n)
    elif i < l:
        bt(i+1, c, n)
        bt(i+1, c|DNA[i], n+1)

N, M = map(int, input().split())
G = [input().rstrip() for _ in range(N)]
MAX = (1<<N)-1

DNA = []
initDNA('', 0)
l = len(DNA)
print(l)

ans = N
bt(0, 0, 0)
print(ans)
