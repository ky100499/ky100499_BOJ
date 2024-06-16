def prime_sum(i, j):
    s = 0
    for k in range(i, j+1):
        if primes[k]:
            s += k
    return s

N = int(input())

primes = [1]*(N+1)
primes[0] = primes[1] = 0
for i in range(2, N+1):
    if primes[i]:
        j = i*i
        while j <= N:
            primes[j] = 0
            j += i

i, j = 2, 2
cnt = 0
while j <= N:
    s = prime_sum(i, j)
    if s < N:
        j += 1
        while j <= N and primes[j] == 0:
            j += 1
    elif s > N:
        i += 1
        while i <= j and primes[i] == 0:
            i += 1
    else:
        cnt += 1
        j += 1
        while j <= N and primes[j] == 0:
            j += 1
print(cnt)
