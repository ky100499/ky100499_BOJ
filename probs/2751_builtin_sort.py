import sys
input = sys.stdin.readline

arr = []
for _ in range(int(input())):
    arr.append(int(input()))
print('\n'.join(map(str, sorted(arr))))
