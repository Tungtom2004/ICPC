#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<vector<int>> st;

    SegTree(int n): n(n) {
        st.resize(4*n);
    }

    void build(int id, int l, int r, const vector<int> &a) {
        if (l == r) {
            st[id] = {a[l]};
            return;
        }
        int mid = (l + r) / 2;
        build(id*2, l, mid, a);
        build(id*2+1, mid+1, r, a);
        st[id].resize(st[id*2].size() + st[id*2+1].size());
        merge(st[id*2].begin(), st[id*2].end(),
              st[id*2+1].begin(), st[id*2+1].end(),
              st[id].begin());
    }

    void update(int id, int l, int r, int pos, int old_val, int new_val) {
        auto &vec = st[id];
        auto it = lower_bound(vec.begin(), vec.end(), old_val);
        vec.erase(it);
        vec.insert(lower_bound(vec.begin(), vec.end(), new_val), new_val);
        if (l == r) return;
        int mid = (l + r) / 2;
        if (pos <= mid) update(id*2, l, mid, pos, old_val, new_val);
        else update(id*2+1, mid+1, r, pos, old_val, new_val);
    }

    int query(int id, int l, int r, int ql, int qr, int x) {
        if (qr < l || r < ql) return INT_MAX;
        if (ql <= l && r <= qr) {
            auto it = upper_bound(st[id].begin(), st[id].end(), x);
            if (it == st[id].end()) return INT_MAX;
            return *it;
        }
        int mid = (l + r) / 2;
        return min(query(id*2, l, mid, ql, qr, x),
                   query(id*2+1, mid+1, r, ql, qr, x));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    SegTree seg(n);
    seg.build(1, 1, n, a);

    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, val;
            cin >> u >> val;	
            seg.update(1, 1, n, u, a[u], val);
            a[u] = val;
        } else {
            int u, v, X;
            cin >> u >> v >> X;
            int ans = seg.query(1, 1, n, u, v, X);
            if (ans == INT_MAX) cout << -1 << "\n";
            else cout << ans << "\n";
        }
    }
}
