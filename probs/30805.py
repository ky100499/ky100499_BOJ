import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
A = list(map(int, input().split()))
M = int(input())
B = list(map(int, input().split()))

cl = []
for i in range(N):
    for j in range(M):
        if A[i] != B[j]:
            continue

        if not cl:
            cl.append(j)
        elif B[cl[0]] < B[j]:
            cl = [j]
        elif B[cl[-1]] >= B[j] and cl[-1] < j:
            cl.append(j)
        else:
            for k, c in enumerate(cl):
                if B[c] < B[j] and cl[k-1] < j:
                    cl = cl[:k] + [j]
                    break
            else:
                continue
        break

print(len(cl))
print(*map(lambda x: B[x], cl))
