import sys
from collections import deque

def Input_Data():
    readl = sys.stdin.readline
    N, M = map(int, readl().split())
    numbers = list(map(int, readl().split()))
    return N, M, numbers

N, M, numbers = Input_Data()
numbers = sorted(numbers)
visited = [False] * N
stack = deque()

def backtrack(length):
    global stack, numbers, N, M
    if length >= M:
        print(*stack, sep=' ')
        return

    flag = 0
    for j in range(N):
        if visited[j]:
            continue
        if flag == numbers[j]:
            continue
        flag = numbers[j]
        
        visited[j] = True
        stack.append(numbers[j])
        backtrack(length+1)
        stack.pop()
        visited[j] = False
        

backtrack(0)

