import sys
input = sys.stdin.readline
from collections import Counter

MOD = 998244353

MAXN = 200005
pow2 = [1] * (MAXN + 1)
for i in range(1, MAXN + 1):
    pow2[i] = (pow2[i-1] * 2) % MOD

def solve_case(N, K, A):
    freq = Counter(A)
    keys = sorted(freq.keys())

    if K == 0:
        total = 1
        for x in keys:
            total = (total * (1 + freq[x])) % MOD
        print((total - 1 + MOD) % MOD)
        return

    total_dp = 1 
    dp = {}      
    dp_total = {} 

    for x in keys:
        cnt = freq[x]
        all_ways = (pow2[cnt] - 1 + MOD) % MOD


        conflict_sum = dp_total.get(x - K, 0)
        valid_prev = (total_dp - conflict_sum + MOD) % MOD

        dp[x] = (valid_prev * all_ways) % MOD
        total_dp = (total_dp + dp[x]) % MOD
        dp_total[x] = total_dp

    print((total_dp - 1 + MOD) % MOD)


T = int(input())
for _ in range(T):
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    solve_case(N, K, A)


