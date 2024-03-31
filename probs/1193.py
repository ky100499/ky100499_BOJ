X = int(input())
n = int((2*X)**0.5)
while n*n+n < 2*X:
    n += 1
r = X - (n*n-n)//2
print(f'{n-r+1}/{r}' if n % 2 else f'{r}/{n-r+1}')
