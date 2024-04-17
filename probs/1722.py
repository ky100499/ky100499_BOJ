import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def fact(n):
    if n <= 1:
        return 1
    else:
        return n * fact(n-1)

N = int(input())
q, *ipt = map(int, input().split())
nums = list(range(1, N+1))

if q == 1:
    k = ipt[0]
    ans = []
    while N:
        n = fact(N-1)
        ans.append(nums.pop((k-1)//n))
        k %= n
        N -= 1
    print(*ans)
else:
    ans = 1
    for i, n in enumerate(ipt):
        idx = nums.index(n)
        ans += idx * fact(N-i-1)
        nums.pop(idx)
    print(ans)
