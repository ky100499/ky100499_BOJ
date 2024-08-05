import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def itoa(n):
    q, r = n//26, n%26
    if q == 0:
        return chr(65+r)
    else:
        return itoa(q-1) + chr(65+r)

while True:
    n, m = map(int, input()[1:].split('C'))
    if n == m == 0:
        break
    print(itoa(m-1)+str(n))
