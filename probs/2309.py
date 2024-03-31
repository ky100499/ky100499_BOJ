h = [int(input()) for _ in range(9)]
s = sum(h) - 100
for i, j in [(i, j) for i in range(8) for j in range(i+1, 9)]:
    if h[i]+h[j] == s:
        print(*sorted(h[:i]+h[i+1:j]+h[j+1:]), sep='\n')
        break
