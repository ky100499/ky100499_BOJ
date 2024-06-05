import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

O = [chr(i) for i in range(ord('A'), ord('Z')+1)]
C = ['']*26

w = input().strip()
k = int(input())-1

for i, c in enumerate(w):
    C[(k+i)%26] = c

k += len(w)
i = ord('A')
while i <= ord('Z'):
    if chr(i) not in C:
        C[k%26] = chr(i)
        k += 1
    i += 1

print(''.join(map(lambda x: O[C.index(x)], input().strip())))
