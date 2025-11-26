#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5;
int n, a[maxn+5], q;
ll sum[maxn+5];
void solve()
{
    cin >> n >> q;
    sum[0] = 0;
    for (int i = 1; i<=n; ++i) {
        cin >> a[i];
        sum[i] = (ll) sum[i-1] + a[i];
    }

    while (q--)
    {
        int l, r; cin >> l >> r;
        cout << (ll) sum[r] - sum[l-1] << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
