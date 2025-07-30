n, u = map(int, input().split())

# 初始化 grid 为二维字符数组
grid = [list(input().strip()) for _ in range(n)]

for t in range(u + 1):
    ans = 0
    for i in range(n // 2):
        for j in range(n // 2):
            vals = [
                1 if grid[i][j] == '#' else 0,
                1 if grid[i][n - 1 - j] == '#' else 0,
                1 if grid[n - 1 - i][j] == '#' else 0,
                1 if grid[n - 1 - i][n - 1 - j] == '#' else 0
            ]
            freq = sum(vals)
            ans += min(freq, 4 - freq)
    print(ans)

    # 若不是最后一次循环，则读取翻转指令
    if t < u:
        r, c = map(int, input().split())
        r -= 1
        c -= 1
        grid[r][c] = '#' if grid[r][c] == '.' else '.'
