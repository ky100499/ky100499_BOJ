import sys
input = sys.stdin.readline

s = set()
for _ in range(int(input())):
    s.add(input().strip())
print('\n'.join(sorted(sorted(list(s)), key=lambda x: len(x))))
