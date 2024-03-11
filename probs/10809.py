s = input()
pos = [-1 for _ in range(26)]

for i, c in enumerate(s):
    n = ord(c) - ord('a')
    if pos[n] == -1: pos[n] = i
print(' '.join(map(str, pos)))
