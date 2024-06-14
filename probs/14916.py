N = int(input())
if N in (1, 3):
    print(-1)
elif (N%5)%2:
    print(N//5-1+(N%5+5)//2)
else:
    print(N//5+(N%5)//2)
