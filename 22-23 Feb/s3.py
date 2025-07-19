def dfs(pos,t,res,a,G,idx):
    if (res[pos]!=-1 and t>=res[pos]): return
    res[pos]=t
    t+=a[pos]
    while(idx[pos]!=-1 and G[pos][idx[pos]][0]>=t):
        c = G[pos][idx[pos]][1]
        d = G[pos][idx[pos]][2]
        idx[pos]-=1
        dfs(c,d,res,a,G,idx)

def solve():
    n,m=map(int,input().split())
    G = [ [] for _ in range(n+1)]
    for _ in range(m):
        a,b,c,d = map(int,input().split())
        G[a].append([b,c,d])
    
    idx=[0]
    for i in range(n):
        G[i+1].sort()
        idx.append(len(G[i+1])-1)
    
    res = [-1] * (n+1)
    a = [0] + list(map(int,input().split()))
    a[1] = 0
    dfs(1,0,res,a,G,idx)
    for i in range(n):
        print(res[i+1])

if __name__ == '__main__':
    solve()