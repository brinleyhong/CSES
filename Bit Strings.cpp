#include <bits/stdc++.h>
using namespace std;
const int mod =1e9 + 7;
void solve()
{
    int n; cin >> n;
    int ans = 1;
    for (int i = 1; i<=n; ++i)
    {
        ans = ((ans%mod) * (2%mod))%mod;
    }
    cout << ans%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
