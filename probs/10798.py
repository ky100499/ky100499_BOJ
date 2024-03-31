ipt = []
for _ in range(5):
    ipt.append(input())

for j in range(15):
    for i in range(5):
        if j < len(ipt[i]):
            print(ipt[i][j], end='')
print()
