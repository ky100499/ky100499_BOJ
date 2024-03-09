n = 1
for _ in range(3):
    n *= int(input())
count = [0] * 10
while n:
    count[n%10] += 1
    n //= 10
for c in count:
    print(c)
