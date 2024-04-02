def fact(n):
    if n <= 1:
        return 1
    else:
        return n * fact(n-1)

def comb(n, r):
    return fact(n) // (fact(r) * fact(n-r))

N, M, K = map(int, input().split())

every = comb(N, M)
prob = 0
for i in range(K, M+1):
    prob += comb(M, i) * comb(N-M, M-i)

print(prob/every)


'''

전체 경우의수 -> nCm

문제 상황
-> M개중에 K개 이상 뽑고 (N-M)개 중에 나머지 뽑기
-> for i: k~m -> mCi * (n-m)C(m-i)

'''
