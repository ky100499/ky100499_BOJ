max_n, max_idx = 0, 0
for i in range(1, 10):
    ipt = int(input())
    if max_n < ipt:
        max_n = ipt
        max_idx = i
print(f'{max_n}\n{max_idx}')
