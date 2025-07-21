def diff(N):
    #找出N有多少个digits
    digits=0
    res=0
    while 10**digits<N:
        digits+=1
    #4999-4444
    for digit in range(1,digits+1):
        upper=int('5'+'0'*(digit-1))-1
        upper=min(N,upper)
        lower=int('4'*digit)
        res+=max(0,upper-lower)
    return res

T=int(input().strip())
for _ in range(T):
    N=int(input().strip())
    print(diff(N))


