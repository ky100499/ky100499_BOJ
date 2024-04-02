jm = int(input())
sm = jm

js, ss = 0, 0

prev, up, down = None, 0, 0
last_price = 0
for price in map(int, input().split()):
    js += jm // price
    jm %= price

    if prev is None:
        prev = price
    elif prev < price:
        up += 1
        down = 0
    elif prev > price:
        down += 1
        up = 0
    else:
        up = 0
        down = 0

    if up == 3:
        sm += ss * price
        ss = 0
    if down == 3:
        ss += sm // price
        sm %= price

    last_price = price

jm += js * last_price
sm += ss * last_price

if jm > sm:
    print('BNP')
elif jm < sm:
    print('TIMING')
else:
    print('SAMESAME')
