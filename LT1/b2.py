mod = 10**9 + 7
s = input()
k = int(input())
tmp = []
for i in range(k):
    t = input()
    tmp.append(t)
n = len(s)
dp = [0]*(n+1)
dp[0] = 1

word_set = set(tmp)
max_len = max(len(t) for t in tmp)

for i in range(1,n+1):
    for l in range(1,max_len+1):
        if i - l >= 0:
            if s[i-l:i] in word_set:    
                dp[i]=(dp[i] + dp[i-l]) % mod
print(dp[n] % mod)