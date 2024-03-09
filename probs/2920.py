ipt = list(map(int, input().split()))
if ipt == sorted(ipt):
    print('ascending')
elif ipt == sorted(ipt, reverse=True):
    print('descending')
else:
    print('mixed')
