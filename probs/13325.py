import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def weight(node):
   if 2*node+1 < N:
      lw = W[2*node] + weight(2*node+1)
      rw = W[2*node+1] + weight(2*node+2)

      if lw > rw:
         W[2*node+1] += lw - rw
         return lw
      elif rw > lw:
         W[2*node] += rw - lw
         return rw
      else:
         return lw
   else:
      return 0

K = int(input())
N = 2**(K+1)-1
W = list(map(int, input().split()))

weight(0)
print(sum(W))
