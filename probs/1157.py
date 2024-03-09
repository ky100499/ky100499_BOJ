import sys
input = sys.stdin.readline

word = input().strip()
count = [0] * 26

for ch in word:
    count[(ord(ch) | 32) - ord('a')] += 1

if count.index(max(count)) == 25 - list(reversed(count)).index(max(count)):
    print(chr(count.index(max(count)) + ord('A')))
else:
    print('?')
