import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split())

f = lambda x, y: (y2-y1)*(x-x1) - (x2-x1)*(y-y1)
a, b = f(x3, y3), f(x4, y4)

if a == b == 0:
    print(int(min(x1, x2) <= max(x3, x4) and min(x3, x4) <= max(x1, x2) and min(y1, y2) <= max(y3, y4) and min(y3, y4) <= max(y1, y2)))
elif a == 0:
    print(int(min(x1, x2) <= x3 <= max(x1, x2) and min(y1, y2) <= y3 <= max(y1, y2)))
elif b == 0:
    print(int(min(x1, x2) <= x4 <= max(x1, x2) and min(y1, y2) <= y4 <= max(y1, y2)))
elif a*b > 0:
    print(0)
else:
    x = (abs(b)*x3+abs(a)*x4)/(abs(a)+abs(b))
    y = (abs(b)*y3+abs(a)*y4)/(abs(a)+abs(b))
    print(int(min(x1, x2) <= x <= max(x1, x2) and min(y1, y2) <= y <= max(y1, y2)))
