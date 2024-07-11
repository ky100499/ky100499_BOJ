import sys
input = sys.stdin.readline

N = int(input())
l, h = 1, N

while l <= h:
    m = (l+h)//2
    print(f'? {m}')
    sys.stdout.flush()

    res = int(input())

    if 2*res == m:
        print(f'! {m}')
        break
    elif 2*res > m:
        l = m+1
    else:
        h = m-1
else:
    print('! 0')
