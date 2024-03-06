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

def mat(idx, A, B, matched, visited):
    if visited[idx]: return False
    visited[idx] = True
    for i, b in enumerate(B):
        if A[idx] + b in primes:
            if matched[1][i] is False or mat(matched[1][i], A, B, matched, visited):
                matched[0][idx] = i
                matched[1][i] = idx
                return True
    return False

N = int(input())
nums = list(map(int, input().split()))
A = list(filter(lambda x: x % 2 == nums[0] % 2, nums))
B = list(filter(lambda x: x % 2 != nums[0] % 2, nums))

a = A.pop(0)

try:
    ans = []
    for i, b in enumerate(B):
        if a + b in primes:
            matched = [[False for _ in range(N//2-1)] for _ in range(2)]
            cnt = 0
            for j in range(N//2-1):
                visited = [False for _ in range(N//2-1)]
                if mat(j, A, B[:i]+B[i+1:], matched, visited):
                    cnt += 1
            if cnt == N//2-1:
                ans.append(b)

    print(' '.join(map(str, sorted(ans))) if len(ans) else -1)
except IndexError:
    print(-1)
