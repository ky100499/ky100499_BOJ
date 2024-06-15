import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

cnt = [0, 0, 0]
for _ in range(int(input())):
    cnt[['1/4', '1/2', '3/4'].index(input().strip())] += 1

ans = (cnt[1]+1)//2 + cnt[2]
rest = (cnt[1]%2)*2 + cnt[2]
if rest < cnt[0]:
    ans += (cnt[0]-rest+3)//4
print(ans)
