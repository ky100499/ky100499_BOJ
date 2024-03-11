import sys
input = sys.stdin.readline

while True:
    ipt = input().strip()
    if int(ipt) == 0: break
    else: print("yes" if ipt == ipt[::-1] else "no")
