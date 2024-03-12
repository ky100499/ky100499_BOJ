N = int(input())
if N == 1: print(1)
else:
    x = (((N - 2) // 6 * 8 + 1) ** 0.5 + 1) // 2
    print(f'{x+1:.0f}')
