MAX = 30

def find_num_string(X, Y , dp):
    for i in range(MAX):
        for j in range(MAX):
            dp[i][j] = 0
    
    dp[0][0] = 1

    for i in range(X+1):
        for j in range(Y+1):
            if i > 0:
                dp[i][j] += dp[i - 1][j]
            if j > 0:
                dp[i][j] += dp[i][j-1]

def kth_string(X, Y, K, dp):
    while X > 0 and Y > 0:

        if K <= dp[X-1][Y]:
            print('a', end = '')
            X -= 1

        else:
            K -= dp[X-1][Y]
            print('b', end = '')
            Y -= 1

    print('a'*X, end = '')
    print('b'*Y)

def kth_string_util(X, Y, K):
    dp = [[0 for j in range(MAX)] for i in range(MAX)]

    find_num_string(X,Y,dp)

    kth_string(X,Y,K, dp)

if __name__ == '__main__':
    s = input().split()

    A = int(s[0])
    B = int(s[1])
    K = int(s[2])
    kth_string_util(A,B,K)       
    