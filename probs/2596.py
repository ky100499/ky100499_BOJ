def findChar(bits):
    ret = False
    for i, secret in enumerate([
        '000000',
        '001111',
        '010011',
        '011100',
        '100110',
        '101001',
        '110101',
        '111010',
    ]):
        cnt = 0
        for s, b in zip(secret, bits):
            if s != b:
                cnt += 1
        if cnt <= 1:
            ret = chr(ord('A') + i)
    return ret

N = int(input())
mail = ''
ipt = input()
for i in range(N):
    c = findChar(ipt[6*i:6*(i+1)])
    if c:
        mail += c
    else:
        print(i+1)
        break
else:
    print(mail)
