def check(x, y):
    cnt = 0
    cnt+=(grid[x][y] == '#')+(grid[x][N - 1 - y] == '#')+(grid[N - 1 - x][y] == '#')+(grid[N - 1 - x][N - 1 - y] == '#')
    return min(cnt, 4 - cnt)

# 输入读取
N, U = map(int, input().split())
grid = [list(input().strip()) for _ in range(N)]

ans = 0
for i in range(N):
    for j in range(N):
        ans += check(i, j)
ans //= 4  # 每组被重复计算了4次

print(ans)

for _ in range(U):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    before = check(x, y)
    grid[x][y] = '.' if grid[x][y] == '#' else '#'
    after = check(x, y)
    ans += after - before
    print(ans)
