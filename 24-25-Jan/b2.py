N=int(input())
nums=[int(x) for x in input().split()]

left=[0]*(N+1)
right=[0]*(N+1)
_left=0
ans=0

for i in range(N):
    right[nums[i]]+=1

for i in range(N):
    if right[nums[i]]==2:
        ans+=_left-(left[nums[i]]>0)
    right[nums[i]]-=1
    _left+=left[nums[i]]==0
    left[nums[i]]+=1

print(ans)


