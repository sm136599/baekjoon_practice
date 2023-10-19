import sys
from time import time

readl = sys.stdin.readline
sudoku = [list(map(int, readl().strip())) for _ in range(9)]

t_s = time()

def check(i, j, num):
    global sudoku
    for k in range(9):
        if sudoku[i][k] == 0:
            continue
        if sudoku[i][k] == num:
            return False

    for k in range(9):
        if sudoku[k][j] == 0:
            continue
        if sudoku[k][j] == num:
            return False

    boxI, boxJ = i // 3, j // 3
    for k in range(3*boxI, 3*(boxI+1)):
        for l in range(3*boxJ, 3*(boxJ+1)):
            if sudoku[k][l] == 0:
                continue

            if sudoku[k][l] == num:
                return False
    return True


def getPossibleNums(i, j):
    global sudoku
    possible = []
    for n in range(1, 10):
        if check(i, j, n):
            possible.append(n)
    return possible

def DFS(idx):
    global sudoku, todo, flag
    if flag:
        return
    if idx >= len(todo):
        for su in sudoku:
            print(*su, sep='')
        flag = True
        return
    i, j = todo[idx]
    possible = getPossibleNums(i, j)
    if not possible:
        # print(*sudoku, sep='\n')
        return
    
    for num in possible:
        sudoku[i][j] = num
        DFS(idx+1)
        sudoku[i][j] = 0

todo = []
for i in range(9):
    for j in range(9):
        if sudoku[i][j] == 0:
            todo.append((i, j))

flag = False
DFS(0)
print(time() - t_s)