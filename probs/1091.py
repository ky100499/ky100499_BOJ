import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def shuffle(P, S):
    ret = [0]*N
    for i, s in enumerate(S):
        ret[s] = P[i]
    return ret

N = int(input())
P = list(map(int, input().split()))
S = list(map(int, input().split()))

for i in range(N):
    for j in range(N):
        if P[j] != j%3:
            break
    else:
        print(i)
        break
    P = shuffle(P, S)
else:
    print(-1)
