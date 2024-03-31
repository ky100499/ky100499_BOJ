N = int(input())
ds = int(input())
cand = []
for _ in range(N-1):
    cand.append(int(input()))

cnt = 0
while cand and ds+cnt <= max(cand):
    cand[cand.index(max(cand))] -= 1
    cnt += 1
print(cnt)
