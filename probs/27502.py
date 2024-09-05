import sys
input = sys.stdin.readline
flush = sys.stdout.flush

N, T = map(int, input().split())

print(f'! {N//2+T%2}')
flush()

if T%2:
    print('1 1')
    flush()

for _ in range(N//2-T%2):
    a, b = map(int, input().split())
    print(b, a)
    flush()
