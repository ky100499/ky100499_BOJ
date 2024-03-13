N = int(input())

sizes = []
for _ in range(N):
    sizes.append(tuple(map(int, input().split())))
for size in sizes:
    print(len(list(filter(lambda x: x[0] > size[0] and x[1] > size[1], sizes))) + 1, end=" ")
print()
