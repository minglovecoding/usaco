from collections import defaultdict
N,F=map(int,input().split())
S=input()
moos=set()
#替换字符

def find_moos(s):
    cnt=defaultdict(int)
    for i in range(N-2):
        if s[i]!=s[i+1] and s[i+1]==s[i+2]:
            cnt[s[i:i+3]]+=1
            if cnt[s[i:i+3]]>=F:
                moos.add(s[i:i+3])

for i in range(N):
    for j in range(26):
        _S=S[:i]+chr(ord('a')+j)+S[i+1:]
        find_moos(_S)

moos=sorted(moos)
print(len(moos))
for moo in moos:
    print(moo)

