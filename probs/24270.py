import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

MOD = int(1e9)+7

N, K = map(int, input().split())
d = K - sum(map(int, input().split()))

# N!*(N+1)H(d) = N!*(N+d)C(d) = N!(N+d)!/N!d! = (d+1)*(d+2)*...*(d+N)

ans = 1
for i in range(d+1, d+N+1):
    ans = (ans * i) % MOD
print(ans)
