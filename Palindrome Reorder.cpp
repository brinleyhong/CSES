#include <bits/stdc++.h>
using namespace std;
const int maxn = 26;
int f[maxn+5];
void solve()
{
    string s; cin >> s;
    for (char v : s)
    {
        int t = int(v) - int('A');
        ++f[t];
    }
    int cnt_odd = 0;
    int t = -1;
    for (int i = 0; i<26; ++i)
    {
        if (f[i]%2==1) {
            ++cnt_odd;
            t = i;
        }
    }
    if (cnt_odd > 1)
    {
        cout << "NO SOLUTION\n";
        return;
    }
    deque <char> dq;
    if (t != -1)
    {
        char v = char(int('A') + t);
        for (int i = 1; i<=f[t]; ++i) dq.push_back(v);
    }
    for (int i = 0; i<26; ++i)
    {
        char v = char(int('A') + i);
        if (t == i) continue;
        for (int j = 1; j<=f[i]/2; ++j) dq.push_front(v);
        for (int j = f[i]/2+1; j <= f[i]; ++j) dq.push_back(v);
    }
    for (char c : dq) cout << c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
