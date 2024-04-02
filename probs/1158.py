from collections import deque

N, K = map(int, input().split())
q = deque(range(1, N+1))
out = []
while q:
    q.rotate(1-K)
    out.append(q.popleft())
print(f'<{", ".join(map(str, out))}>')
