import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

ans = 0
for _ in range(int(input())):
    ans += int(input().rstrip()[2:]) <= 90
print(ans)
