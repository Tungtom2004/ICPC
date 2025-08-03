#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
const int MAXT = 4 * MAXN + 5;

int max_free[MAXT], prefix_free[MAXT], suffix_free[MAXT], lazy[MAXT];

void build(int id, int l, int r) {
    lazy[id] = -1;
    if (l == r) {
        max_free[id] = prefix_free[id] = suffix_free[id] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    prefix_free[id] = suffix_free[id] = max_free[id] = r - l + 1;
}

void apply(int id, int l, int r, int val) {
    lazy[id] = val;
    if (val == 0) {
        max_free[id] = prefix_free[id] = suffix_free[id] = r - l + 1;
    } else {
        max_free[id] = prefix_free[id] = suffix_free[id] = 0;
    }
}

void push(int id, int l, int r) {
    if (lazy[id] == -1) return;
    int mid = (l + r) / 2;
    apply(id * 2, l, mid, lazy[id]);
    apply(id * 2 + 1, mid + 1, r, lazy[id]);
    lazy[id] = -1;
}

void merge(int id, int l, int r) {
    int mid = (l + r) / 2;
    int L = id * 2, R = id * 2 + 1;

    prefix_free[id] = prefix_free[L];
    if (prefix_free[L] == mid - l + 1) prefix_free[id] += prefix_free[R];

    suffix_free[id] = suffix_free[R];
    if (suffix_free[R] == r - mid) suffix_free[id] += suffix_free[L];

    max_free[id] = max({
        max_free[L],
        max_free[R],
        suffix_free[L] + prefix_free[R]
    });
}

void update(int id, int l, int r, int u, int v, int val) {
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
        apply(id, l, r, val);
        return;
    }
    push(id, l, r);
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    merge(id, l, r);
}

int query(int id, int l, int r, int k) {
    if (max_free[id] < k) return -1;
    if (l == r) return l;
    push(id, l, r);
    int mid = (l + r) / 2;
    if (max_free[id * 2] >= k) return query(id * 2, l, mid, k);
    if (suffix_free[id * 2] + prefix_free[id * 2 + 1] >= k)
        return mid - suffix_free[id * 2] + 1;
    return query(id * 2 + 1, mid + 1, r, k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    build(1, 1, N);
    int refused = 0;

    for (int i = 0; i < M; ++i) {
        string type;
        cin >> type;
        if (type == "A") {
            int k;
            cin >> k;
            int pos = query(1, 1, N, k);
            if (pos == -1 || pos + k - 1 > N) ++refused;
            else update(1, 1, N, pos, pos + k - 1, 1);
        } else {
            int a, b;
            cin >> a >> b;
            update(1, 1, N, a, b, 0);
        }
    }
    cout << refused << '\n';
    return 0;
}
