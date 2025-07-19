def solve():
    n, m = map(int, input().split())
    x=list()
    for i in range(n):
        a,b,c = map(int, input().strip().split())
        x.append((a,b,c))
    x.sort(key = lambda t: t[2])   #根据元组的2号元素排序（编号从0开始）
    for i in range(1, n):
        dx = x[i][0] - x[i-1][0]
        dy = x[i][1] - x[i-1][1]
        dt = x[i][2] - x[i-1][2]
        if dx*dx + dy*dy > dt*dt:
            print(m)
            return
    cnt = 0
    for _ in range(m):
        xx, y, t = map(int, input().split())
        i = 0
        j = n - 1
        while i <= j:            #通过二分查找找到第一个大于(xx,y,t)的元组，这里只需要比较t和x数组中各元素的第2个元素
            mid = (i + j) // 2
            if x[mid][2] < t:
                i = mid + 1
            else:
                j = mid - 1
        flag = False
        if i < n:
            dx = x[i][0] - xx
            dy = x[i][1] - y
            dt = x[i][2] - t
            if dx*dx + dy*dy > dt*dt:
                flag = True
        if i > 0:
            dx = x[i-1][0] - xx
            dy = x[i-1][1] - y
            dt = x[i-1][2] - t
            if dx*dx + dy*dy > dt*dt:
                flag = True
        cnt += flag
    print(cnt)

if __name__ == '__main__':
    T = 1
    for _ in range(T):
        solve()
