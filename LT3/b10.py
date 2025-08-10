def solve():
    n,c = map(int,input().split())
    a = list(map(int,input().split()))

    a.sort()
    cnt = 0
    l,r = 0,n-1
    while l <= r:
        if l == r:
            cnt+=1
            break 
        if a[l] + a[r] <= c:
            l+=1
            r-=1
            cnt+=1
        else:
            r-=1
            cnt+=1

    print(cnt)
solve()
