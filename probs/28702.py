for i in range(3):
    x = input()
    if x.isdecimal():
        ans = int(x)+3-i

if ans % 5 == 0 and ans % 3 == 0:
    print('FizzBuzz')
elif ans % 5 == 0:
    print('Buzz')
elif ans % 3 == 0:
    print('Fizz')
else:
    print(ans)
