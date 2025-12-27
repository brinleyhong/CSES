#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    vector <queue<int>> v;
    queue <int> s;
    s.push(0);
    v.push_back(s);
    s.pop();
    s.push(1);
    v.push_back(s);
    for (int i = 2; i<=n; ++i)
    {
        int sz = v.size();
        for (int j = sz-1; j>=0; --j) v.push_back(v[j]);
        for (int j = 0; j<sz; ++j) v[j].push(0);
        for (int j = sz; j < sz*2; ++j) v[j].push(1);
    }
    for (int i = 0; i<v.size(); ++i)
    {
        while (!v[i].empty())
        {
            cout << v[i].front();
            v[i].pop();
        }
        cout << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
