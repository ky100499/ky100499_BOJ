S = input()

l = len(S)
parts = set()
for i in range(1, l+1):
    for j in range(l - i + 1):
        parts.add(S[j:i+j])
print(len(parts))
