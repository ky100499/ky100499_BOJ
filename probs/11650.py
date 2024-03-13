import sys
input = sys.stdin.readline

coords = []
for _ in range(int(input())):
    coords.append(tuple(map(int, input().split())))
coords.sort(key=lambda x: x[1])
coords.sort(key=lambda x: x[0])
print('\n'.join(map(lambda x: f'{x[0]} {x[1]}', coords)))
