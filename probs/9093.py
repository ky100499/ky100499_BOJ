import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

for _ in range(int(input())):
    A = list(map(lambda x:x[::-1], input().split()))
    print(*A)
