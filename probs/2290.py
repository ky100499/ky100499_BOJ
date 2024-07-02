S, N = input().split()
S = int(S)

num = [
    0b1111110,
    0b0110000,
    0b1101101,
    0b1111001,
    0b0110011,
    0b1011011,
    0b1011111,
    0b1110000,
    0b1111111,
    0b1111011,
]

chk = 0b1000000

for n in map(int, N):
    print(' ', end='')
    for _ in range(S):
        print('-' if num[n] & chk else ' ', end='')
    print(' ', end=' ')
print()

for _ in range(S):
    for n in map(int, N):
        print('|' if num[n] & (chk>>5) else ' ', end='')
        for _ in range(S):
            print(' ', end='')
        print('|' if num[n] & (chk>>1) else ' ', end=' ')
    print()

for n in map(int, N):
    print(' ', end='')
    for _ in range(S):
        print('-' if num[n] & (chk>>6) else ' ', end='')
    print(' ', end=' ')
print()

for _ in range(S):
    for n in map(int, N):
        print('|' if num[n] & (chk>>4) else ' ', end='')
        for _ in range(S):
            print(' ', end='')
        print('|' if num[n] & (chk>>2) else ' ', end=' ')
    print()

for n in map(int, N):
    print(' ', end='')
    for _ in range(S):
        print('-' if num[n] & (chk>>3) else ' ', end='')
    print(' ', end=' ')
print()
