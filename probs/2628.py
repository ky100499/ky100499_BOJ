w, h = map(int, input().split())
wc, hc = [], []

for _ in range(int(input())):
    d, n = map(int, input().split())
    if d:
        wc.append(n)
    else:
        hc.append(n)
wc += [0, w]
hc += [0, h]
wc.sort()
hc.sort()

w = max([wc[i+1]-wc[i] for i in range(len(wc)-1)])
h = max([hc[i+1]-hc[i] for i in range(len(hc)-1)])
print(w*h)
