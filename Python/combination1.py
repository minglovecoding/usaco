class solution:
    def combine(self,n,k):
        res=[]
        path=[]
        def back_tracking(n,k,index):
            if len(path)==k:
                res.append(path[:])
                return
            for i in range(index,n-(k-len(path))+2):
                path.append(i)
                back_tracking(n,k,i+1)
                path.pop()
        back_tracking(n,k,1)
        print(res)
        return res
a=solution()
a.combine(4,3)
