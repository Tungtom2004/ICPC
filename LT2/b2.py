from collections import deque
n = int(input())
a = list(map(int, input().split()))
b = deque()
ok = False 
for i in a:
    if ok == False:
        b.append(i)
    else:
        b.appendleft(i)
    ok = not ok 
if ok == True:
    b.reverse()
print(*b)