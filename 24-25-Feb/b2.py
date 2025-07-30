N=int(input())
a=list(map(int,input().split()))

cnt=[0]*(N+1)
for x in a:
    cnt[x]+=1

empty=0
for i in range(N+1):
    print(max(cnt[i],empty))
    empty+=cnt[i]==0