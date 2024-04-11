import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

import re

pat = re.compile(r'^(100+1+|01)+$')

for _ in range(int(input())):
    print('NO' if pat.match(input().strip()) is None else 'YES')
