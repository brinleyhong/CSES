#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int n, t[maxn+5], x[maxn+5], p[maxn+5], ans[maxn+5], seg[maxn*4+5];

void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[id] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id*2+1, mid+1, r);
    seg[id] = seg[id*2] + seg[id*2+1];
}


void update(int id, int l, int r, int point)
{
    // l r u l r v l r
    if (l == r) {
        seg[id] = 0;
        return;
    }
    int mid = (l + r)/ 2;
    if (point <= mid) update(id*2, l, mid, point);
    else update(id*2+1, mid+1, r, point);
    seg[id] = seg[id*2] + seg[id*2+1];
}

int get(int id, int l, int r, int u, int v)
{
    if (r < u || v < l) return 0;
    if (u <= l && r <= v)
    {
        return seg[id];
    }
    int mid = (l + r) / 2;
    return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}
void solve()
{
    cin >> n;
    for (int i = 1; i<=n; ++i) cin >> x[i];
    for (int i = 1; i<=n; ++i) cin >> p[i];
    build(1, 1, n);
    for (int i = 1; i<=n; ++i)
    {
        int l = 1, r = n;
        int res = n;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int cur = get(1, 1, n, 1, mid);
            if (cur >= p[i])
            {
                res = mid;
                r = mid-1;
            }
            else l = mid + 1;
        }
        ans[i] = x[res];
        update(1, 1, n, res);
    }
    for (int i = 1; i<=n; ++i) cout << ans[i] << ' ';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
