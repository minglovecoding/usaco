#nums=[int(x) for x in input().split()]
#输入数组
#dd=[int(x) for x in input().split()]
#print(nums[1])
#print(len(nums))
#A=[int(x) for x in input().split()]
#for i in range(len(A),0,-1):
#   print(A[i-1])

count=0
for i in range(100):
    for j in range(100):
        ii=i/2
        jj=j/2
        A=(1+2*ii)*(2+2*jj)*(2*ii+jj)
        B=32*ii*jj
        if(A==B):
            count+=1
print(count)