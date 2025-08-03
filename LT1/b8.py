from math import*
for i in range(int(input())):
    a,b = map(int,input().split())
    d = abs(a-b)
    if d == 0:
        print(0)
        continue
    k = int((-1 + sqrt(1 + 8 * d)) / 2)
    while True:
        s = k*(k+1)//2
        if s >= d and (s - d) % 2 == 0:
            print(k)
            break 
        k+=1 
    