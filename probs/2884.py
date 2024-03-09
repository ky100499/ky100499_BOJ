H, M = map(int, input().split())
M -= 45
H -= 1 if M < 0 else 0
M += 60 if M < 0 else 0
H += 24 if H < 0 else 0
print(f'{H} {M}')
