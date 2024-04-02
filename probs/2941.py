s = input()
l = len(s)
cnt = 0
i = 0
while i < l:
    if s[i] in 'cdlnsz' and i+1 < l and s[i:i+2] in ['c=', 'c-', 'd-', 'lj', 'nj', 's=', 'z=']:
        i += 1
    elif i+2 < l and s[i:i+3] == 'dz=':
        i += 2
    cnt += 1
    i += 1
print(cnt)
