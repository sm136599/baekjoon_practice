import sys

def Input_Data():
    readl = sys.stdin.readline
    N, M = map(int, readl().split())
    know = list(map(int, readl().split()))[1:]
    party = [list(map(int, readl().split()))[1:] for _ in range(M)]
    return N, M, know, party


N, M, know, party = Input_Data()

flag = 1

while flag:
    flag = 0
    for i in range(M):
        for j in range(len(party[i])):
            if party[i][j] in know:
                for k in range(len(party[i])):
                    know.append(party[i][k])
                party[i] = []
                flag = 1
                break

cnt = 0

for i in range(M):
    if len(party[i]) > 0:
        cnt += 1

print(cnt)
