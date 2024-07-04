X = input()

cnt = 0
while len(X) > 1:
    cnt += 1
    X = str(sum(map(int, X)))
print(cnt, 'NO' if int(X)%3 else 'YES', sep='\n')
