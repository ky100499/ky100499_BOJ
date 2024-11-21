import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

while True:
    a, b, c = sorted(map(int, input().split()))
    if a == 0:
        break

    if a == c:
        print("Equilateral")
    elif a + b <= c:
        print("Invalid")
    elif a == b or b == c:
        print("Isosceles")
    else:
        print("Scalene")
