from functools import reduce
print(reduce(lambda x,y:(x+2)*(y+2)%int(1e9+7),map(int,input().split())))
