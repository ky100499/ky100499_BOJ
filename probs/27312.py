import sys
input = sys.stdin.readline
flush = sys.stdout.flush

M, N, Q = map(int, input().split())
A = list(map(int, input().split()))

for i in range(M):
    print(f'? {i+1} {i+1}')
    flush()

    v = int(input())

    if v == A[i]:
        A[i] = 1

print(f'! {" ".join(map(str, A))}')
flush()
