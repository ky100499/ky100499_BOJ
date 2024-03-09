import sys
input = sys.stdin.readline

N = int(input())

files = []
for _ in range(N):
    files.append(input().strip())

pat = ""
for i in range(len(files[0])):
    if list(filter(lambda x: x[i] != files[0][i], files)):
        pat += '?'
    else:
        pat += files[0][i]

print(pat)
