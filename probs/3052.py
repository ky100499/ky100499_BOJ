cnt = [0] * 42
for _ in range(10):
    cnt[int(input()) % 42] += 1
print(len(list(filter(lambda x: x, cnt))))
