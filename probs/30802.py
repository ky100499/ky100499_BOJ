import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
sizes = list(map(int, input().split()))
T, P = map(int, input().split())

print(sum(map(lambda x: (x+T-1) // T, sizes)))
print(N // P, N % P)
