n = int(input())

div = 1_000_000_007

def matmul(a, b):
    h, w = len(a), len(a[0])
    w2 = len(b)
    res = [[0]*w2 for _ in range(h)]
    for i in range(h):
        for j in range(w2):
            for k in range(w):
                res[i][j] += a[i][k] * b[k][j]
            res[i][j] %= div

    return res

a = [[1, 1], [1, 0]]
ans = [[1, 0], [0, 1]]
while n > 0:
    if n % 2:
        ans = matmul(ans, a)
    a = matmul(a,a)

    n //= 2

print(ans[1][0])