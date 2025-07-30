class cheese_block:
    def __init__(self,n):
        self.n=n 
        self.res=0
        self.xy=[[n]*n for _ in range(n)]
        self.xz=[[n]*n for _ in range(n)]
        self.yz=[[n]*n for _ in range(n)]
    def carve(self,x,y,z):
        self.xy[x][y]-=1
        self.xz[x][z]-=1
        self.yz[y][z]-=1
        self.res+=(self.xy[x][y]==0)+(self.xz[x][z]==0)+(self.yz[y][z]==0)

    def ans(self):
        return self.res

N,Q=map(int,input().split())
cb=cheese_block(N)
for _ in range(Q):
    x,y,z=map(int,input().split())
    cb.carve(x,y,z)
    print(cb.ans())