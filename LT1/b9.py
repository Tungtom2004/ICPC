from math import*
import sys 
maxn = 1000000
prime = []
is_prime = [True] * (maxn + 1)
is_prime[0] = is_prime[1] = False
def sieve():
    is_prime[0] = is_prime[1] = 0
    for i in range(2,maxn+1):
        if is_prime[i]:
            prime.append(i)
            for j in range(i*i,maxn+1,i):
                is_prime[j] = False



sieve()
def pt(n,p):
    cnt = 0
    while n:
        n //= p
        cnt += n
    return cnt

def count_divisor(k,n):
    if k == 0 or k == n:
        return 1 
    res = 1 
    for p in prime:
        e = pt(n,p) - pt(k,p) - pt(n-k,p)
        if e > 0:
            res *= (e+1)
    return res 


for line in sys.stdin:
    if not line.strip():
        continue
    n,k = map(int,line.strip().split())
    print(count_divisor(n,k))
