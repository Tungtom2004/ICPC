#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500;
vector<int> primes;

// Sàng nguyên tố đến MAXN
void sieve() {
    vector<bool> is_prime(MAXN + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAXN; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAXN; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i <= MAXN; ++i) {
        if (is_prime[i])
            primes.push_back(i);
    }
}

// Tính số mũ của p trong n!
int count_exp(int n, int p) {
    int res = 0;
    while (n) {
        res += n / p;
        n /= p;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int n, k;
    while (cin >> n >> k) {
        if (k > n) {
            cout << 0 << '\n';
            continue;
        }
        if (k == 0 || k == n) {
            cout << 1 << '\n';
            continue;
        }

        long long result = 1;
        for (int p : primes) {
            int e = count_exp(n, p) - count_exp(k, p) - count_exp(n - k, p);
            result *= (e + 1);
        }
        cout << result << '\n';
    }

    return 0;
}
