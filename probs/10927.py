import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

import hashlib

hash = hashlib.new('ripemd160')
hash.update(input().strip().encode())
print(hash.hexdigest())
