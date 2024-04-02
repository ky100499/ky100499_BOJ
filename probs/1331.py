input = open('input.txt', 'r').readline

sx, sy = None, None
px, py = None, None

visited = set()

for _ in range(36):
    x, y = input().strip()
    x = ord(x) - ord('A')
    y = int(y) - 1

    if sx is None:
        sx, sy = x, y
    elif (x, y) in visited or (abs(x-px), abs(y-py)) not in ((1, 2), (2, 1)):
        print('Invalid')
        break

    visited.add((x, y))
    px, py = x, y
else:
    if (abs(sx-px), abs(sy-py)) in ((1, 2), (2, 1)):
        print('Valid')
    else:
        print('Invalid')
