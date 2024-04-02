x, y, w, s = map(int, input().split())
if x<y:
    x, y = y, x
if 2*w > s:
    if w>s:
        print(s*y + 2*s*((x-y)//2) + w*((x-y)%2))
    else:
        print(s*y + w*(x-y))
else:
    print(w*(x+y))
