MOD = int(1e9)+7

N = int(input())

'''
1       1
2       2
3       4
4       1+3 2+2 3+1 4 -> 1+2+4+1 = 8

n       sum(1, 2, ... , n-1) + 1 = 2 ** n
'''

def pow(b, p):
    if p == 0:
        return 1
    else:
        x = pow(b, p//2)
        if p%2:
            return (x*x%MOD)*b%MOD
        else:
            return x*x%MOD

print(pow(2, N-1) if N else 1)
