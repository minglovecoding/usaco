def trim_spaces(s):
    tmp=[]
    #去除前面的空格
    left,right=0,len(s)-1
    while left<=right and s[left]==' ':
        left+=1
    #去除后面的空格
    while left<=right and s[right]==' ':
        right-=1
    #去除中间的空格
    while left<=right:
        if s[left]!=' ':
            tmp.append(s[left])
        elif tmp[-1]!=' ':
            tmp.append(s[left])
        left+=1
    return tmp
    
def reverse(nums,left,right):
    while left<right:
        nums[left],nums[right]=nums[right],nums[left]
        left+=1
        right-=1
    return None
#翻转每个单词
def reverse_word(nums):
    start=0
    end=0
    while start<len(nums):
        while end<len(nums) and nums[end]!=' ':
            end+=1
        reverse(nums,start,end-1)
        start=end+1
        end+=1
    return None
def reversewords(s):
    l=trim_spaces(s)
    reverse(l,0,len(l)-1)
    reverse_word(l)
    #print(l)
    return print(''.join(l))
    
if __name__=='__main__':
    s='asda dada'
    reversewords(s)
    #print(s)
    #print(s)
