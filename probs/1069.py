import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

X, Y, D, T = map(int, input().split())

dist = (X**2 + Y**2) ** 0.5
t1 = dist // D * T
print(
    min(
        dist,                   # 걷기
        t1 + dist % D,          # 최대한 점프하고 걷기
        max(T*2, t1+T),         # 돌아서 점프하기
        t1+T + D - dist % D     # 오버로 점프하고 돌아오기
    )
)
