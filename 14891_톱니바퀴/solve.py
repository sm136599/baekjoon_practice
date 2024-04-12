from collections import deque
gear_state = [deque(map(int, input().strip())) for _ in range(4)]
K = int(input())
cmd = [list(map(int, input().split())) for _ in range(K)]

for n, dir in cmd:
    tmp = [gear_state[0][2] == gear_state[1][-2],
           gear_state[1][2] == gear_state[2][-2],
           gear_state[2][2] == gear_state[3][-2]]
    
    rot = [0] * 4
    rot[n-1] = dir
    for i in range(n, 4):
        if rot[i-1] != 0 and not tmp[i-1]:
            rot[i] = -rot[i-1]

    for i in range(n-2, -1, -1):
        if rot[i+1] != 0 and not tmp[i]:
            rot[i] = -rot[i+1]

    for i in range(4):
        gear_state[i].rotate(rot[i])
    
answer = 0
for i in range(4):
    if gear_state[i][0]:
        answer += 2**i

print(answer)