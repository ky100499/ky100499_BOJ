import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

while True:
    N, R = map(int, input().split())

    if N == R == 0:
        break

    deck = [i+1 for i in reversed(range(N))]

    for _ in range(R):
        p, c = map(int, input().split())
        p -= 1
        deck = deck[p:p+c] + deck[:p] + deck[p+c:]

    print(deck[0])
