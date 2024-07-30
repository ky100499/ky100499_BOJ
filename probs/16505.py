def star(S, n):
    if n == 0:
        return S

    l = len(S[0])
    ret = []
    for s in S:
        ret.append(((s + ' '*(l-len(s)))*2).rstrip())
    for s in S:
        ret.append((s + ' '*(l-len(s))).rstrip())
    return star(ret, n-1)

print(*star(['*'], int(input())), sep='\n')
