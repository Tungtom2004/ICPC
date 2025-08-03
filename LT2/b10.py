from math import* 

def check(a):
    target = 2 * a * a
    for i in range(1, isqrt(target) + 1):
        b = i * i
        c = target - b
        if c < 0:
            continue
        j = isqrt(c)
        if j > 10**5:
            continue
        if j*j == c:
            if len(set([a,i, j])) == 3:
                return True
    return False

a = int(input())
if check(a):
    print("YES")
else:
    print("NO")
