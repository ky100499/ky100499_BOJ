import sys
input = sys.stdin.readline

s = []
p = 'PPAP'

for c in input().strip():
    s.append(c)
    while len(s) > 3 and s[-1] == 'P':
        for i in range(1,5):
            if s[-1] != p[-i]:
                s.extend(p[-i+1:])
                break
            s.pop()
        else:
            s.append('P')
            continue
        break

print('PPAP' if s == ['P'] else 'NP')
