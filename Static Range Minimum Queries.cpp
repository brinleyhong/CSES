#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int maxn = 2e5;
int seg[maxn*4+5], a[maxn+5], n, q;

void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    seg[id] = min(seg[id*2], seg[id*2+1]);
}

int get(int id, int l, int r, int u, int v)
{
    //l r u l r v l r
    if (r < u || v < l) return INF;
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) / 2;
    return min(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}
void solve()
{
    cin >> n >> q;
    for (int i = 1; i<=n; ++i) cin >> a[i];
    build(1, 1, n);
    while (q--)
    {
        int l, r; cin >> l >> r;
        cout << get(1, 1, n, l, r) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
