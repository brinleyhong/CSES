#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int n, q, prexor[maxn+5];
void solve()
{
    cin >> n >> q;
    for (int i = 1; i<=n; ++i)
    {
        int x; cin >> x;
        prexor[i] = prexor[i-1] ^ x;
    }
    while (q--)
    {
        int l, r; cin >> l >> r;
        int ans = prexor[r] xor prexor[l-1];
        cout << ans << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
