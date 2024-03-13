import sys
input = sys.stdin.readline

users = []
for _ in range(int(input())):
    users.append(tuple(input().split()))
users.sort(key=lambda x: int(x[0]))
print('\n'.join(map(lambda x: ' '.join(x), users)))
