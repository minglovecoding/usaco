def main():
    n = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    same=sum(1 for i in range(n) if A[i]==B[i])
    ans=[0]*(n+1)

    def expand(l,r):
        nonlocal same
        _same=same
        while l>=0 and r<n:
            _same-=(A[l]==B[l])+(A[r]==B[r])
            _same+=(A[l]==B[r])+(A[r]==B[l])
            ans[_same]+=1
            l-=1
            r+=1

        for mid in range(n):
            expand(mid,mid)
            expand(mid,mid+1)
    
    for res in ans:
        print(res)

if __name__ == "__main__":
    main()