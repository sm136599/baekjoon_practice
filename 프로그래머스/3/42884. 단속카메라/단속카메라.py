def solution(routes):
    answer = 1
    routes.sort()
    maxx = 30000
    print(routes)
    for i, j in routes:
        if i > maxx:
            answer += 1
            maxx = j
        maxx = min(maxx, j)
    return answer