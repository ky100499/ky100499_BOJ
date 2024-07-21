import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

'''
벡터 외적 이용

(x1, y1, 0) X (x2, y2, 0) = (0, 0, x1y2 - x2y1) = 2S
'''

N = int(input())
O = tuple(map(int, input().split()))
p1 = tuple(map(int, input().split()))

area = 0
for _ in range(N-2):
    p2 = tuple(map(int, input().split()))
    area += (p1[0] - O[0]) * (p2[1] - O[1]) - (p2[0] - O[0]) * (p1[1] - O[1])
    p1 = p2

print(f'{abs(area)/2:.1f}')
