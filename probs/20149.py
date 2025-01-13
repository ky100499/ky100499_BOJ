import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split())

f = lambda x, y: (y2-y1)*(x-x1) - (x2-x1)*(y-y1)
a, b = f(x3, y3), f(x4, y4)

if a == b == 0:
    if x1 == x3 and y1 == y3 and (x1-x2) * (x3-x4) <= 0 and (y1-y2) * (y3-y4) <= 0:
        print(f"1\n{x1} {y1}")
    elif x1 == x4 and y1 == y4 and (x1-x2) * (x4-x3) <= 0 and (y1-y2) * (y4-y3) <= 0:
        print(f"1\n{x1} {y1}")
    elif x2 == x3 and y2 == y3 and (x2-x1) * (x3-x4) <= 0 and (y2-y1) * (y3-y4) <= 0:
        print(f"1\n{x2} {y2}")
    elif x2 == x4 and y2 == y4 and (x2-x1) * (x4-x3) <= 0 and (y2-y1) * (y4-y3) <= 0:
        print(f"1\n{x2} {y2}")
    elif min(x1, x2) <= max(x3, x4) and min(x3, x4) <= max(x1, x2) and min(y1, y2) <= max(y3, y4) and min(y3, y4) <= max(y1, y2):
        print(1)
    else:
        print(0)
elif a == 0:
    if min(x1, x2) <= x3 <= max(x1, x2) and min(y1, y2) <= y3 <= max(y1, y2):
        print(f"1\n{x3} {y3}")
    else:
        print(0)
elif b == 0:
    if min(x1, x2) <= x4 <= max(x1, x2) and min(y1, y2) <= y4 <= max(y1, y2):
        print(f"1\n{x3} {y3}")
    else:
        print(0)
elif a*b > 0:
    print(0)
else:
    r = abs(a) / (abs(a) + abs(b))
    x = (1-r)*x3 + r*x4
    y = (1-r)*y3 + r*y4
    if min(x1, x2) <= x <= max(x1, x2) and min(y1, y2) <= y <= max(y1, y2):
        print(f"1\n{x:.10f} {y:.10f}")
    else:
        print(0)
