#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int n, a[maxn+5];
void solve()
{
    cin >> n;
    set <int> se;
    for (int i = 1; i<=n; ++i) {
        cin >> a[i];
        se.insert(a[i]);
    }
    cout << se.size();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
