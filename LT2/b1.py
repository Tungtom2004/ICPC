n = int(input())
a = list(map(int, input().split()))
x = max(a)
s = sum(a)
if x < s-x:
    print('Yes')
else:
    print('No')