N = int(input())

if (x := ((1 << N.bit_length()) - 1) ^ N):
    print(2, x, N, sep='\n')
else:
    print(1, N, sep='\n')
