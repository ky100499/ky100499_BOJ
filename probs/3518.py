import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

S = []
l = 0
while True:
    try:
        s = input().split()
    except EOFError:
        break

    if not s:
        break

    l = max(l, len(s))
    S.append(s)

lens = [0]*l
for s in S:
    for i, w in enumerate(s):
        lens[i] = max(lens[i], len(w))

for s in S:
    ans = []
    for i, w in enumerate(s):
        ans.append(w + ' '*(lens[i] - len(w)))
    ans[-1] = ans[-1].rstrip()
    print(' '.join(ans))
