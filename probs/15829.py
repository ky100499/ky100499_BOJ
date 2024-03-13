input()
s = 0
for i, c in enumerate(input()):
    s += (ord(c) - ord('a') + 1) * 31 ** i
print(s % 1234567891)
