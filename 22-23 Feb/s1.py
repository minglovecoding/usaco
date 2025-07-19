def find_bottom_c(i, ans):
    ans_l = 0
    ans_r = min(c_time - 1, ans)
    sum_val = a[i]*c_time + b[i]*m_time
    while ans_l <= ans_r:
        ans_m = (ans_l + ans_r) // 2
        if sum_val - ans_m * a[i] - min(ans - ans_m, m_time - 1) * b[i] - c[i] <= 0:
            ans_r = ans_m - 1
        else:
            ans_l = ans_m + 1
    return ans_l

def find_bottom_m(i, ans):
    ans_l = 0
    ans_r = min(m_time - 1, ans)
    sum_val = a[i]*c_time + b[i]*m_time
    while ans_l <= ans_r:
        ans_m = (ans_l + ans_r) // 2
        if sum_val - ans_m * b[i] - min(ans - ans_m, c_time - 1) * a[i] - c[i] <= 0:
            ans_r = ans_m - 1
        else:
            ans_l = ans_m + 1
    return ans_l

def check(ans):
    bottom_c = 0
    bottom_m = 0
    for i in range(n):
        if a[i] >= b[i]:
            bottom_c = max(bottom_c, find_bottom_c(i, ans))
        if b[i] >= a[i]:
            bottom_m = max(bottom_m, find_bottom_m(i, ans))
    if bottom_c > ans or bottom_c > c_time - 1:
        return False
    if bottom_m > ans or bottom_m > m_time - 1:
        return False
    return bottom_c + bottom_m <= ans

def solve():
    ans_l = 0
    ans_r = c_time + m_time - 2
    while ans_l <= ans_r:
        ans_m = (ans_l + ans_r) // 2
        if check(ans_m):
            ans_r = ans_m - 1
        else:
            ans_l = ans_m + 1
    return ans_l

if __name__=='__main__':
    T = int(input())
    for _ in range(T):
        temp = str()
        while len(temp)==0:
            temp = input().strip()
        temp = temp.split()
        n, c_time, m_time = [int(k) for k in temp]
        a = [0]*n
        b = [0]*n
        c = [0]*n
        i = 0
        while i < n:
            temp = input().strip()
            if len(temp) == 0:
                continue
            else:
                temp = temp.split()
                a[i], b[i], c[i] = [int(k) for k in temp]
                i += 1
        print(solve())
