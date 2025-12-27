#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n; cin >> n;
    for (int k = 1; k<=n; ++k) {
        int v = k*k;
        int ans = (v*(v-1LL))/2LL - (4LL*(k-1LL)*(k-2LL));
        cout << ans << "\n";
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
