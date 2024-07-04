import sys
# lines = sys.stdin.readlines()

lines = open('input.txt', 'r').readlines()

def gcd(a, b):
    while b:
        a, b = b, a%b
    return a

s = set()
w, g = 0, 0
word = ''
for c in ' '.join(lines) + ' ':
    if c.isalpha():
        c = chr(ord(c) & ~32)
        word += c
    elif word == 'BULLSHIT':
        g += 1
        w += len(s)
        s = set()
        word = ''
    elif word:
        s.add(word)
        word = ''

mod = gcd(w, g)
print(w//mod, '/', g//mod)
