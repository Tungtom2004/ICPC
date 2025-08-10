import sys
input = sys.stdin.readline 

n = int(input())
u = []
v = []

points = []
for i in range(n):
    x,y = map(int, input().split())
    ui = x + y 
    vi = x - y 
    u.append((ui,i))
    v.append((vi,i))
    points.append((x,y))

u.sort()
v.sort()
candidates = set()
candidates.add(u[0][1])
candidates.add(u[1][1])
candidates.add(u[-1][1])
candidates.add(u[-2][1])

candidates.add(v[0][1])
candidates.add(v[1][1])
candidates.add(v[-1][1])
candidates.add(v[-2][1])

res = float('inf')
for i in candidates:
    if u[-1][1] == i:
        maxU = u[-2][0]
    else:
        maxU = u[-1][0]
    if u[0][1] == i:
        minU = u[1][0]
    else:
        minU = u[0][0]
    if v[-1][1] == i:
        maxV = v[-2][0]
    else:
        maxV = v[-1][0]
    if v[0][1] == i:
        minV = v[1][0]
    else:
        minV = v[0][0]

    k = max(maxU - minU, maxV - minV)
    res = min(res, k)
print(res)