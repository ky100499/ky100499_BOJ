import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

V = set()

for _ in range(int(input())):
    S = input().split()

    for i, s in enumerate(S):
        if s[0].upper() not in V:
            S[i] = f'[{s[0]}]{s[1:]}'
            V.add(s[0].upper())
            break
    else:
        for i, s in enumerate(S):
            for j, c in enumerate(s):
                if c.upper() not in V:
                    S[i] = f'{s[:j]}[{s[j]}]{s[j+1:]}'
                    V.add(c.upper())
                    break
            else:
                continue
            break

    print(' '.join(S))
