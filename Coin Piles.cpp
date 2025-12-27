#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int a, b; cin >> a >> b;
    if ((a+b)%3!=0)
    {
        cout << "NO\n";
        return;
    }
    if (a < (a+b)/3 || b < (a+b)/3)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
