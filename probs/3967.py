import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

input = open('input.txt', 'r').readline

check = [
    [0, 2, 5, 7],
    [0, 3, 6, 10],
    [7, 8, 9, 10],
    [1, 2, 3, 4],
    [1, 5, 8, 11],
    [4, 6, 9, 11],
]
solved = False

def fill(star, pool):
    global solved

    if pool:
        for c in check:
            s = 0
            for i in c:
                s += star[i]
            if s > 26:
                break
        else:
            idx = star.index(0)
            for i, v in enumerate(pool):
                star[idx] = pool[i]
                fill(star, pool[:i]+pool[i+1:])
                star[idx] = 0

                if solved:
                    break
    else:
        for c in check:
            s = 0
            for i in c:
                s += star[i]
            if s != 26:
                break
        else:
            star = list(map(lambda x: chr(x+ord('A')-1), star))
            print(f'....{star[0]}....')
            print(f'.{".".join(star[1:5])}.')
            print(f'..{"...".join(star[5:7])}..')
            print(f'.{".".join(star[7:11])}.')
            print(f'....{star[11]}....')
            solved = True

star = []
avail = list(range(1, 13))
for _ in range(5):
    for c in input().strip():
        if c != '.':
            if c == 'x':
                star.append(0)
            else:
                c = ord(c) - ord('A') + 1
                star.append(c)
                avail.pop(avail.index(c))
fill(star, avail)
