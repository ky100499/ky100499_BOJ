import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def shuffle(P, S):
    ret = [0]*N
    for i, s in enumerate(S):
        ret[s] = P[i]
    return ret

def gcd(a, b):
    while b:
        a, b = b, a%b
    return a

def lcm(a, b):
    return a*b//gcd(a, b)

N = int(input())
P = list(map(int, input().split()))
S = list(map(int, input().split()))

L = [0]*N
loop = 1
for i in range(N):
    if L[i]:
        continue
    a, k = S[i], 1
    while a != i:
        L[a] = 1
        a = S[a]
        k += 1
    loop = lcm(loop, k)

for i in range(loop):
    for j in range(N):
        if P[j] != j%3:
            break
    else:
        print(i)
        break
    P = shuffle(P, S)
else:
    print(-1)
