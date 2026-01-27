import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

h1, m1 = map(int, input().split(':'))
h2, m2 = map(int, input().split(':'))
d = abs((h2-h1)*60 + m2-m1)
print(min(d, 720-d) * 6)
