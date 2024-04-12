N = int(input())
nums = list(map(int, input().split()))
add, sub, mul, div = list(map(int, input().split()))

minn = 1_000_000_000
maxx = -1_000_000_000

def dfs(depth, score, a, s, m, d):
    global nums, minn, maxx
    
    if depth >= N:
        minn = min(score, minn)
        maxx = max(score, maxx)
        return
    
    if a > 0:
        dfs(depth+1, score+nums[depth], a-1, s, m, d)
    if s > 0:
        dfs(depth+1, score-nums[depth], a, s-1, m, d)
    if m > 0:
        dfs(depth+1, score*nums[depth], a, s, m-1, d)
    if d > 0:
        if score >= 0:
            dfs(depth+1, score//nums[depth], a, s, m, d-1)
        else:
            dfs(depth+1, -(-score//nums[depth]), a, s, m, d-1)

dfs(1, nums[0], add, sub, mul, div)
print(maxx)
print(minn)