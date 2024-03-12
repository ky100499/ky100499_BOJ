a, b = sorted(map(int, input().split()))
m = a * b
while min(a, b) != 0:
    a, b = b % a, a
print(f'{b}\n{m//b}')
