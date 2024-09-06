import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

s = 0
while True:
    a = int(input())
    if a == -1:
        break
    s += a
print(s)
