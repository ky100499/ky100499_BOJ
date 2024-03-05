import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

def isPrime(n):
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    else:
        return True

primes = [i for i in range(2, 2000) if isPrime(i)]

def divide(l):
    if len(l) == 2: return sum(l) in primes
    n = l.pop()
    for i in range(len(l)):
        if n + l[i] in primes and divide(l[:i] + l[i+1:]):
            return True
    else: return False

N = int(input())
nums = list(map(int, input().split()))
n = nums.pop(0)
ans = []
for i in range(N-1):
    if n + nums[i] in primes and divide(nums[:i] + nums[i+1:]):
        ans.append(nums[i])

print(' '.join(map(str, sorted(ans))) if len(ans) else -1)
