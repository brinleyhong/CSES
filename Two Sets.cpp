#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n; cin >> n;
    ll sum = (ll) n * (n+1LL);
    sum = (ll) sum / 2LL;
    if (sum % 2 == 1)
    {
        cout << "NO\n";
        return;
    }
    if (n%2==0)
    {
        cout << "YES\n";
        cout << n/2 << "\n";
        for (int i = 1; i<=n/2; i+=2)
            cout << i << " " << n-i+1 << " ";
        cout << "\n" << n/2 << "\n";
        for (int i = 2; i<=n/2; i+=2)
            cout << i << " " << n-i+1 << " ";

        return;
    }
    cout << "YES\n";
    cout << (n+1)/2 << "\n";
    for (int i = 1; i<=(n-1)/2; i+=2)
    {
        cout << i << " " << n-i << " ";
    }
    cout << "\n";
    cout << (n-1)/2 << "\n";
    for (int i = 2; i<=(n-1)/2; i+=2)
        cout << i << " " << n-i << " ";
    cout << n;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
