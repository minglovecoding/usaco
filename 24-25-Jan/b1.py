WGB={
    'W':0,
    'G':1,
    'B':2,
}
def _case():
    N,A,B=[int(x) for x in input().split()]
    map2=[[WGB[x] for x in input()] for _ in range(N)]
    map1=[[0 for _ in range(N)] for _ in range(N)]
   
    for i in range(N):
        for j in range(N):
            if map2[i][j]==2:
                map1[i][j]=1
                if i<B or j<A:
                    print(-1)
                    return 
                if map2[i-B][j-A]==0:
                    print(-1)
                    return
                map1[i-B][j-A]=1
    
    for i in range(N):
        for j in range(N):
            if map2[i][j]==1:
                if map1[i][j]==1:
                    continue
                if i<B or j<A:
                    map1[i][j]=1
                    continue
                if map1[i-B][j-A]==1:
                    continue
                map1[i][j]=1

    print(sum(sum(x) for x in map1))

T=int(input())
while T:
    T-=1
    _case()