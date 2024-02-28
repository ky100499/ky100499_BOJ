T = int(input())

for i in range(T):
    N, K = map(int, input().split())

    t_req = [0]
    t_build = [0 for _ in range(N+1)]

    seq = [[] for _ in range(N+1)]
    num_req = [0 for _ in range(N+1)]

    for t in map(int, input().split()):
        t_req.append(t)

    for j in range(K):
        X, Y = map(int, input().split())
        seq[X].append(Y)
        num_req[Y] += 1

    queue = []
    for j in range(len(num_req)):
        if num_req[j] == 0:
            num_req[j] = -1
            queue.append(j)
    queue.pop(0)
    while len(queue) > 0:
        cur = queue.pop(0)
        t_build[cur] += t_req[cur]
        for s in seq[cur]:
            if num_req[s] == -1:
                continue
            t_build[s] = max(t_build[s], t_build[cur])
            num_req[s] -= 1
            if num_req[s] == 0:
                queue.append(s)

    print(t_build[int(input())])
