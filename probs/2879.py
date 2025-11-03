input = open('input.txt', 'r').readline

input()
ans, v = 0, 0
for a, b in zip(map(int, input().split()), map(int, input().split())):
    d = b-a
    ans += max(0, abs(d)-abs(v)) if v*d > 0 else abs(d)
    v = d
print(ans)
