N = int(input())

def isPrime(n):
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True

def bt(n, k):
    if isPrime(n):
        if k == 1:
            print(n)
        else:
            bt(10*n+1, k-1)
            bt(10*n+3, k-1)
            bt(10*n+5, k-1)
            bt(10*n+7, k-1)
            bt(10*n+9, k-1)

bt(2, N)
bt(3, N)
bt(5, N)
bt(7, N)
