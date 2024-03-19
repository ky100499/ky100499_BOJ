input = open('input.txt', 'r').readline

N, M = map(int, input().split())
_, *truth = map(int, input().split())
truth = set(truth)

parties = []
for _ in range(M):
    _, *party = map(int, input().split())
    parties.append(party)

lie = [True] * M

update = True
while update:
    update = False
    for i, party in enumerate(parties):
        if lie[i]:
            for person in party:
                if person in truth:
                    truth.update(party)
                    lie[i] = False
                    update = True
                    break

print(lie.count(True))
