import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

for _ in range(int(input())):
    fd, *fb = map(int, input().split())
    gd, *gb = map(int, input().split())
    hd, *hb = map(int, input().split())

    rb = [0]*(fd+gd-1)
    for i in range(fd):
        for j in range(gd):
            rb[i+j] ^= fb[i]&gb[j]

    for i in range(fd+gd-hd):
        if rb[i]:
            for j in range(hd):
                rb[i+j] ^= hb[j]

    rb = rb[rb.index(1):]
    print(len(rb), *rb)
