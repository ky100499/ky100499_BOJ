alphas = [
    '',
    '',
    'ABC',
    'DEF',
    'GHI',
    'JKL',
    'MNO',
    'PQRS',
    'TUV',
    'WXYZ',
]

def cton(c):
    for i, v in enumerate(alphas):
        if c in v:
            return i

ans = 0
for c in input():
    ans += cton(c)+1
print(ans)
