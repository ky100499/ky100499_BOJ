import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

while True:
    try:
        mem = [int(input(), 2) for _ in range(32)]
        pc = adder = 0
    except:
        break

    while True:
        op, x = mem[pc]//32, mem[pc]%32
        pc = (pc + 1) % 32

        if op == 0:
            mem[x] = adder
        elif op == 1:
            adder = mem[x]
        elif op == 2:
            pc = pc if adder else x
        elif op == 3:
            pass
        elif op == 4:
            adder = (adder + 255) % 256
        elif op == 5:
            adder = (adder + 1) % 256
        elif op == 6:
            pc = x
        elif op == 7:
            break

    print(bin(adder)[2:].zfill(8))
