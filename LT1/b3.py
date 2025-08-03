s = input()
l,r = 0,len(s)-1
res = -1
while l <= r:
    if s[l] == 'A' and s[r] == 'Z':
        res = max(res,r-l+1)
        l+=1
        r-=1 
    else:
        if s[l] != 'A':
            l += 1
        if s[r] != 'Z':
            r -= 1
print(res)