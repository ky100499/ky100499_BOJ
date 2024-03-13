from collections import deque

N, K = map(int, input().split())
q = deque(range(1, N+1))
output = []
for i in range(N):
    q.rotate(1-K)
    output.append(q.popleft())
print(f'<{", ".join(map(str, output))}>')
