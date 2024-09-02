def count1(N):
    if N <= 1:
        return N

    ans = 0

    l = 1
    while N > (1<<l):
        l += 1
    if not N&(1<<l):
        l -= 1

    ans += count1(N^(1<<l))
    ans += (1<<(l-1))*l + N-(1<<l)+1
    return ans

A, B = map(int, input().split())
print(count1(B) - count1(A-1))
