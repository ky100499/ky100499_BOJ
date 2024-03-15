ipt = input().split('-')
calced = []
for chunk in ipt:
    calced.append(sum(map(int, chunk.split('+'))))
print(sum(calced) * -1 + 2 * calced[0])
