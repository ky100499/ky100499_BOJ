y = int(input())
print(1 if y % 400 == 0 or y % 100 != 0 and y % 4 == 0 else 0)
