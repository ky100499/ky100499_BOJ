import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

vowels = 'aeiou'

while True:
    ipt = input().strip()
    if ipt == 'end':
        break

    vow = False
    cont = True
    dup = True

    for i in range(len(ipt)):
        if not vow and ipt[i] in vowels:
            vow = True
        if i < len(ipt)-2 and (ipt[i] in vowels) == (ipt[i+1] in vowels) == (ipt[i+2] in vowels):
            cont = False
            break
        if i < len(ipt)-1 and ipt[i] not in 'eo' and ipt[i] == ipt[i+1]:
            dup = False
            break
    print(f'<{ipt}> is {"" if vow and cont and dup else "not "}acceptable.')
